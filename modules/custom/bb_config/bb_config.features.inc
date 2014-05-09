<?php
/**
 * @file
 * bb_config.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function bb_config_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
