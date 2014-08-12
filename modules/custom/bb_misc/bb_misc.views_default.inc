<?php
/**
 * @file
 * bb_misc.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function bb_misc_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'bb_orders';
  $view->description = '';
  $view->tag = 'commerce';
  $view->base_table = 'commerce_order';
  $view->human_name = 'BeardBalm: Orders';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Orders';
  $handler->display->display_options['css_class'] = 'commerce-backoffice-view';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer commerce_order entities';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['pure_distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table_megarows';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'order_number' => 'order_number',
    'created' => 'created',
    'name' => 'name',
    'mail' => 'name',
    'commerce_order_total' => 'commerce_order_total',
    'status' => 'status',
    'operations_dropbutton' => 'operations_dropbutton',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'order_number' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '<br />',
      'empty_column' => 0,
    ),
    'mail' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'commerce_order_total' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'operations_dropbutton' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['empty_table'] = TRUE;
  $handler->display->display_options['row_plugin'] = 'fields';
  /* No results behavior: Commerce Order: Empty text */
  $handler->display->display_options['empty']['empty_text']['id'] = 'empty_text';
  $handler->display->display_options['empty']['empty_text']['table'] = 'commerce_order';
  $handler->display->display_options['empty']['empty_text']['field'] = 'empty_text';
  /* Relationship: Commerce Order: Referenced customer profile */
  $handler->display->display_options['relationships']['commerce_customer_billing_profile_id']['id'] = 'commerce_customer_billing_profile_id';
  $handler->display->display_options['relationships']['commerce_customer_billing_profile_id']['table'] = 'field_data_commerce_customer_billing';
  $handler->display->display_options['relationships']['commerce_customer_billing_profile_id']['field'] = 'commerce_customer_billing_profile_id';
  /* Relationship: Commerce Order: Owner */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'commerce_order';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Relationship: Commerce Order: Referenced customer profile */
  $handler->display->display_options['relationships']['commerce_customer_shipping_profile_id']['id'] = 'commerce_customer_shipping_profile_id';
  $handler->display->display_options['relationships']['commerce_customer_shipping_profile_id']['table'] = 'field_data_commerce_customer_shipping';
  $handler->display->display_options['relationships']['commerce_customer_shipping_profile_id']['field'] = 'commerce_customer_shipping_profile_id';
  /* Field: Bulk operations: Commerce Order */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '50';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 1,
      'label' => 'Delete order',
    ),
    'action::views_bulk_operations_script_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'show_all_tokens' => 1,
        'display_values' => array(
          'status' => 'status',
        ),
      ),
    ),
    'action::views_bulk_operations_argument_selector_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'url' => '',
      ),
    ),
    'rules_component::commerce_shipping_service_expedited_intl' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::commerce_shipping_service_expedited_us' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::commerce_shipping_service_free_shipping' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::system_send_email_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::rules_commerce_order_status_canceled' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::rules_commerce_order_status_cart' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::rules_order_status_checkout_checkout' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::rules_order_status_checkout_complete' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::rules_order_status_checkout_payment' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::rules_order_status_checkout_review' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::rules_order_status_checkout_shipping' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::rules_commerce_order_status_completed' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::rules_commerce_order_status_pending' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::rules_commerce_order_status_processing' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Commerce Order: Order number */
  $handler->display->display_options['fields']['order_number']['id'] = 'order_number';
  $handler->display->display_options['fields']['order_number']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['order_number']['field'] = 'order_number';
  $handler->display->display_options['fields']['order_number']['label'] = 'ID';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Name/Email';
  /* Field: Commerce Order: Created date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Created';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['relationship'] = 'uid';
  $handler->display->display_options['fields']['mail']['label'] = 'Email';
  $handler->display->display_options['fields']['mail']['link_to_user'] = '0';
  /* Field: Commerce Order: Shipping information */
  $handler->display->display_options['fields']['commerce_customer_shipping']['id'] = 'commerce_customer_shipping';
  $handler->display->display_options['fields']['commerce_customer_shipping']['table'] = 'field_data_commerce_customer_shipping';
  $handler->display->display_options['fields']['commerce_customer_shipping']['field'] = 'commerce_customer_shipping';
  /* Field: Commerce Order: Total Orders */
  $handler->display->display_options['fields']['field_total_orders']['id'] = 'field_total_orders';
  $handler->display->display_options['fields']['field_total_orders']['table'] = 'field_data_field_total_orders';
  $handler->display->display_options['fields']['field_total_orders']['field'] = 'field_total_orders';
  $handler->display->display_options['fields']['field_total_orders']['element_type'] = '0';
  $handler->display->display_options['fields']['field_total_orders']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_total_orders']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_total_orders']['field_api_classes'] = TRUE;
  /* Field: Commerce Order: Order status */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['label'] = 'Status';
  /* Sort criterion: Commerce Order: Updated date */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'commerce_order';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
  $handler->display->display_options['sorts']['changed']['order'] = 'DESC';
  /* Contextual filter: Commerce Order: Order ID */
  $handler->display->display_options['arguments']['order_id']['id'] = 'order_id';
  $handler->display->display_options['arguments']['order_id']['table'] = 'commerce_order';
  $handler->display->display_options['arguments']['order_id']['field'] = 'order_id';
  $handler->display->display_options['arguments']['order_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['order_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['order_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['order_id']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Commerce Order: Order status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'commerce_order';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Filter by';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['multiple'] = TRUE;
  /* Filter criterion: Date: Date (commerce_order) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'commerce_order';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['operator'] = 'between';
  $handler->display->display_options['filters']['date_filter']['group'] = 1;
  $handler->display->display_options['filters']['date_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter']['expose']['operator_id'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['operator'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['identifier'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'commerce_order.created' => 'commerce_order.created',
  );
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'contains';
  $handler->display->display_options['filters']['combine']['group'] = 1;
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'order_number' => 'order_number',
    'name' => 'name',
    'mail' => 'mail',
  );

  /* Display: Admin page */
  $handler = $view->new_display('page', 'Admin page', 'admin_page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'admin/commerce/orders/list';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'Orders';
  $handler->display->display_options['menu']['weight'] = '-10';
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Orders';
  $handler->display->display_options['tab_options']['description'] = 'Manage orders in the store.';
  $handler->display->display_options['tab_options']['weight'] = '';
  $handler->display->display_options['tab_options']['name'] = 'management';

  /* Display: Fulfillment: New domestic orders */
  $handler = $view->new_display('page', 'Fulfillment: New domestic orders', 'fulfil_domestic');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table_megarows';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'order_number' => 'order_number',
    'created' => 'created',
    'name' => 'name',
    'quantity' => 'quantity',
    'commerce_customer_address_thoroughfare' => 'commerce_customer_address_thoroughfare',
    'commerce_customer_address_premise' => 'commerce_customer_address_thoroughfare',
    'commerce_customer_address_organisation_name' => 'commerce_customer_address_thoroughfare',
    'commerce_customer_address_locality' => 'commerce_customer_address_locality',
    'commerce_customer_address_administrative_area' => 'commerce_customer_address_locality',
    'commerce_customer_address_postal_code' => 'commerce_customer_address_locality',
    'commerce_customer_address_country' => 'commerce_customer_address_locality',
    'field_total_orders' => 'field_total_orders',
    'status' => 'status',
  );
  $handler->display->display_options['style_options']['default'] = 'created';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'order_number' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '<br />',
      'empty_column' => 0,
    ),
    'quantity' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'commerce_customer_address_thoroughfare' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '<br />',
      'empty_column' => 0,
    ),
    'commerce_customer_address_premise' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'commerce_customer_address_organisation_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'commerce_customer_address_locality' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '<br />',
      'empty_column' => 0,
    ),
    'commerce_customer_address_administrative_area' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'commerce_customer_address_postal_code' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'commerce_customer_address_country' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_total_orders' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['empty_table'] = TRUE;
  $handler->display->display_options['style_options']['scroll_padding'] = '120';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Commerce Order: Referenced line items */
  $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['id'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['table'] = 'field_data_commerce_line_items';
  $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['field'] = 'commerce_line_items_line_item_id';
  /* Relationship: Commerce Order: Referenced customer profile */
  $handler->display->display_options['relationships']['commerce_customer_billing_profile_id']['id'] = 'commerce_customer_billing_profile_id';
  $handler->display->display_options['relationships']['commerce_customer_billing_profile_id']['table'] = 'field_data_commerce_customer_billing';
  $handler->display->display_options['relationships']['commerce_customer_billing_profile_id']['field'] = 'commerce_customer_billing_profile_id';
  /* Relationship: Commerce Order: Owner */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'commerce_order';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Relationship: Commerce Order: Referenced customer profile */
  $handler->display->display_options['relationships']['commerce_customer_shipping_profile_id']['id'] = 'commerce_customer_shipping_profile_id';
  $handler->display->display_options['relationships']['commerce_customer_shipping_profile_id']['table'] = 'field_data_commerce_customer_shipping';
  $handler->display->display_options['relationships']['commerce_customer_shipping_profile_id']['field'] = 'commerce_customer_shipping_profile_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Bulk operations: Commerce Order */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '50';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 1,
      'label' => 'Delete order',
    ),
    'action::views_bulk_operations_script_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'show_all_tokens' => 1,
        'display_values' => array(
          'status' => 'status',
        ),
      ),
    ),
    'action::views_bulk_operations_argument_selector_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'url' => '',
      ),
    ),
    'rules_component::commerce_shipping_service_expedited_intl' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::commerce_shipping_service_expedited_us' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::commerce_shipping_service_free_shipping' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::system_send_email_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::rules_commerce_order_status_canceled' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::rules_commerce_order_status_cart' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::rules_order_status_checkout_checkout' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::rules_order_status_checkout_complete' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::rules_order_status_checkout_payment' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::rules_order_status_checkout_review' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::rules_order_status_checkout_shipping' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::rules_commerce_order_status_completed' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::rules_commerce_order_status_pending' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::rules_commerce_order_status_processing' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Commerce Order: Order number */
  $handler->display->display_options['fields']['order_number']['id'] = 'order_number';
  $handler->display->display_options['fields']['order_number']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['order_number']['field'] = 'order_number';
  $handler->display->display_options['fields']['order_number']['label'] = 'ID';
  $handler->display->display_options['fields']['order_number']['link_to_order'] = 'admin';
  /* Field: Commerce Order: Created date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Created';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Name/Email';
  /* Field: Commerce Line Item: Quantity */
  $handler->display->display_options['fields']['quantity']['id'] = 'quantity';
  $handler->display->display_options['fields']['quantity']['table'] = 'commerce_line_item';
  $handler->display->display_options['fields']['quantity']['field'] = 'quantity';
  $handler->display->display_options['fields']['quantity']['relationship'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['fields']['quantity']['label'] = '# of Cans';
  $handler->display->display_options['fields']['quantity']['precision'] = '0';
  /* Field: Commerce Customer profile: Address - Thoroughfare (i.e. Street address) */
  $handler->display->display_options['fields']['commerce_customer_address_thoroughfare']['id'] = 'commerce_customer_address_thoroughfare';
  $handler->display->display_options['fields']['commerce_customer_address_thoroughfare']['table'] = 'field_data_commerce_customer_address';
  $handler->display->display_options['fields']['commerce_customer_address_thoroughfare']['field'] = 'commerce_customer_address_thoroughfare';
  $handler->display->display_options['fields']['commerce_customer_address_thoroughfare']['relationship'] = 'commerce_customer_shipping_profile_id';
  $handler->display->display_options['fields']['commerce_customer_address_thoroughfare']['label'] = 'Address';
  $handler->display->display_options['fields']['commerce_customer_address_thoroughfare']['element_type'] = '0';
  $handler->display->display_options['fields']['commerce_customer_address_thoroughfare']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['commerce_customer_address_thoroughfare']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['commerce_customer_address_thoroughfare']['element_default_classes'] = FALSE;
  /* Field: Commerce Customer profile: Address - Premise (i.e. Apartment / Suite number) */
  $handler->display->display_options['fields']['commerce_customer_address_premise']['id'] = 'commerce_customer_address_premise';
  $handler->display->display_options['fields']['commerce_customer_address_premise']['table'] = 'field_data_commerce_customer_address';
  $handler->display->display_options['fields']['commerce_customer_address_premise']['field'] = 'commerce_customer_address_premise';
  $handler->display->display_options['fields']['commerce_customer_address_premise']['relationship'] = 'commerce_customer_shipping_profile_id';
  $handler->display->display_options['fields']['commerce_customer_address_premise']['label'] = '';
  $handler->display->display_options['fields']['commerce_customer_address_premise']['element_type'] = '0';
  $handler->display->display_options['fields']['commerce_customer_address_premise']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['commerce_customer_address_premise']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['commerce_customer_address_premise']['element_default_classes'] = FALSE;
  /* Field: Commerce Customer profile: Address - Company */
  $handler->display->display_options['fields']['commerce_customer_address_organisation_name']['id'] = 'commerce_customer_address_organisation_name';
  $handler->display->display_options['fields']['commerce_customer_address_organisation_name']['table'] = 'field_data_commerce_customer_address';
  $handler->display->display_options['fields']['commerce_customer_address_organisation_name']['field'] = 'commerce_customer_address_organisation_name';
  $handler->display->display_options['fields']['commerce_customer_address_organisation_name']['relationship'] = 'commerce_customer_shipping_profile_id';
  $handler->display->display_options['fields']['commerce_customer_address_organisation_name']['label'] = '';
  $handler->display->display_options['fields']['commerce_customer_address_organisation_name']['element_type'] = '0';
  $handler->display->display_options['fields']['commerce_customer_address_organisation_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['commerce_customer_address_organisation_name']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['commerce_customer_address_organisation_name']['element_default_classes'] = FALSE;
  /* Field: Commerce Customer profile: Address - Locality (i.e. City) */
  $handler->display->display_options['fields']['commerce_customer_address_locality']['id'] = 'commerce_customer_address_locality';
  $handler->display->display_options['fields']['commerce_customer_address_locality']['table'] = 'field_data_commerce_customer_address';
  $handler->display->display_options['fields']['commerce_customer_address_locality']['field'] = 'commerce_customer_address_locality';
  $handler->display->display_options['fields']['commerce_customer_address_locality']['relationship'] = 'commerce_customer_shipping_profile_id';
  $handler->display->display_options['fields']['commerce_customer_address_locality']['label'] = 'City, State, Zip, Country';
  $handler->display->display_options['fields']['commerce_customer_address_locality']['element_type'] = '0';
  $handler->display->display_options['fields']['commerce_customer_address_locality']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['commerce_customer_address_locality']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['commerce_customer_address_locality']['element_default_classes'] = FALSE;
  /* Field: Commerce Customer profile: Address - Administrative area (i.e. State / Province) */
  $handler->display->display_options['fields']['commerce_customer_address_administrative_area']['id'] = 'commerce_customer_address_administrative_area';
  $handler->display->display_options['fields']['commerce_customer_address_administrative_area']['table'] = 'field_data_commerce_customer_address';
  $handler->display->display_options['fields']['commerce_customer_address_administrative_area']['field'] = 'commerce_customer_address_administrative_area';
  $handler->display->display_options['fields']['commerce_customer_address_administrative_area']['relationship'] = 'commerce_customer_billing_profile_id';
  $handler->display->display_options['fields']['commerce_customer_address_administrative_area']['label'] = '';
  $handler->display->display_options['fields']['commerce_customer_address_administrative_area']['element_type'] = '0';
  $handler->display->display_options['fields']['commerce_customer_address_administrative_area']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['commerce_customer_address_administrative_area']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['commerce_customer_address_administrative_area']['element_default_classes'] = FALSE;
  /* Field: Commerce Customer profile: Address - Postal code */
  $handler->display->display_options['fields']['commerce_customer_address_postal_code']['id'] = 'commerce_customer_address_postal_code';
  $handler->display->display_options['fields']['commerce_customer_address_postal_code']['table'] = 'field_data_commerce_customer_address';
  $handler->display->display_options['fields']['commerce_customer_address_postal_code']['field'] = 'commerce_customer_address_postal_code';
  $handler->display->display_options['fields']['commerce_customer_address_postal_code']['relationship'] = 'commerce_customer_shipping_profile_id';
  $handler->display->display_options['fields']['commerce_customer_address_postal_code']['label'] = '';
  $handler->display->display_options['fields']['commerce_customer_address_postal_code']['element_type'] = '0';
  $handler->display->display_options['fields']['commerce_customer_address_postal_code']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['commerce_customer_address_postal_code']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['commerce_customer_address_postal_code']['element_default_classes'] = FALSE;
  /* Field: Commerce Customer profile: Address - Country */
  $handler->display->display_options['fields']['commerce_customer_address_country']['id'] = 'commerce_customer_address_country';
  $handler->display->display_options['fields']['commerce_customer_address_country']['table'] = 'field_data_commerce_customer_address';
  $handler->display->display_options['fields']['commerce_customer_address_country']['field'] = 'commerce_customer_address_country';
  $handler->display->display_options['fields']['commerce_customer_address_country']['relationship'] = 'commerce_customer_shipping_profile_id';
  $handler->display->display_options['fields']['commerce_customer_address_country']['label'] = '';
  $handler->display->display_options['fields']['commerce_customer_address_country']['element_type'] = '0';
  $handler->display->display_options['fields']['commerce_customer_address_country']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['commerce_customer_address_country']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['commerce_customer_address_country']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['commerce_customer_address_country']['display_name'] = 1;
  /* Field: Commerce Order: Total Orders */
  $handler->display->display_options['fields']['field_total_orders']['id'] = 'field_total_orders';
  $handler->display->display_options['fields']['field_total_orders']['table'] = 'field_data_field_total_orders';
  $handler->display->display_options['fields']['field_total_orders']['field'] = 'field_total_orders';
  $handler->display->display_options['fields']['field_total_orders']['label'] = '# of Previous Orders';
  $handler->display->display_options['fields']['field_total_orders']['element_type'] = '0';
  $handler->display->display_options['fields']['field_total_orders']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_total_orders']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_total_orders']['field_api_classes'] = TRUE;
  /* Field: Commerce Order: Order status */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['label'] = 'Status';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['operator'] = 'OR';
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'AND',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Commerce Order: Order status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'commerce_order';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    'processing' => 'processing',
  );
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Filter by';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
    6 => 0,
  );
  /* Filter criterion: Date: Date (commerce_order) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'commerce_order';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['operator'] = 'between';
  $handler->display->display_options['filters']['date_filter']['group'] = 1;
  $handler->display->display_options['filters']['date_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter']['expose']['operator_id'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['operator'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['identifier'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'commerce_order.created' => 'commerce_order.created',
  );
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'contains';
  $handler->display->display_options['filters']['combine']['group'] = 1;
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'order_number' => 'order_number',
    'name' => 'name',
    'mail' => 'mail',
  );
  /* Filter criterion: Commerce Customer profile: Address - Country */
  $handler->display->display_options['filters']['commerce_customer_address_country']['id'] = 'commerce_customer_address_country';
  $handler->display->display_options['filters']['commerce_customer_address_country']['table'] = 'field_data_commerce_customer_address';
  $handler->display->display_options['filters']['commerce_customer_address_country']['field'] = 'commerce_customer_address_country';
  $handler->display->display_options['filters']['commerce_customer_address_country']['relationship'] = 'commerce_customer_shipping_profile_id';
  $handler->display->display_options['filters']['commerce_customer_address_country']['value'] = array(
    'US' => 'US',
  );
  $handler->display->display_options['filters']['commerce_customer_address_country']['group'] = 1;
  /* Filter criterion: Commerce Line Item: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'commerce_line_item';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['filters']['type']['value'] = array(
    'product' => 'product',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Commerce Line Item: Quantity */
  $handler->display->display_options['filters']['quantity']['id'] = 'quantity';
  $handler->display->display_options['filters']['quantity']['table'] = 'commerce_line_item';
  $handler->display->display_options['filters']['quantity']['field'] = 'quantity';
  $handler->display->display_options['filters']['quantity']['relationship'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['filters']['quantity']['operator'] = '>';
  $handler->display->display_options['filters']['quantity']['value']['value'] = '1';
  $handler->display->display_options['filters']['quantity']['group'] = 2;
  /* Filter criterion: Commerce Customer profile: Address - Country */
  $handler->display->display_options['filters']['commerce_customer_address_country_1']['id'] = 'commerce_customer_address_country_1';
  $handler->display->display_options['filters']['commerce_customer_address_country_1']['table'] = 'field_data_commerce_customer_address';
  $handler->display->display_options['filters']['commerce_customer_address_country_1']['field'] = 'commerce_customer_address_country';
  $handler->display->display_options['filters']['commerce_customer_address_country_1']['relationship'] = 'commerce_customer_shipping_profile_id';
  $handler->display->display_options['filters']['commerce_customer_address_country_1']['operator'] = 'not in';
  $handler->display->display_options['filters']['commerce_customer_address_country_1']['value'] = array(
    'US' => 'US',
  );
  $handler->display->display_options['filters']['commerce_customer_address_country_1']['group'] = 2;
  /* Filter criterion: Commerce Line Item: Type */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'commerce_line_item';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['relationship'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'product' => 'product',
  );
  $handler->display->display_options['filters']['type_1']['group'] = 2;
  $handler->display->display_options['path'] = 'admin/commerce/orders/fulfil_domestic';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Domestic fulfilment';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Fulfillment: New international orders */
  $handler = $view->new_display('page', 'Fulfillment: New international orders', 'page_1');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'editableviews_table';
  $handler->display->display_options['style_options']['columns'] = array(
    'order_number' => 'order_number',
    'created' => 'created',
    'field_shipped_date' => 'field_shipped_date',
    'field_customs_id_editable' => 'field_customs_id_editable',
    'quantity' => 'quantity',
    'field_special_instructions' => 'field_special_instructions',
    'name' => 'name',
    'commerce_customer_address' => 'commerce_customer_address',
    'field_total_orders' => 'field_total_orders',
    'status' => 'status',
  );
  $handler->display->display_options['style_options']['default'] = 'created';
  $handler->display->display_options['style_options']['info'] = array(
    'order_number' => array(
      'sortable' => 0,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_shipped_date' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_customs_id_editable' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'quantity' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_special_instructions' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'commerce_customer_address' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_total_orders' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Commerce Order: Referenced line items */
  $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['id'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['table'] = 'field_data_commerce_line_items';
  $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['field'] = 'commerce_line_items_line_item_id';
  /* Relationship: Commerce Order: Referenced customer profile */
  $handler->display->display_options['relationships']['commerce_customer_billing_profile_id']['id'] = 'commerce_customer_billing_profile_id';
  $handler->display->display_options['relationships']['commerce_customer_billing_profile_id']['table'] = 'field_data_commerce_customer_billing';
  $handler->display->display_options['relationships']['commerce_customer_billing_profile_id']['field'] = 'commerce_customer_billing_profile_id';
  /* Relationship: Commerce Order: Owner */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'commerce_order';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Relationship: Commerce Order: Referenced customer profile */
  $handler->display->display_options['relationships']['commerce_customer_shipping_profile_id']['id'] = 'commerce_customer_shipping_profile_id';
  $handler->display->display_options['relationships']['commerce_customer_shipping_profile_id']['table'] = 'field_data_commerce_customer_shipping';
  $handler->display->display_options['relationships']['commerce_customer_shipping_profile_id']['field'] = 'commerce_customer_shipping_profile_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Commerce Order: Order number */
  $handler->display->display_options['fields']['order_number']['id'] = 'order_number';
  $handler->display->display_options['fields']['order_number']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['order_number']['field'] = 'order_number';
  $handler->display->display_options['fields']['order_number']['label'] = 'ID';
  /* Field: Commerce Order: Created date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Entered';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  /* Field: Commerce Order: Shipped */
  $handler->display->display_options['fields']['field_shipped_date']['id'] = 'field_shipped_date';
  $handler->display->display_options['fields']['field_shipped_date']['table'] = 'field_data_field_shipped_date';
  $handler->display->display_options['fields']['field_shipped_date']['field'] = 'field_shipped_date';
  $handler->display->display_options['fields']['field_shipped_date']['element_type'] = '0';
  $handler->display->display_options['fields']['field_shipped_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_shipped_date']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_shipped_date']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_shipped_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  $handler->display->display_options['fields']['field_shipped_date']['field_api_classes'] = TRUE;
  /* Field: Commerce Order: Customs ID (editable) */
  $handler->display->display_options['fields']['field_customs_id_editable']['id'] = 'field_customs_id_editable';
  $handler->display->display_options['fields']['field_customs_id_editable']['table'] = 'field_data_field_customs_id';
  $handler->display->display_options['fields']['field_customs_id_editable']['field'] = 'field_customs_id_editable';
  $handler->display->display_options['fields']['field_customs_id_editable']['label'] = 'Customs ID';
  $handler->display->display_options['fields']['field_customs_id_editable']['element_type'] = '0';
  $handler->display->display_options['fields']['field_customs_id_editable']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_customs_id_editable']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_customs_id_editable']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_customs_id_editable']['settings'] = array(
    'title_style' => '_none',
    'title_link' => '',
    'title_class' => '',
  );
  $handler->display->display_options['fields']['field_customs_id_editable']['field_api_classes'] = TRUE;
  $handler->display->display_options['fields']['field_customs_id_editable']['widget_type'] = 'text_textfield';
  $handler->display->display_options['fields']['field_customs_id_editable']['suppress_label'] = 1;
  $handler->display->display_options['fields']['field_customs_id_editable']['suppress_description'] = 0;
  /* Field: Field: Special Instructions */
  $handler->display->display_options['fields']['field_special_instructions']['id'] = 'field_special_instructions';
  $handler->display->display_options['fields']['field_special_instructions']['table'] = 'field_data_field_special_instructions';
  $handler->display->display_options['fields']['field_special_instructions']['field'] = 'field_special_instructions';
  $handler->display->display_options['fields']['field_special_instructions']['element_type'] = '0';
  $handler->display->display_options['fields']['field_special_instructions']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_special_instructions']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_special_instructions']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_special_instructions']['field_api_classes'] = TRUE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Name/Email';
  /* Field: Commerce Customer profile: Address */
  $handler->display->display_options['fields']['commerce_customer_address']['id'] = 'commerce_customer_address';
  $handler->display->display_options['fields']['commerce_customer_address']['table'] = 'field_data_commerce_customer_address';
  $handler->display->display_options['fields']['commerce_customer_address']['field'] = 'commerce_customer_address';
  $handler->display->display_options['fields']['commerce_customer_address']['relationship'] = 'commerce_customer_shipping_profile_id';
  $handler->display->display_options['fields']['commerce_customer_address']['label'] = 'Shipping Address';
  $handler->display->display_options['fields']['commerce_customer_address']['element_type'] = '0';
  $handler->display->display_options['fields']['commerce_customer_address']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['commerce_customer_address']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['commerce_customer_address']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['commerce_customer_address']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['commerce_customer_address']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  $handler->display->display_options['fields']['commerce_customer_address']['field_api_classes'] = TRUE;
  /* Field: Commerce Order: Total Orders */
  $handler->display->display_options['fields']['field_total_orders']['id'] = 'field_total_orders';
  $handler->display->display_options['fields']['field_total_orders']['table'] = 'field_data_field_total_orders';
  $handler->display->display_options['fields']['field_total_orders']['field'] = 'field_total_orders';
  $handler->display->display_options['fields']['field_total_orders']['element_type'] = '0';
  $handler->display->display_options['fields']['field_total_orders']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_total_orders']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_total_orders']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_total_orders']['field_api_classes'] = TRUE;
  /* Field: Commerce Order: Order status */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['label'] = 'Status';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Commerce Order: Order status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'commerce_order';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    'processing' => 'processing',
    'completed' => 'completed',
  );
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Filter by';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
    6 => 0,
  );
  $handler->display->display_options['filters']['status']['expose']['reduce'] = TRUE;
  /* Filter criterion: Date: Date (commerce_order) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'commerce_order';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['operator'] = 'between';
  $handler->display->display_options['filters']['date_filter']['group'] = 1;
  $handler->display->display_options['filters']['date_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter']['expose']['operator_id'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['operator'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['identifier'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'commerce_order.created' => 'commerce_order.created',
  );
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'contains';
  $handler->display->display_options['filters']['combine']['group'] = 1;
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'order_number' => 'order_number',
    'name' => 'name',
    'mail' => 'mail',
  );
  /* Filter criterion: Commerce Customer profile: Address - Country */
  $handler->display->display_options['filters']['commerce_customer_address_country']['id'] = 'commerce_customer_address_country';
  $handler->display->display_options['filters']['commerce_customer_address_country']['table'] = 'field_data_commerce_customer_address';
  $handler->display->display_options['filters']['commerce_customer_address_country']['field'] = 'commerce_customer_address_country';
  $handler->display->display_options['filters']['commerce_customer_address_country']['relationship'] = 'commerce_customer_shipping_profile_id';
  $handler->display->display_options['filters']['commerce_customer_address_country']['operator'] = 'not in';
  $handler->display->display_options['filters']['commerce_customer_address_country']['value'] = array(
    'US' => 'US',
  );
  $handler->display->display_options['filters']['commerce_customer_address_country']['group'] = 1;
  /* Filter criterion: Commerce Order: Order status */
  $handler->display->display_options['filters']['status_1']['id'] = 'status_1';
  $handler->display->display_options['filters']['status_1']['table'] = 'commerce_order';
  $handler->display->display_options['filters']['status_1']['field'] = 'status';
  $handler->display->display_options['filters']['status_1']['value'] = array(
    'processing' => 'processing',
    'completed' => 'completed',
  );
  /* Filter criterion: Commerce Line Item: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'commerce_line_item';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['filters']['type']['value'] = array(
    'product' => 'product',
  );
  /* Filter criterion: Commerce Line Item: Quantity */
  $handler->display->display_options['filters']['quantity']['id'] = 'quantity';
  $handler->display->display_options['filters']['quantity']['table'] = 'commerce_line_item';
  $handler->display->display_options['filters']['quantity']['field'] = 'quantity';
  $handler->display->display_options['filters']['quantity']['relationship'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['filters']['quantity']['value']['value'] = '1';
  $handler->display->display_options['path'] = 'admin/commerce/orders/fulfil_international';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'International fulfilment';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['bb_orders'] = $view;

  return $export;
}
