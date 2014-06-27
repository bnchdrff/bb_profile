<?php

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
    $this->addFieldMapping('user', null); //TODO: username?

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

