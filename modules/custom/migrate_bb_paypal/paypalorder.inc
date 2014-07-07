<?php

class PayPalOrdersMigration extends PayPalBaseMigration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    $this->description = t('Import PayPal Orders from CSV.');
    $this->dependencies = array('PayPalOrdersCustomerProfilesBilling');
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
      MigrateDestinationEntityAPI::getKeySchema('commerce_order', 'commerce_order')
    );
    $this->destination = new MigrateDestinationEntityAPI('commerce_order', 'commerce_order');

    $this->addFieldMapping('uid', 'Transaction ID')->sourceMigration('PayPalOrdersUsers')->description(t('the orders migration follows the order users migration.')); // based on the order users migration
    $this->addFieldMapping('owner', 'owner_name');
    $this->addFieldMapping('field_paypal_transaction_id', 'Transaction ID');
    $this->addFieldMapping('order_number', null);

    $this->addFieldMapping('commerce_customer_billing', 'Transaction ID')->sourceMigration('PayPalOrdersCustomerProfilesBilling')->description(t('This customer profile is associated with this order.'));
    $this->addFieldMapping('commerce_customer_shipping', 'Transaction ID')->sourceMigration('PayPalOrdersCustomerProfilesShipping')->description(t('This customer profile is associated with this order.'));

    $this->addFieldMapping('status', 'Status');
    $this->addFieldMapping('created', 'Date');
    $this->addFieldMapping('field_shipped_date', 'Date');
    $this->addFieldMapping('field_shipped_date:timezone', 'Time Zone');
    $this->addFieldMapping('mail', 'From Email Address');
    $this->addFieldMapping('commerce_order_total', 'Gross');
    $this->addFieldMapping('commerce_order_total:currency_code', null)->defaultValue('USD'); // TODO: different currency code?
    $this->addFieldMapping('type', null)->defaultValue('commerce_order');
    $this->addUnmigratedDestinations(array(
      'changed',
      'hostname',
      'commerce_discounts',
      'commerce_line_items', // This is handled in the LineItems' migration's complete function.
      'field_special_instructions',
      'field_special_instructions:language',
      'field_paypal_transaction_id:language',
      'field_gift_order',
      'field_total_orders',
      'field_shipped_date:rrule',
      'field_shipped_date:to',
      'field_customs_id',
      'field_customs_id:language',
      'field_amazon_transaction_id',
      'field_amazon_transaction_id:language',
      'commerce_order_total:tax_rate', // TODO: is there a default for this?
    ));
    $this->addUnmigratedSources(array(
      'Balance',
      'Time',
      'Counterparty Status',
      'Item Title',
      'Type',
      'Name',
      'Fee',
      'Net',
      'Address Status',
      'Shipping and Handling Amount',
      'Receipt ID',
      'Address Line 1',
      'Address Line 2/District/Neighborhood',
      'Town/City',
      'State/Province/Region/County/Territory/Prefecture/Republic',
      'Zip/Postal Code',
      'Country',
    ));
  }

  /**
   * Review a data row after fetch, returning FALSE to skip it.
   *
   * @param $row
   * @return bool
   */
  public function prepareRow($row) {
    if ($this->skipRow($row)) {
      return FALSE;
    }
    $row = parent::prepareRow($row);

    if ($row->{'Status'} == 'Completed') 
      $row->{'Status'} = strtolower($row->{'Status'});

    return TRUE;
  }

  public function prepare($entity, stdClass $row) {
  }
}
