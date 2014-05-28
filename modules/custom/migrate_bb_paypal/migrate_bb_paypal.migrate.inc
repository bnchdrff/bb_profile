<?php

/*
 * Implements hook_migrate_api().
 */
function migrate_bb_paypal_migrate_api() {

  /**
   * Register all the classes
   */
  $api = array(
    'api' => 2,
    'groups' => array(
      'paypal' => array(
        'title' => t('PayPal Orders'),
      ),
    ),
    'migrations' => array(
      'PayPalOrdersUsers' => array(
        'class_name' => 'PayPalOrdersUsersMigration',
        'group_name' => 'paypal',
      ),
      'PayPalOrders' => array(
        'class_name' => 'PayPalOrdersMigration',
        'group_name' => 'paypal',
      ),
      'PayPalOrdersCustomerProfilesBilling' => array(
        'class_name' => 'PayPalOrdersCustomerProfilesBillingMigration',
        'group_name' => 'paypal',
      ),
      'PayPalOrdersCustomerProfilesShipping' => array(
        'class_name' => 'PayPalOrdersCustomerProfilesShippingMigration',
        'group_name' => 'paypal',
      ),
    ),
  );

  return $api;
}
