<?php
/**
 * @file
 * bb_misc.default_breakpoint_group.inc
 */

/**
 * Implements hook_default_breakpoint_group().
 */
function bb_misc_default_breakpoint_group() {
  $export = array();

  $breakpoint_group = new stdClass();
  $breakpoint_group->disabled = FALSE; /* Edit this to true to make a default breakpoint_group disabled initially */
  $breakpoint_group->api_version = 1;
  $breakpoint_group->machine_name = 'bb_theme';
  $breakpoint_group->name = 'Beard Balm';
  $breakpoint_group->breakpoints = array(
    0 => 'breakpoints.theme.bb_theme.wide',
    1 => 'breakpoints.theme.bb_theme.normal',
    2 => 'breakpoints.theme.bb_theme.narrow',
    3 => 'breakpoints.theme.bb_theme.mobile',
  );
  $breakpoint_group->type = 'theme';
  $breakpoint_group->overridden = 0;
  $export['bb_theme'] = $breakpoint_group;

  return $export;
}
