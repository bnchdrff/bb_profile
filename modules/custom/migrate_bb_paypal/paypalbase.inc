<?php

// Common to all PayPal csv to Drupal entity migrations.
abstract class PayPalBaseMigration extends Migration {
  // A Migration constructor takes an array of arguments as its first parameter.
  // The arguments must be passed through to the parent constructor.
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    // using sheet1 from the "2012-2/6/2014" doc to test.
    $this->source = new MigrateSourceCSV(drupal_get_path('module', 'migrate_bb_paypal') . '/paypal_bb_test.full.csv', array(), array('header_rows'=>1,'embedded_newlines'=>FALSE));

    if (module_exists('path')) {
      $this->addFieldMapping('path')
           ->issueGroup(t('DNM'));
    }
  }

  public function skipRow($row) {
    // Skip any non 'Complete' transactions.
    if ($row->{'Status'} != 'Completed') {
      return TRUE;
    }
    // Skip bank account withdraws, refunds and others.
    if ($row->{'Type'} == 'Withdraw Funds to a Bank Account' ||
        $row->{'Type'} == 'Refund' || // TODO: change orders that were refunded? No.
        $row->{'Type'} == 'Invoice Sent' || // has corresponding "Payment Received" row.
        $row->{'Type'} == 'Cancelled Fee') {
      return TRUE;
    }
    return FALSE;
  }

  public function prepareRow($row) {
    if ($this->skipRow($row)) {
      return FALSE;
    }
    $existing_user = user_load_by_mail($row->{'From Email Address'});
    if ($existing_user->uid) {
      $row->uid = $existing_user->uid;
    }

    $row->{'Country'} = _convert_country_name_to_country_code($row->{'Country'}); // TODO: make noise if this doesn't find a country.

    $row->{'Name'} = check_plain($row->{'Name'});

    // Covert row date to timestamp.
    $row->{'Date'} = strtotime($row->{'Date'} . ' ' . $row->{'Time'} . ' ' . $row->{'Time Zone'});
    return $row;
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


