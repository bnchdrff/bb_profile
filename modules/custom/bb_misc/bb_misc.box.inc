<?php
/**
 * @file
 * bb_misc.box.inc
 */

/**
 * Implements hook_default_box().
 */
function bb_misc_default_box() {
  $export = array();

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'logo';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'Logo';
  $box->options = array(
    'body' => array(
      'value' => '<img src="profiles/commerce_kickstart/themes/bb_theme/images/rsz_1balmlabelfrontdetroit.png" alt="Beard Balm" title="Beard Balm">',
      'format' => 'full_html',
    ),
  );
  $export['logo'] = $box;

  return $export;
}
