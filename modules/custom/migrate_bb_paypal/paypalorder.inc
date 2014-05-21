<?php

/**
 * @file
 *   PayPal Orders migration.
 */

class PayPalOrdersUsersMigration extends Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    $this->description = t('Import PayPal Orders\' Users from CSV.');
    // Create a map object for tracking the relationships between source rows
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'Transaction ID' => array(
          'type' => 'varchar',
          'length' => 20,
          'not null' => TRUE,
          'description' => 'PayPal Transaction ID',
        ),
      ),
      MigrateDestinationUser::getKeySchema()
    );
    // using sheet1 from the "2012-2/6/2014" doc to test.
    $this->source = new MigrateSourceCSV(drupal_get_path('module', 'migrate_bb_paypal') . '/paypal_bb_test.csv', array(), array('header_rows'=>1,'embedded_newlines'=>FALSE));
    $this->destination = new MigrateDestinationUser();

    $this->addFieldMapping('mail', 'From Email Address');
    $this->addFieldMapping('uid', 'uid');
    $this->addFieldMapping('name', 'Name');
/*
    $this->addFieldMapping('order_number', null);
    $this->addFieldMapping('status', 'Status'); // Need to convert these values?
    $this->addFieldMapping('created', 'Date'); // use full date & time & tz
    $this->addFieldMapping('field_shipped_date', 'Date'); // use full date & time & tz
    $this->addFieldMapping('field_shipped_date:timezone', 'Time Zone'); // use full date & time & tz
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
  */
  }

  /**
   * Review a data row after fetch, returning FALSE to skip it.
   * Code adapted from: http://cgit.drupalcode.org/migrate_d2d/tree/user.inc
   *
   * @param $row
   * @return bool
   */
  public function prepareRow($row) {

    // On initial import, if this email address already exists, just map to the
    // existing uid and don't allow it to be deleted. When updating, we can
    // take the existing uid from the map instead of querying for it. Make sure
    // when updating an imported user that we don't apply this logic.

    if (empty($row->migrate_map_destid1)) {
      $existing_user = user_load_by_mail($row->{'From Email Address'});
      $new_uid = $existing_user->uid;
    }
    elseif ($row->migrate_map_needs_update == MigrateMap::STATUS_IGNORED &&
            $row->migrate_map_rollback_action == MigrateMap::ROLLBACK_PRESERVE) {
      $new_uid = $row->migrate_map_destid1;
    }

    //  need to do something like this to prevent deleting existing users on rollback?
    if (!empty($new_uid)) {
      $hash = isset($row->migrate_map_hash) ? $row->migrate_map_hash : NULL;
      $this->map->saveIDMapping($row, array($new_uid), MigrateMap::STATUS_IGNORED,
        MigrateMap::ROLLBACK_PRESERVE, $hash);
      $this->rollbackAction = MigrateMap::ROLLBACK_PRESERVE;
      return FALSE;
    }

    return TRUE;
  }
}


class PayPalOrdersMigration extends Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    $this->description = t('Import PayPal Orders from CSV.');
    $this->dependencies = array('PayPalOrdersUsers');
    // Create a map object for tracking the relationships between source rows
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'Transaction ID' => array(
          'type' => 'varchar',
          'length' => 20,
          'not null' => TRUE,
          'description' => 'PayPal Transaction ID',
        ),
      ),
      MigrateDestinationEntityAPI::getKeySchema('commerce_order', 'commerce_order')
    );
    // using sheet1 from the "2012-2/6/2014" doc to test.
    $this->source = new MigrateSourceCSV(drupal_get_path('module', 'migrate_bb_paypal') . '/paypal_bb_test.csv', array(), array('header_rows'=>1,'embedded_newlines'=>FALSE));
    $this->destination = new MigrateDestinationEntityAPI('commerce_order', 'commerce_order');

    $this->addFieldMapping('uid', 'Transaction ID')->sourceMigration('PayPalOrdersUsers')->description(t('The orders migration follows the order Users migration.')); // based on the order users migration
    $this->addFieldMapping('owner', 'owner_name');
    $this->addFieldMapping('field_paypal_transaction_id', 'Transaction ID');
    $this->addFieldMapping('order_number', null);
    $this->addFieldMapping('status', 'Status'); // Need to convert these values?
    $this->addFieldMapping('created', 'Date'); // use full date & time & tz
    $this->addFieldMapping('field_shipped_date', 'Date'); // use full date & time & tz
    $this->addFieldMapping('field_shipped_date:timezone', 'Time Zone'); // use full date & time & tz
    $this->addFieldMapping('mail', 'From Email Address');
    $this->addFieldMapping('commerce_order_total', 'Gross');
    $this->addFieldMapping('commerce_order_total:currency_code', null)->defaultValue('USD'); // unsure
    $this->addFieldMapping('type', null)->defaultValue('commerce_order');
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
      'field_amazon_transaction_id',
      'field_amazon_transaction_id:language',
    ));
    $this->addUnmigratedSources(array(
      'Balance',
      'Counterparty Status',
      'Item Title',
      'Type',
    ));
  }

  /**
   * Review a data row after fetch, returning FALSE to skip it.
   *
   * @param $row
   * @return bool
   */
  public function prepareRow($row) {

dpm($row, 'orders prepareRow row!');
  
    return TRUE;
  }

  public function prepare($entity, stdClass $row) {
    dpm($entity, 'orders prepare entity');
    dpm($row, 'orders prepare row');
  }

}

class PayPalOrdersCustomerProfilesBillingMigration extends Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    $this->description = t('Import PayPal Orders\' Customer Profile - billing from CSV.');
    $this->dependencies = array('PayPalOrdersUsers');
    // Create a map object for tracking the relationships between source rows
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'Transaction ID' => array(
          'type' => 'varchar',
          'length' => 20,
          'not null' => TRUE,
          'description' => 'PayPal Transaction ID',
        ),
      ),
      MigrateDestinationEntityAPI::getKeySchema('commerce_customer_profile', 'billing')
    );
    // using sheet1 from the "2012-2/6/2014" doc to test.
    $this->source = new MigrateSourceCSV(drupal_get_path('module', 'migrate_bb_paypal') . '/paypal_bb_test.csv', array(), array('header_rows'=>1,'embedded_newlines'=>FALSE));
    $this->destination = new MigrateDestinationEntityAPI('commerce_customer_profile', 'billing');
    $this->addFieldMapping('uid', 'Transaction ID')->sourceMigration('PayPalOrdersUsers')->description(t('The assignment of customer profile address for orders.'));;
    $this->addFieldMapping('commerce_customer_address:postal_code', 'Zip/Postal Code');
    $this->addFieldMapping('type', null)->defaultValue('billing');
/*
    $this->addFieldMapping('order_number', null);
    $this->addFieldMapping('status', 'Status'); // Need to convert these values?
    $this->addFieldMapping('created', 'Date'); // use full date & time & tz
    $this->addFieldMapping('field_shipped_date', 'Date'); // use full date & time & tz
    $this->addFieldMapping('field_shipped_date:timezone', 'Time Zone'); // use full date & time & tz
    $this->addFieldMapping('mail', 'From Email Address');
    $this->addFieldMapping('commerce_order_total', 'Gross');
    $this->addFieldMapping('commerce_order_total:currency_code', null)->defaultValue('USD'); // unsure
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
    */
  }
}
