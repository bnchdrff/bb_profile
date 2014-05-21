<?php

/**
 * @file
 *   PayPal Orders migration.
 */

class PayPalOrdersMigration extends Migration {
  public function __construct($arguments = array()) {
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
    // using sheet1 from the "2012-2/6/2014" doc to test.
    $this->source = new MigrateSourceCSV(drupal_get_path('module', 'migrate_bb_paypal') . '/paypal_bb_test.csv', array(), array('header_rows'=>1,'embedded_newlines'=>FALSE));
    $this->destination = new MigrateDestinationEntityAPI('commerce_order', 'commerce_order');

    $this->addFieldMapping('order_number', null);
    $this->addFieldMapping('status', 'Status'); // Need to convert these values?
    $this->addFieldMapping('created', 'Date'); // use full date & time & tz
    $this->addFieldMapping('field_shipped_date', 'Date'); // use full date & time & tz
    $this->addFieldMapping('field_shipped_date:timezone', 'Time Zone'); // use full date & time & tz
    $this->addFieldMapping('mail', 'From Email Address');
    $this->addFieldMapping('commerce_order_total', 'Gross');
    $this->addFieldMapping('commerce_order_total:currency_code', null)->defaultValue('USD'); // unsure
    $this->addFieldMapping('field_paypal_transaction_id', 'Transaction ID');
    $this->addFieldMapping('uid', null)->defaultValue(1);
    $this->addFieldMapping('type', null)->defaultValue('commerce_order');
    $this->addFieldMapping('owner', 'name')->defaultValue('admin');
    $this->addUnmigratedDestinations(array(
      'changed',
      'hostname',
      'path',
      'commerce_discounts',
      'field_special_instructions',
      'field_special_instructions:language',
      'field_paypal_transaction_id:language',
      'field_gift_order',
      'field_total_orders',
      'field_shipped_date:rrule',
      'field_shipped_date:to',
      'field_customs_id',
      'field_customs_id:language',
    ));
    $this->addUnmigratedSources(array(
      'Balance',
      'Counterparty Status',
      'Item Title',
      'Type',
    ));
  }
}
