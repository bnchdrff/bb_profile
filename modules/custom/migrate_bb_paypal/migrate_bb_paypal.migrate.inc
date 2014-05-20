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
      'paypalorders' => array(
        'title' => t('PayPal Orders'),
      ),
    ),
    'migrations' => array(
      'PayPalOrders' => array(
        'class_name' => 'PayPalOrdersMigration',
        'group_name' => 'paypalorders',
      ),
    ),
  );

  return $api;
}
