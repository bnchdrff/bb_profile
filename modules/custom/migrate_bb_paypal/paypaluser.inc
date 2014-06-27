<?php

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
    $this->addFieldMapping('name', 'Name')->dedupe('users', 'name');
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
    // existing uid and don't allow it to be deleted.
    $existing_user = user_load_by_mail($row->{'From Email Address'});
    if ($existing_user) {
      $new_uid = $existing_user->uid;

      $hash = isset($row->migrate_map_hash) ? $row->migrate_map_hash : NULL;
      $this->map->saveIDMapping($row, array($new_uid), MigrateMap::STATUS_IGNORED,
        MigrateMap::ROLLBACK_PRESERVE, $hash);
      $this->rollbackAction = MigrateMap::ROLLBACK_PRESERVE;
      return FALSE;
    }

    return TRUE;
  }
}


