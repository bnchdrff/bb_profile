<?php

/**
 * @file
 *   PayPal Orders migration.
 */

// Common to all PayPal csv to Drupal entity migrations.
abstract class PayPalBaseMigration extends Migration {
  // A Migration constructor takes an array of arguments as its first parameter.
  // The arguments must be passed through to the parent constructor.
  public function __construct($arguments) {
    parent::__construct($arguments);

    // using sheet1 from the "2012-2/6/2014" doc to test.
    $this->source = new MigrateSourceCSV(drupal_get_path('module', 'migrate_bb_paypal') . '/paypal_bb_test.csv', array(), array('header_rows'=>1,'embedded_newlines'=>FALSE));

    if (module_exists('path')) {
      $this->addFieldMapping('path')
           ->issueGroup(t('DNM'));
    }
  }

  public function skipRow($row) {
    // Skip bank account withdraws.
    if ($row->{'Type'} == 'Withdraw Funds to a Bank Account' || 
        $row->{'Type'} == 'Refund' || // TODO: change orders that were refunded?
        $row->{'Type'} == 'Cancelled Fee') {
      return TRUE;
    }
    return FALSE;
  }

  public function prepareRow($row) {
    $existing_user = user_load_by_mail($row->{'From Email Address'});
    if ($existing_user->uid) {
      $row->uid = $existing_user->uid;
    }

    $row->{'Country'} = _convert_country_name_to_country_code($row->{'Country'}); // TODO: make noise if this doesn't find a country.

    // Covert row date to timestamp.
    $row->{'Date'} = strtotime($row->{'Date'} . ' ' . $row->{'Time'} . ' ' . $row->{'Time Zone'});
    return $row;
  }
}

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
    $this->addFieldMapping('created', 'Date');
    $this->addFieldMapping('timezone', 'Time Zone');
    $this->addUnmigratedDestinations(array(
      'pass',
      'access',
      'login',
      'roles', // TODO:  is there a default role for customers?
      'role_names',
      'picture',
      'signature',
      'signature_format',
      'theme',
      'init',
      'data',
      'is_new', // TODO: set this to create a new user?
      'pathauto',
    ));
    $this->addUnmigratedSources(array(
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
    $row = parent::prepareRow($row);

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
    $this->dependencies = array('PayPalOrdersCustomerProfilesBilling');
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

dpm($row, 'orders prepareRow row!');
  
    return TRUE;
  }

  public function prepare($entity, stdClass $row) {
    dpm($entity, 'orders prepare entity');
    dpm($row, 'orders prepare row');
  }

}

abstract class PayPalOrdersCustomerProfilesMigration extends PayPalBaseMigration {
  public function __construct(array $arguments, $type) {
    parent::__construct($arguments);

    $this->dependencies = array('PayPalOrdersUsers');
    $this->description = t('Import PayPal Orders\' Customer Profile - ' . $type . ' from CSV.');
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
      MigrateDestinationEntityAPI::getKeySchema('commerce_customer_profile', $type)
    );
    $this->destination = new MigrateDestinationEntityAPI('commerce_customer_profile', $type);

    $this->addFieldMapping('uid', 'Transaction ID')->sourceMigration('PayPalOrdersUsers')->description(t('The assignment of customer profile address for orders.'));
    $this->addFieldMapping('type', null)->defaultValue($type);
    $this->addFieldMapping('user', null); // username?

