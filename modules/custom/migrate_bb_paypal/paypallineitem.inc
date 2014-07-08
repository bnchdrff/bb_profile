<?php

abstract class PayPalOrdersLineItemsMigration extends PayPalBaseMigration {
  public function __construct(array $arguments, $type) {
    parent::__construct($arguments);

    $this->description = t('Import PayPal Orders\'' . $type . ' line items from CSV.');
    $this->dependencies = array('PayPalOrders');
    // Create a map object for tracking the relationships between source rows
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'Transaction ID' => array(
          'type' => 'varchar',
          'length' => 30,
          'not null' => TRUE,
          'description' => 'PayPal Transaction ID',
        ),
      ),
      MigrateDestinationEntityAPI::getKeySchema('commerce_line_item', $type)
    );
    $this->destination = new MigrateDestinationEntityAPI('commerce_line_item', $type);

    $this->addFieldMapping('order_id', 'Transaction ID')->sourceMigration('PayPalOrders')->description(t('the orders\' line items migration follows the order  migration.')); // based on the order users migration
    $this->addFieldMapping('type', null)->defaultValue($type);
    $this->addFieldMapping('created', 'Date');
    $this->addUnmigratedDestinations(array(
      'order', // this is handled in the complete
      'commerce_unit_price:currency_code',
      'commerce_unit_price:tax_rate',
      'commerce_total:currency_code',
      'commerce_total:tax_rate',
      'commerce_display_path',
      'commerce_display_path:language',
    ));
    $this->addUnmigratedSources(array(
      'Status',
      'Gross',
      'From Email Address',
      'Balance',
      'Time',
      'Time Zone',
      'Counterparty Status',
      'Item Title',
      'Type',
      'Name',
      'Fee',
      'Address Status',
      'Receipt ID',
      'Address Line 1',
      'Address Line 2/District/Neighborhood',
      'Town/City',
      'State/Province/Region/County/Territory/Prefecture/Republic',
      'Zip/Postal Code',
      'Country',
    ));
  }

  public function prepareRow($row) {
    $row = parent::prepareRow($row);
  }

  function prepare($line_item, stdClass $row) {
    // Add a base price component.
    $line_item_wrapper = entity_metadata_wrapper('commerce_line_item', $line_item);

    $price = $line_item_wrapper->commerce_unit_price;
    $base_price = array(
      'amount' => $price->amount->value(),
      'currency_code' => $price->currency_code->value(),
      'data' => array(),
    );
    $line_item_wrapper->commerce_unit_price->data = commerce_price_component_add($base_price, 'base_price', $base_price, TRUE);

    // The destination mapping schema has two primary keys when revisioning is
    // enabled (order_id and revision_id). When the field mapping looks up the
    // source migration to match the order_id, it gets both the destid1 and
    // destid2 from the mapping table. We need to pick one here or every
    // order_id ends up as 1
    if (is_array($line_item->order_id) && isset($line_item->order_id['destid1'])) {
      $line_item->order_id = $line_item->order_id['destid1'];
    }
  }

  /**
   * A line item has been saved. Reference it from the order.
   */
  function complete($line_item, stdClass $row) {
    // We need to do a full order save here so that commerce recalculates
    // the total with our price components
    $order = commerce_order_load($line_item->order_id);
    $order_wrapper = entity_metadata_wrapper('commerce_order', $order);
    $order_wrapper->commerce_line_items[] = $line_item;
    $order_wrapper->save();
  }

  /**
   * The line item has been deleted, delete its references.
   */
  function completeRollback($line_item_id) {
    db_delete('field_data_commerce_line_items')
      ->condition('commerce_line_items_line_item_id', $line_item_id)
      ->execute();
  }
}

class PayPalOrdersLineItemsProductsMigration extends PayPalOrdersLineItemsMigration {
  public function __construct(array $arguments) {
    $type = 'product';
    parent::__construct($arguments, $type);

    $this->addFieldMapping('quantity', 'quantity'); // Calculated in prepareRow().
    $this->addFieldMapping('commerce_total', 'Net');
    $this->addFieldMapping('commerce_product', null)->defaultValue(3);
    $this->addFieldMapping('line_item_label', null)->defaultValue('beardbalm-single');
    $this->addFieldMapping('commerce_unit_price', null)->defaultValue(16);
    $this->addUnmigratedSources(array(
      'Shipping and Handling Amount',
    ));
  }

  function prepareRow($row) {
    if ($this->skipRow($row)) {
      return FALSE;
    }

    $row->quantity = _calculateQuantityFromGross($row->{'Gross'}, $row->{'Shipping and Handling Amount'});
    $row = parent::prepareRow($row);
  }
}

function _calculateQuantityFromGross($gross, $shippingAmount) {
  return ($gross - $shippingAmount) / 16;
}

class PayPalOrdersLineItemsShippingMigration extends PayPalOrdersLineItemsMigration {
  public function __construct(array $arguments) {
    $type = 'shipping';
    parent::__construct($arguments, $type);

    $this->addFieldMapping('quantity', null)->defaultValue(1);
    $this->addFieldMapping('commerce_total', 'Shipping and Handling Amount');
    $this->addFieldMapping('commerce_product', null)->defaultValue(3);
    $this->addFieldMapping('commerce_unit_price', 'Shipping and Handling Amount');
    $this->addUnmigratedDestinations(array('line_item_label'));
  }

  function prepareRow($row) {
    if ($this->skipRow($row)) {
      return FALSE;
    }

    $row = parent::prepareRow($row);
  }

  function prepare($line_item, stdClass $row) {
    $price_component_type = 'flat_rate_expedited_us';
    $service = 'expedited_us';
    if ($row->{'Country'} != 'US') {
      $price_component_type = 'flat_rate_expedited_intl';
      $service = 'expedited_intl';
    }
    $line_item->data['shipping_service'] = commerce_shipping_service_load($service);
    if (is_array($line_item->order_id) && isset($line_item->order_id['destid1'])) {
      $line_item->order_id = $line_item->order_id['destid1'];
    }
    $line_item_wrapper = entity_metadata_wrapper('commerce_line_item', $line_item);
    $line_item_wrapper->commerce_shipping_service = $service;
    // Add the price component.
    $price = $line_item_wrapper->commerce_unit_price;
    $base_price = array(
      'amount' => $price->amount->value(),
      'currency_code' => $price->currency_code->value(),
      'data' => array(),
    );
    $line_item_wrapper->commerce_unit_price->data = commerce_price_component_add($base_price, $price_component_type, $base_price, FALSE, FALSE);

  }
}
