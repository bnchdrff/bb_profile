<?php
/**
 * @file
 * bb_misc.default_picture_mapping.inc
 */

/**
 * Implements hook_default_picture_mapping().
 */
function bb_misc_default_picture_mapping() {
  $export = array();

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'fullwidth_breaks';
  $picture_mapping->machine_name = 'fullwidth_breaks';
  $picture_mapping->breakpoint_group = 'bb_theme';
  $picture_mapping->mapping = array(
    'breakpoints.theme.bb_theme.wide' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'fullwidthbreakpoints_theme_bb_theme_wide_1x',
      ),
    ),
    'breakpoints.theme.bb_theme.normal' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'fullwidthbreakpoints_theme_bb_theme_normal_1x',
      ),
    ),
    'breakpoints.theme.bb_theme.narrow' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'fullwidthbreakpoints_theme_bb_theme_narrow_1x',
      ),
    ),
    'breakpoints.theme.bb_theme.mobile' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'fullwidthbreakpoints_theme_bb_theme_mobile_1x',
      ),
    ),
  );
  $export['fullwidth_breaks'] = $picture_mapping;

  return $export;
}
