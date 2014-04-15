<?php
/**
 * @file
 * bb_customer_profiles.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function bb_customer_profiles_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'commerce_customer_address'
  $field_bases['commerce_customer_address'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(
      0 => 'commerce_customer_profile',
    ),
    'field_name' => 'commerce_customer_address',
    'foreign keys' => array(),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'addressfield',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'addressfield',
  );

  // Exported field_base: 'field_order_count'
  $field_bases['field_order_count'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_order_count',
    'foreign keys' => array(),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'computed_field',
    'settings' => array(
      'code' => '//dpm(get_defined_vars(), \'Get vars\');
$line_items_quantity = 0;
$orders = commerce_order_load_multiple(array(), array(\'uid\' => $entity->uid), TRUE);
foreach ($orders as $order) {
  if ( true) { //$order->status == \'completed\' || $order->status == \'processing\') {
     if ($order->commerce_line_items != null) {
       $line_items_ids = array();
       foreach ($order->commerce_line_items[\'und\'] as $line_item) {
         $line_items_ids[] = $line_item[\'line_item_id\'];
       }
   // dpm($line_items_ids, \'Line Items Ids\');
       $line_items = commerce_line_item_load_multiple($line_items_ids);
       $line_items_quantity += commerce_line_items_quantity($line_items, array(\'product\'));
 // dpm($line_items, \'Line Items\');
//  dpm($line_items_quantity, \'Line Items Quantity\'); 
    }
  }
}
//dpm($orders, \'Orders\');

$entity_field[0][\'value\'] = $line_items_quantity;',
      'database' => array(
        'data_default' => '',
        'data_index' => 0,
        'data_length' => 32,
        'data_not_NULL' => 0,
        'data_precision' => 10,
        'data_scale' => 2,
        'data_size' => 'normal',
        'data_type' => 'int',
      ),
      'display_format' => '$display_output = $entity_field_item[\'value\'];',
      'store' => 1,
    ),
    'translatable' => 0,
    'type' => 'computed',
  );

  return $field_bases;
}
