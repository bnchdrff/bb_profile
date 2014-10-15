<?php
/**
 * @file
 * bb_misc.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function bb_misc_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer commerce_order entities'.
  $permissions['administer commerce_order entities'] = array(
    'name' => 'administer commerce_order entities',
    'roles' => array(
      'administrator' => 'administrator',
      'domestic fulfiller' => 'domestic fulfiller',
      'international fulfiller' => 'international fulfiller',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: 'create commerce_order entities'.
  $permissions['create commerce_order entities'] = array(
    'name' => 'create commerce_order entities',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: 'edit any commerce_order entity'.
  $permissions['edit any commerce_order entity'] = array(
    'name' => 'edit any commerce_order entity',
    'roles' => array(
      'administrator' => 'administrator',
      'domestic fulfiller' => 'domestic fulfiller',
      'fulfiller' => 'fulfiller',
      'international fulfiller' => 'international fulfiller',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: 'edit any field_customs_id'.
  $permissions['edit any field_customs_id'] = array(
    'name' => 'edit any field_customs_id',
    'roles' => array(
      'administrator' => 'administrator',
      'international fulfiller' => 'international fulfiller',
    ),
    'module' => 'bb_misc',
  );

  // Exported permission: 'edit own commerce_order entities'.
  $permissions['edit own commerce_order entities'] = array(
    'name' => 'edit own commerce_order entities',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: 'edit own field_customs_id'.
  $permissions['edit own field_customs_id'] = array(
    'name' => 'edit own field_customs_id',
    'roles' => array(),
    'module' => 'bb_misc',
  );

  // Exported permission: 'redeem any coupon'.
  $permissions['redeem any coupon'] = array(
    'name' => 'redeem any coupon',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'commerce_coupon',
  );

  // Exported permission: 'view any commerce_order entity'.
  $permissions['view any commerce_order entity'] = array(
    'name' => 'view any commerce_order entity',
    'roles' => array(
      'administrator' => 'administrator',
      'domestic fulfiller' => 'domestic fulfiller',
      'fulfiller' => 'fulfiller',
      'international fulfiller' => 'international fulfiller',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: 'view any field_customs_id'.
  $permissions['view any field_customs_id'] = array(
    'name' => 'view any field_customs_id',
    'roles' => array(
      'administrator' => 'administrator',
      'international fulfiller' => 'international fulfiller',
    ),
    'module' => 'bb_misc',
  );

  // Exported permission: 'view own commerce_order entities'.
  $permissions['view own commerce_order entities'] = array(
    'name' => 'view own commerce_order entities',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: 'view own field_customs_id'.
  $permissions['view own field_customs_id'] = array(
    'name' => 'view own field_customs_id',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'bb_misc',
  );

  // Exported permission: 'view payments'.
  $permissions['view payments'] = array(
    'name' => 'view payments',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'commerce_payment',
  );

  // Exported permission: 'view the administration theme'.
  $permissions['view the administration theme'] = array(
    'name' => 'view the administration theme',
    'roles' => array(
      'administrator' => 'administrator',
      'domestic fulfiller' => 'domestic fulfiller',
      'fulfiller' => 'fulfiller',
      'international fulfiller' => 'international fulfiller',
    ),
    'module' => 'system',
  );

  return $permissions;
}
