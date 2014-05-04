<?php
/**
 * @file
 * bb_misc.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function bb_misc_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'sitewide';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'system-help' => array(
          'module' => 'system',
          'delta' => 'help',
          'region' => 'content',
          'weight' => '-10',
        ),
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
          'weight' => '-9',
        ),
        'commerce_cart-cart' => array(
          'module' => 'commerce_cart',
          'delta' => 'cart',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'menu-menu-user-menu' => array(
          'module' => 'menu',
          'delta' => 'menu-user-menu',
          'region' => 'footer',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['sitewide'] = $context;

  return $export;
}
