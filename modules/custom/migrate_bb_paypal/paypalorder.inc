<?php

/**
 * @file
 *   PayPal Orders migration.
 */

class PayPalOrdersMigration extends Migration {
  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->description = t('Import PayPal Orders from CSV.');
    // Create a map object for tracking the relationships between source rows
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'order_id' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
          'description' => 'Order ID',
        ),
      ),
      MigrateDestinationEntityAPI::getKeySchema('commerce_order', 'commerce_order')
    );
    $this->source = new MigrateSourceCSV(drupal_get_path('module', 'migrate_bb_paypal') . '/paypal_bb_test.csv', $this->csvcols(), array('header_rows'=>1,'embedded_newlines'=>FALSE));
    $this->destination = new MigrateDestinationEntityAPI('commerce_order', 'commerce_order');

    $this->addFieldMapping('status', 'status');
  }
  protected function csvcols() {
    $cols[0] = array('date', 'Date');
    $cols[1] = array('time', 'Time');
    $cols[0] = array('timezone', 'Time Zone');
    $cols[1] = array('Name', 'Name');
    $cols[0] = array('type', 'Payment type');
    $cols[0] = array('status', 'Status');
    $cols[0] = array('gross', 'Gross');
    $cols[0] = array('fee', 'Fee');
    $cols[0] = array('net', 'Net');
    $cols[0] = array('from_email', 'From Email Address');
    $cols[0] = array('transaction_id', 'Transaction ID');
    $cols[0] = array('counterparty_status', 'Counterparty Status');
    $cols[0] = array('address_status', 'Address Status');
    $cols[0] = array('item_title', 'Item Title');
    $cols[0] = array('shipping_handling', 'Shipping and Handling Amount');
    $cols[0] = array('receipt_id', 'Receipt ID');
    $cols[0] = array('balance', 'Balance');
    $cols[0] = array('address_1', 'Address Line 1');
    $cols[0] = array('address_2', 'Address Line 2/District/Neighborhood');
    $cols[0] = array('town_city', 'Town/City');
    $cols[0] = array('state', 'State/Province/Region/County/Territory/Prefecture/Republic');
    $cols[0] = array('zip_postal_code', 'Zip/Postal Code');
    $cols[0] = array('country', 'Country');
    return $cols;
  }
}
