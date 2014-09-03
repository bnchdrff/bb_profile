<?php
/**
 * @file
 * bb_misc.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function bb_misc_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: user-menu_fulfil-international:admin/commerce/orders/fulfil_international
  $menu_links['user-menu_fulfil-international:admin/commerce/orders/fulfil_international'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'admin/commerce/orders/fulfil_international',
    'router_path' => 'admin/commerce/orders/fulfil_international',
    'link_title' => 'Fulfil International',
    'options' => array(
      'query' => array(
        'status[]' => 'processing',
      ),
      'attributes' => array(),
      'identifier' => 'user-menu_fulfil-international:admin/commerce/orders/fulfil_international',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -43,
    'customized' => 1,
  );
  // Exported menu link: user-menu_log-out:user/logout
  $menu_links['user-menu_log-out:user/logout'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'user/logout',
    'router_path' => 'user/logout',
    'link_title' => 'Log out',
    'options' => array(
      'identifier' => 'user-menu_log-out:user/logout',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 10,
    'customized' => 0,
  );
  // Exported menu link: user-menu_user-account:user
  $menu_links['user-menu_user-account:user'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'user',
    'router_path' => 'user',
    'link_title' => 'User account',
    'options' => array(
      'alter' => TRUE,
      'identifier' => 'user-menu_user-account:user',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -10,
    'customized' => 0,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Fulfil International');
  t('Log out');
  t('User account');


  return $menu_links;
}