    $this->addFieldMapping('status', null)->defaultValue('1');
    $this->addFieldMapping('created', 'Date');
    $this->addFieldMapping('commerce_customer_address:administrative_area', 'State/Province/Region/County/Territory/Prefecture/Republic');
    $this->addFieldMapping('commerce_customer_address:locality', 'Town/City');
    $this->addFieldMapping('commerce_customer_address:postal_code', 'Zip/Postal Code');
    $this->addFieldMapping('commerce_customer_address:thoroughfare', 'Address Line 1');
    $this->addFieldMapping('commerce_customer_address:premise', 'Address Line 2/District/Neighborhood');
    $this->addFieldMapping('commerce_customer_address:name_line', 'Name'); // full name?
    $this->addUnmigratedDestinations(array(
      'changed',
      'commerce_customer_address', // prepare() handles this jazz.
      'commerce_customer_address:sub_administrative_area',
      'commerce_customer_address:dependent_locality',
      'commerce_customer_address:sub_premise',
      'commerce_customer_address:organisation_name',
      'commerce_customer_address:last_name',
      'commerce_customer_address:first_name',
      'commerce_customer_address:data',
    ));
    $this->addUnmigratedSources(array(
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

  public function prepareRow($row) {
    // TODO: try to find an existing customer profile based on the address??
    $row = parent::prepareRow($row);
  }
  public function prepare($profile, stdClass $row) {
    // Adapted from: http://cgit.drupalcode.org/commerce_migrate_ubercart/tree/customer_billing_profile.inc#n79
    $profile->commerce_customer_address[LANGUAGE_NONE][0] = array(
      'xnl' => '<NameDetails PartyType="Person"><NameLine>' . $row->{'Name'} . '</NameLine></NameDetails>',
      'name_line' => $row->{'Name'},
      'administrative_area' => $row->{'State/Province/Region/County/Territory/Prefecture/Republic'},
      'country' => !empty($row->{'Country'}) ? $row->{'Country'} : 'US',
      'thoroughfare' => $row->{'Address Line 1'},
      'locality' => $row->{'Town/City'},
      'postal_code' => $row->{'Zip/Postal Code'},
    );
  }
}

class PayPalOrdersCustomerProfilesBillingMigration extends PayPalOrdersCustomerProfilesMigration {
  public function __construct(array $arguments) {
    parent::__construct($arguments, 'billing');
  }

  public function prepareRow($row) {
    if ($this->skipRow($row)) {
      return FALSE;
    }

    $row = parent::prepareRow($row);
  }
  public function prepare($profile, stdClass $row) {
    $profile = parent::prepare($profile, $row);
  }
}

class PayPalOrdersCustomerProfilesShippingMigration extends PayPalOrdersCustomerProfilesMigration {
  public function __construct(array $arguments) {
    parent::__construct($arguments, 'shipping');
  }

  public function prepareRow($row) {
    if ($this->skipRow($row)) {
      return FALSE;
    }

    $row = parent::prepareRow($row);
  }
  public function prepare($profile, stdClass $row) {
    $profile = parent::prepare($profile, $row);
  }
}


/**
 * Convert country name to ISO country code
 * source: http://dropbucket.org/node/233
 *
 * @param $country - country name. Can be of any case
 */
function _convert_country_name_to_country_code($country) {
  // Necessary for country_get_list().
  require_once DRUPAL_ROOT . '/includes/locale.inc';
  $countries = country_get_list();
  return array_search(strtolower($country), array_map('strtolower', $countries));
}

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
          'length' => 20,
          'not null' => TRUE,
          'description' => 'PayPal Transaction ID',
        ),
      ),
      MigrateDestinationEntityAPI::getKeySchema('commerce_line_item', $type)
    );
    $this->destination = new MigrateDestinationEntityAPI('commerce_line_item', $type);

    $this->addFieldMapping('order_id', 'Transaction ID')->sourceMigration('PayPalOrders')->description(t('the orders\' line items migration follows the order  migration.')); // based on the order users migration
    $this->addFieldMapping('owner', 'owner_name');
    $this->addFieldMapping('order_number', null);
    $this->addFieldMapping('created', 'Date');
  }
}

class PayPalOrdersLineItemsProductsMigration extends PayPalOrdersLineItemsMigration {
  public function __construct(array $arguments) {
    $type = 'product';
    parent::__construct($arguments, $type);

    $this->addFieldMapping('quantity', 'quantity'); // Need to preprocess this field to get total.
    $this->addFieldMapping('commerce_total', 'Net');
    $this->addFieldMapping('commerce_product', null)->defaultValue(3);
    $this->addFieldMapping('line_item_label', null)->defaultValue('beardbalm-single');
    $this->addFieldMapping('type', null)->defaultValue($type);
    $this->addFieldMapping('commerce_unit_price', null)->defaultValue(16);
    $this->addUnmigratedDestinations(array(
      'changed',
      'order', // this is handled in the complete?
      'commerce_unit_price:currency_code',
      'commerce_unit_price:tax_rate',
      'commerce_total:currency_code',
      'commerce_total:tax_rate',
      'commerce_display_path',
      'commerce_display_path:language',
    ));
    $this->addUnmigratedSources(array(
      'Balance',
      'Time',
      'Time Zone',
      'Counterparty Status',
      'Item Title',
      'Type',
      'Name',
      'Fee',
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

  function prepareRow($row) {
    if ($this->skipRow($row)) {
      return FALSE;
    }

    $row = parent::prepareRow($row);
    $row->quantity = _calculateQuantityFromGross($row->{'Gross'}, $row->{'Shipping and Handling Amount'});
  }

  function prepare($line_item, stdClass $row) {

    // The destination line item type is product
    $line_item->type = 'product';

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

function _calculateQuantityFromGross($gross, $shippingAmount) {
  return ($gross - $shippingAmount) / 16;
}
