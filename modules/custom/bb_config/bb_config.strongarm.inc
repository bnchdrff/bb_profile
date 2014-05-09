<?php
/**
 * @file
 * bb_config.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function bb_config_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'sendgrid_integration_apikey';
  $strongarm->value = 'fee 44 Fees';
  $export['sendgrid_integration_apikey'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'sendgrid_integration_ssl';
  $strongarm->value = 1;
  $export['sendgrid_integration_ssl'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'sendgrid_integration_username';
  $strongarm->value = 'bnchdrff';
  $export['sendgrid_integration_username'] = $strongarm;

  return $export;
}
