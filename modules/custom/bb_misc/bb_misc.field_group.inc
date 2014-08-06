<?php
/**
 * @file
 * bb_misc.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function bb_misc_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_customer_fields|commerce_order|commerce_order|form';
  $field_group->group_name = 'group_customer_fields';
  $field_group->entity_type = 'commerce_order';
  $field_group->bundle = 'commerce_order';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Optional',
    'weight' => '10',
    'children' => array(
      0 => 'field_gift_order',
      1 => 'field_special_instructions',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-customer-fields field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_customer_fields|commerce_order|commerce_order|form'] = $field_group;

  return $export;
}
