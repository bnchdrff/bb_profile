<?php
/**
 * @file
 * bb_config.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function bb_config_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer sendgrid settings'.
  $permissions['administer sendgrid settings'] = array(
    'name' => 'administer sendgrid settings',
    'roles' => array(),
    'module' => 'sendgrid_integration',
  );

  return $permissions;
}
