<?php
/**
 * @file
 * bb_misc.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function bb_misc_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_product_display';
  $strongarm->value = 0;
  $export['comment_anonymous_product_display'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_product_display';
  $strongarm->value = 1;
  $export['comment_default_mode_product_display'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_product_display';
  $strongarm->value = '50';
  $export['comment_default_per_page_product_display'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_product_display';
  $strongarm->value = 1;
  $export['comment_form_location_product_display'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_page';
  $strongarm->value = 0;
  $export['comment_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_product_display';
  $strongarm->value = '1';
  $export['comment_preview_product_display'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_product_display';
  $strongarm->value = '0';
  $export['comment_product_display'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_product_display';
  $strongarm->value = 0;
  $export['comment_subject_field_product_display'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'commerce_empty_cart_paths';
  $strongarm->value = 'checkout
checkout/*
cart
cart/*';
  $export['commerce_empty_cart_paths'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__product_display';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'product_list' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(
        'product:sku' => array(
          'default' => array(
            'weight' => '8',
            'visible' => FALSE,
          ),
          'product_list' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
          'teaser' => array(
            'weight' => '5',
            'visible' => FALSE,
          ),
        ),
        'product:title' => array(
          'default' => array(
            'weight' => '7',
            'visible' => FALSE,
          ),
          'teaser' => array(
            'weight' => '6',
            'visible' => FALSE,
          ),
        ),
        'product:status' => array(
          'default' => array(
            'weight' => '9',
            'visible' => FALSE,
          ),
          'product_list' => array(
            'weight' => '8',
            'visible' => FALSE,
          ),
          'teaser' => array(
            'weight' => '9',
            'visible' => FALSE,
          ),
        ),
        'product:commerce_price' => array(
          'default' => array(
            'weight' => '5',
            'visible' => FALSE,
          ),
          'product_list' => array(
            'weight' => '2',
            'visible' => TRUE,
          ),
          'teaser' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
        ),
        'product:field_images' => array(
          'default' => array(
            'weight' => '4',
            'visible' => TRUE,
          ),
          'product_list' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'teaser' => array(
            'weight' => '3',
            'visible' => TRUE,
          ),
        ),
        'product:title_field' => array(
          'product_list' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
          'default' => array(
            'weight' => '6',
            'visible' => FALSE,
          ),
          'teaser' => array(
            'weight' => '2',
            'visible' => TRUE,
          ),
        ),
        'product:field_prices' => array(
          'default' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
          'teaser' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
        ),
        'product:commerce_product_limit_max' => array(
          'default' => array(
            'weight' => '36',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__product_display'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'jquery_update_compression_type';
  $strongarm->value = 'min';
  $export['jquery_update_compression_type'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'jquery_update_jquery_admin_version';
  $strongarm->value = 'default';
  $export['jquery_update_jquery_admin_version'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'jquery_update_jquery_cdn';
  $strongarm->value = 'none';
  $export['jquery_update_jquery_cdn'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'jquery_update_jquery_version';
  $strongarm->value = '1.10';
  $export['jquery_update_jquery_version'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_product_display';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_product_display'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_product_display';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_product_display'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_page';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_product_display';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_product_display'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_product_display';
  $strongarm->value = '1';
  $export['node_preview_product_display'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_page';
  $strongarm->value = FALSE;
  $export['node_submitted_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_product_display';
  $strongarm->value = 0;
  $export['node_submitted_product_display'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'theme_bb_theme_settings';
  $strongarm->value = array(
    'toggle_logo' => 0,
    'toggle_name' => 0,
    'toggle_slogan' => 0,
    'toggle_node_user_picture' => 1,
    'toggle_comment_user_picture' => 1,
    'toggle_comment_user_verification' => 0,
    'toggle_favicon' => 1,
    'toggle_main_menu' => 0,
    'toggle_secondary_menu' => 0,
    'default_logo' => 1,
    'logo_path' => '',
    'logo_upload' => '',
    'default_favicon' => 1,
    'favicon_path' => '',
    'favicon_upload' => '',
    'general__active_tab' => 'edit-theme-settings',
    'bootstrap__active_tab' => 'edit-advanced',
    'bootstrap_breadcrumb' => '1',
    'bootstrap_breadcrumb_home' => 0,
    'bootstrap_breadcrumb_title' => 1,
    'bootstrap_navbar_position' => '',
    'bootstrap_navbar_inverse' => 0,
    'bootstrap_region_well-navigation' => '',
    'bootstrap_region_well-header' => '',
    'bootstrap_region_well-highlighted' => '',
    'bootstrap_region_well-help' => '',
    'bootstrap_region_well-content' => 'well',
    'bootstrap_region_well-sidebar_first' => 'well',
    'bootstrap_region_well-sidebar_second' => '',
    'bootstrap_region_well-footer' => '',
    'bootstrap_region_well-page_top' => '',
    'bootstrap_region_well-page_bottom' => '',
    'bootstrap_anchors_fix' => 0,
    'bootstrap_anchors_smooth_scrolling' => 0,
    'bootstrap_popover_enabled' => 1,
    'bootstrap_popover_animation' => 1,
    'bootstrap_popover_html' => 0,
    'bootstrap_popover_placement' => 'right',
    'bootstrap_popover_selector' => '',
    'bootstrap_popover_trigger' => array(
      'click' => 'click',
      'hover' => 0,
      'focus' => 0,
      'manual' => 0,
    ),
    'bootstrap_popover_title' => '',
    'bootstrap_popover_content' => '',
    'bootstrap_popover_delay' => '0',
    'bootstrap_popover_container' => 'body',
    'bootstrap_tooltip_enabled' => 1,
    'bootstrap_tooltip_descriptions' => 1,
    'bootstrap_tooltip_animation' => 1,
    'bootstrap_tooltip_html' => 0,
    'bootstrap_tooltip_placement' => 'auto left',
    'bootstrap_tooltip_selector' => '',
    'bootstrap_tooltip_trigger' => array(
      'hover' => 'hover',
      'focus' => 'focus',
      'click' => 0,
      'manual' => 0,
    ),
    'bootstrap_tooltip_delay' => '0',
    'bootstrap_tooltip_container' => 'body',
    'bootstrap_cdn' => '',
    'bootstrap_bootswatch' => '',
    'bootstrap_rebuild_registry' => 0,
    'bootstrap_toggle_jquery_error' => 0,
  );
  $export['theme_bb_theme_settings'] = $strongarm;

  return $export;
}
