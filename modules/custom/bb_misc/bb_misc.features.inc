<?php
/**
 * @file
 * bb_misc.features.inc
 */

/**
 * Implements hook_commerce_flat_rate_default_services().
 */
function bb_misc_commerce_flat_rate_default_services() {
  $items = array(
    'expedited_intl' => array(
      'name' => 'expedited_intl',
      'base' => 'expedited_intl',
      'display_title' => 'Expedited International',
      'description' => '',
      'shipping_method' => 'flat_rate',
      'rules_component' => TRUE,
      'price_component' => 'flat_rate_expedited_intl',
      'weight' => 0,
      'callbacks' => array(
        'rate' => 'commerce_flat_rate_service_rate_order',
        'details_form' => 'expedited_intl_details_form',
        'details_form_validate' => 'expedited_intl_details_form_validate',
        'details_form_submit' => 'expedited_intl_details_form_submit',
      ),
      'module' => 'commerce_flat_rate',
      'title' => 'Expedited International',
      'base_rate' => array(
        'amount' => 2500,
        'currency_code' => 'USD',
        'data' => array(),
      ),
      'data' => array(),
      'admin_list' => TRUE,
    ),
    'expedited_us' => array(
      'name' => 'expedited_us',
      'base' => 'expedited_us',
      'display_title' => 'Expedited US',
      'description' => '',
      'shipping_method' => 'flat_rate',
      'rules_component' => TRUE,
      'price_component' => 'flat_rate_expedited_us',
      'weight' => 1,
      'callbacks' => array(
        'rate' => 'commerce_flat_rate_service_rate_order',
        'details_form' => 'expedited_us_details_form',
        'details_form_validate' => 'expedited_us_details_form_validate',
        'details_form_submit' => 'expedited_us_details_form_submit',
      ),
      'module' => 'commerce_flat_rate',
      'title' => 'Expedited US',
      'base_rate' => array(
        'amount' => 1000,
        'currency_code' => 'USD',
        'data' => array(),
      ),
      'data' => array(),
      'admin_list' => TRUE,
    ),
    'free_intl_shipping' => array(
      'name' => 'free_intl_shipping',
      'base' => 'free_intl_shipping',
      'display_title' => 'Free international shipping',
      'description' => 'Global shipping is free!',
      'shipping_method' => 'flat_rate',
      'rules_component' => TRUE,
      'price_component' => 'flat_rate_free_intl_shipping',
      'weight' => 2,
      'callbacks' => array(
        'rate' => 'commerce_flat_rate_service_rate_order',
        'details_form' => 'free_intl_shipping_details_form',
        'details_form_validate' => 'free_intl_shipping_details_form_validate',
        'details_form_submit' => 'free_intl_shipping_details_form_submit',
      ),
      'module' => 'commerce_flat_rate',
      'title' => 'Free international shipping',
      'base_rate' => array(
        'amount' => 0,
        'currency_code' => 'USD',
        'data' => array(),
      ),
      'data' => array(),
      'admin_list' => TRUE,
    ),
    'free_shipping' => array(
      'name' => 'free_shipping',
      'base' => 'free_shipping',
      'display_title' => 'Free shipping',
      'description' => '',
      'shipping_method' => 'flat_rate',
      'rules_component' => TRUE,
      'price_component' => 'flat_rate_free_shipping',
      'weight' => 3,
      'callbacks' => array(
        'rate' => 'commerce_flat_rate_service_rate_order',
        'details_form' => 'free_shipping_details_form',
        'details_form_validate' => 'free_shipping_details_form_validate',
        'details_form_submit' => 'free_shipping_details_form_submit',
      ),
      'module' => 'commerce_flat_rate',
      'title' => 'Free shipping',
      'base_rate' => array(
        'amount' => 0,
        'currency_code' => 'USD',
        'data' => array(),
      ),
      'data' => array(),
      'admin_list' => TRUE,
    ),
  );
  return $items;
}

/**
 * Implements hook_commerce_product_default_types().
 */
function bb_misc_commerce_product_default_types() {
  $items = array(
    'product' => array(
      'type' => 'product',
      'name' => 'Product',
      'description' => 'A basic product type.',
      'help' => '',
      'revision' => 1,
    ),
  );
  return $items;
}

/**
 * Implements hook_commerce_tax_default_rates().
 */
function bb_misc_commerce_tax_default_rates() {
  $items = array(
    'sample_michigan_sales_tax' => array(
      'name' => 'sample_michigan_sales_tax',
      'display_title' => 'Sample Michigan Sales Tax 6%',
      'description' => '',
      'rate' => 0.06,
      'type' => 'sales_tax',
      'rules_component' => 'commerce_tax_rate_sample_michigan_sales_tax',
      'default_rules_component' => 0,
      'price_component' => 'tax|sample_michigan_sales_tax',
      'calculation_callback' => 'commerce_tax_rate_calculate',
      'module' => 'commerce_tax_ui',
      'title' => 'Sample Michigan Sales Tax 6%',
      'admin_list' => TRUE,
    ),
  );
  return $items;
}

/**
 * Implements hook_commerce_tax_default_types().
 */
function bb_misc_commerce_tax_default_types() {
  $items = array(
    'sales_tax' => array(
      'name' => 'sales_tax',
      'display_title' => 'Sales tax',
      'description' => 'A basic type for taxes that do not display inclusive with product prices.',
      'display_inclusive' => 0,
      'round_mode' => 0,
      'rule' => 'commerce_tax_type_sales_tax',
      'module' => 'commerce_tax_ui',
      'title' => 'Sales tax',
      'admin_list' => TRUE,
    ),
  );
  return $items;
}

/**
 * Implements hook_ctools_plugin_api().
 */
function bb_misc_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function bb_misc_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function bb_misc_node_info() {
  $items = array(
    'page' => array(
      'name' => t('Basic page'),
      'base' => 'node_content',
      'description' => t('Use <em>basic pages</em> for your static content, such as an \'About us\' page.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'product_display' => array(
      'name' => t('Product display'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
