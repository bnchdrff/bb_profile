<?php

// Common to all PayPal csv to Drupal entity migrations.
abstract class PayPalBaseMigration extends Migration {
  // A Migration constructor takes an array of arguments as its first parameter.
  // The arguments must be passed through to the parent constructor.
  public function __construct($arguments) {
    parent::__construct($arguments);

    // using sheet1 from the "2012-2/6/2014" doc to test.
    $this->source = new MigrateSourceCSV(drupal_get_path('module', 'migrate_bb_paypal') . '/paypal_bb_test.csv', array(), array('header_rows'=>1,'embedded_newlines'=>FALSE));
  }

  public function skipRow($row) {
    // Skip bank account withdraws.
    if ($row->{'Type'} == 'Withdraw Funds to a Bank Account') {
      return TRUE;
    }
    return FALSE;
  }
}

/**
 * @file
 *   PayPal Orders migration.
 */

class PayPalOrdersUsersMigration extends PayPalBaseMigration {
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
    $this->destination = new MigrateDestinationUser();

    $this->addFieldMapping('mail', 'From Email Address');
    $this->addFieldMapping('uid', 'uid');
    $this->addFieldMapping('name', 'Name'); // TODO: avoid duplicate/existing names? 
    $this->addFieldMapping('status', null)->defaultValue('1');
    $this->addFieldMapping('language', null)->defaultValue('en');
    $this->addFieldMapping('created', 'Date'); // use full date & time & tz
    $this->addFieldMapping('timezone', 'Time Zone'); // use full date & time & tz
    $this->addUnmigratedDestinations(array(
      'pass',
      'access',
      'login',
      'roles', // is there a default role for customers?
      'role_names',
      'picture',
      'signature',
      'signature_format',
      'theme',
      'init',
      'data',
      'is_new', // create a new user?
      'path',
      'pathauto',
    ));
    $this->addUnmigratedSources(array(
      'Date',
      'Time',
      'Status',
      'Gross',
      'Fee',
      'Net',
      'Address Status',
      'Item Title',
      'Shipping and Handling Amount',
      'Receipt ID',
      'Balance',
      'Address Line 1',
      'Address Line 2/District/Neighborhood',
      'Town/City',
      'State/Province/Region/County/Territory/Prefecture/Republic',
      'Zip/Postal Code',
      'Country',
      'Counterparty Status',
      'Item Title',
      'Type',
    ));
  }

  /**
   * Review a data row after fetch, returning FALSE to skip it.
   * Code adapted from: http://cgit.drupalcode.org/migrate_d2d/tree/user.inc
   *
   * @param $row
   * @return bool
   */
  public function prepareRow($row) {
    if ($this->skipRow($row)) {
      return FALSE;
    }

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


class PayPalOrdersMigration extends PayPalBaseMigration {
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
    if ($this->skipRow($row)) {
      return FALSE;
    }

dpm($row, 'orders prepareRow row!');
  
    return TRUE;
  }

  public function prepare($entity, stdClass $row) {
    dpm($entity, 'orders prepare entity');
    dpm($row, 'orders prepare row');
  }

}

class PayPalOrdersCustomerProfilesBillingMigration extends PayPalBaseMigration {
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
    $this->destination = new MigrateDestinationEntityAPI('commerce_customer_profile', 'billing');
    $this->addFieldMapping('uid', 'Transaction ID')->sourceMigration('PayPalOrdersUsers')->description(t('The assignment of customer profile address for orders.'));;
    $this->addFieldMapping('type', null)->defaultValue('billing');
    $this->addFieldMapping('user', null); // username?

    $this->addFieldMapping('status', null)->defaultValue('1');
    $this->addFieldMapping('created', 'Date'); // use full date & time & tz
    $this->addFieldMapping('commerce_customer_address:administrative_area', 'State/Province/Region/County/Territory/Prefecture/Republic');
    $this->addFieldMapping('commerce_customer_address:locality', 'Town/City');
    $this->addFieldMapping('commerce_customer_address:postal_code', 'Zip/Postal Code');
    $this->addFieldMapping('commerce_customer_address:thoroughfare', 'Address Line 1');
    $this->addFieldMapping('commerce_customer_address:premise', 'Address Line 2/District/Neighborhood');
    $this->addFieldMapping('commerce_customer_address:name_line', 'Name'); // full name?
    $this->addUnmigratedDestinations(array(
      'changed',
      'commerce_customer_address', // need this or just it's parts?
      'commerce_customer_address:sub_administrative_area',
      'commerce_customer_address:dependent_locality',
      'commerce_customer_address:sub_premise',
      'commerce_customer_address:organisation_name',
      'commerce_customer_address:last_name',
      'commerce_customer_address:first_name',
      'commerce_customer_address:data',
      'path',
    ));
    $this->addUnmigratedSources(array(
      'Date',
      'Time',
      'Time Zone',
      'Status',
      'Gross',
      'Fee',
      'Net',
      'From Email Address',
      'Address Status',
      'Item Title',
      'Shipping and Handling Amount',
      'Receipt ID',
      'Transaction ID (PK)',
      'Balance',
      'Country',
      'Counterparty Status',
      'Item Title',
      'Type',
    ));
  }
  public function prepare($profile, stdClass $row) {
    if ($this->skipRow($row)) {
      return FALSE;
    }
    dpm(get_defined_vars(), 'profile prepare');
  }
}
