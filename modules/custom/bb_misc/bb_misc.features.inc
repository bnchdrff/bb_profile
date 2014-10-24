<?php
/**
 * @file
 * bb_misc.features.inc
 */

/**
 * Implements hook_default_commerce_discount().
 */
function bb_misc_default_commerce_discount() {
  $items = array();
  $items['discount_test'] = entity_import('commerce_discount', '{
    "name" : "discount_test",
    "label" : "test",
    "type" : "order_discount",
    "component_title" : "test name",
    "export_status" : "1",
    "commerce_discount_date" : [],
    "commerce_discount_offer" : {
      "type" : "percentage",
      "commerce_percentage" : { "und" : [ { "value" : "100.00" } ] }
    },
    "inline_conditions" : []
  }');
  return $items;
}

/**
 * Implements hook_commerce_flat_rate_default_services().
 */
function bb_misc_commerce_flat_rate_default_services() {
  $items = array(
    'standard_global_shipping' => array(
      'name' => 'standard_global_shipping',
      'base' => 'standard_global_shipping',
      'display_title' => 'Global Flat Rate S&H',
      'description' => 'edit description!',
      'shipping_method' => 'flat_rate',
      'rules_component' => TRUE,
      'price_component' => 'flat_rate_standard_global_shipping',
      'weight' => 1,
      'callbacks' => array(
        'rate' => 'commerce_flat_rate_service_rate_order',
        'details_form' => 'standard_global_shipping_details_form',
        'details_form_validate' => 'standard_global_shipping_details_form_validate',
        'details_form_submit' => 'standard_global_shipping_details_form_submit',
      ),
      'module' => 'commerce_flat_rate',
      'title' => 'Standard global shipping',
      'base_rate' => array(
        'amount' => 200,
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
  if ($module == "boxes" && $api == "box") {
    return array("version" => "1");
  }
  if ($module == "breakpoints" && $api == "default_breakpoint_group") {
    return array("version" => "1");
  }
  if ($module == "breakpoints" && $api == "default_breakpoints") {
    return array("version" => "1");
  }
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "picture" && $api == "default_picture_mapping") {
    return array("version" => "2");
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
 * Implements hook_image_default_styles().
 */
function bb_misc_image_default_styles() {
  $styles = array();

  // Exported image style: frontpage_full.
  $styles['frontpage_full'] = array(
    'name' => 'frontpage_full',
    'label' => 'Frontpage full',
    'effects' => array(
      2 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 800,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: fullwidthbreakpoints_theme_bb_theme_mobile_1x.
  $styles['fullwidthbreakpoints_theme_bb_theme_mobile_1x'] = array(
    'name' => 'fullwidthbreakpoints_theme_bb_theme_mobile_1x',
    'label' => 'fullwidthbreakpoints_theme_bb_theme_mobile_1x',
    'effects' => array(
      3 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 682,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: fullwidthbreakpoints_theme_bb_theme_narrow_1x.
  $styles['fullwidthbreakpoints_theme_bb_theme_narrow_1x'] = array(
    'name' => 'fullwidthbreakpoints_theme_bb_theme_narrow_1x',
    'label' => 'fullwidthbreakpoints_theme_bb_theme_narrow_1x',
    'effects' => array(
      4 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 906,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: fullwidthbreakpoints_theme_bb_theme_normal_1x.
  $styles['fullwidthbreakpoints_theme_bb_theme_normal_1x'] = array(
    'name' => 'fullwidthbreakpoints_theme_bb_theme_normal_1x',
    'label' => 'fullwidthbreakpoints_theme_bb_theme_normal_1x',
    'effects' => array(
      5 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 1114,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: fullwidthbreakpoints_theme_bb_theme_wide_1x.
  $styles['fullwidthbreakpoints_theme_bb_theme_wide_1x'] = array(
    'name' => 'fullwidthbreakpoints_theme_bb_theme_wide_1x',
    'label' => 'fullwidthbreakpoints_theme_bb_theme_wide_1x',
    'effects' => array(
      6 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 1114,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: product_full.
  $styles['product_full'] = array(
    'name' => 'product_full',
    'label' => 'product_full',
    'effects' => array(
      1 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 1140,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
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
