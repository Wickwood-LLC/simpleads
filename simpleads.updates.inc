<?php

/**
 * @file
 * SimpleAds Updates.
 */

/**
 *  Add new fields to store Text and Flash ads.
 *  Make Image Ad field to not required.
 */
function simpleads_update_7001(&$sandbox) {

  $fields = array(
    array(
      'field_name' => 'field_ad_flash',
      'type' => 'file',
      'cardinality' => 1,
      'translatable' => TRUE,
      'locked' => FALSE,
      'indexes' => array('fid' => array('fid')),
      'settings' => array(
        'uri_scheme' => 'public',
        'default_image' => FALSE,
      ),
      'storage' => array(
        'type' => 'field_sql_storage',
        'settings' => array(),
      ),
    ),
  );
  foreach ($fields as $field) {
    field_create_field($field);
  }

  $instance = array(
    'field_name' => 'field_ad_flash',
    'entity_type' => 'node',
    'label' => st('Flash Ad'),
    'bundle' => 'simpleads',
    'description' => st('Upload Flash file for this Ad.'),
    'required' => FALSE,

    'settings' => array(
      'file_directory' => 'field/flash',
      'file_extensions' => 'swf',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'alt_field' => FALSE,
      'title_field' => '',
    ),

    'widget' => array(
      'type' => 'file_generic',
      'settings' => array(
      ),
      'weight' => 0,
    ),

    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'type' => 'file_default',
        'weight' => -1,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'type' => 'file_default',
        'weight' => -1,
      ),
    ),
  );
  field_create_instance($instance);
  $instance = array(
    'field_name' => 'field_ad_image',
    'entity_type' => 'node',
    'label' => st('Ad Image'),
    'bundle' => 'simpleads',
    'description' => st('Upload an image for this Ad.'),
    'required' => FALSE,

    'settings' => array(
      'file_directory' => 'field/image',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'alt_field' => TRUE,
      'title_field' => '',
    ),

    'widget' => array(
      'type' => 'image_image',
      'settings' => array(
        'progress_indicator' => 'throbber',
        'preview_image_style' => 'thumbnail',
      ),
      'weight' => -2,
    ),

    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'type' => 'image',
        'settings' => array('image_style' => 'large', 'image_link' => ''),
        'weight' => -1,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'type' => 'image',
        'settings' => array('image_style' => 'medium', 'image_link' => 'content'),
        'weight' => -1,
      ),
    ),
  );
  field_update_instance($instance);

  $instance = array(
    'field_name' => 'field_ad_category',
    'entity_type' => 'node',
    'label' => st('Ad Group'),
    'bundle' => 'simpleads',
    'required' => TRUE,
    'widget' => array(
      'type' => 'options_select',
      'weight' => -4,
    ),
    'display' => array(
      'default' => array('type' => 'hidden'),
      'teaser' => array('type' => 'hidden')
    ),
  );
  field_update_instance($instance);

  $fields = array(
    array(
      'field_name' => 'field_ad_text',
      'type' => 'text',
      'cardinality' => 1,
      'translatable' => TRUE,
      'locked' => FALSE,
      'settings' => array(),
      'storage' => array(
        'type' => 'field_sql_storage',
        'settings' => array(),
      ),
    ),
  );
  foreach ($fields as $field) {
    field_create_field($field);
  }

  $instance = array(
    'field_name' => 'field_ad_text',
    'entity_type' => 'node',
    'label' => st('Text Ad'),
    'bundle' => 'simpleads',
    'description' => st('Enter your text Ad. If you would like to add embeded code or formatted text, please configure settings of this field on content type field settings page'),
    'required' => FALSE,

    'settings' => array(
      'rows' => 5,
      'text_processing' => 1,
    ),

    'widget' => array(
      'type' => 'text_textarea',
      'settings' => array(
      ),
      'weight' => 1,
      'module' => 'text',
    ),

    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'type' => 'text_default',
        'weight' => -1,
        'module' => 'text',
      ),
      'teaser' => array(
        'label' => 'hidden',
        'type' => 'text_default',
        'weight' => -1,
      ),
    ),
  );
  field_create_instance($instance);

  $fields = array(
    array(
      'field_name' => 'field_ad_type',
      'type' => 'list_text',
      'cardinality' => 1,
      'translatable' => TRUE,
      'locked' => FALSE,
      'module' => 'list',
      'settings' => array(
        'allowed_values' => array(
          'graphic' => st('Image Ad'),
          'text' => st('Text Ad'),
          'flash' => st('Flash Ad'),
        ),
        'allowed_values_function' => '',
      ),
      'storage' => array(
        'type' => 'field_sql_storage',
        'settings' => array(),
      ),
    ),
  );
  foreach ($fields as $field) {
    field_create_field($field);
  }

  $instance = array(
    'field_name' => 'field_ad_type',
    'entity_type' => 'node',
    'label' => st('Ad Type'),
    'bundle' => 'simpleads',
    'description' => st('Please select Ad type.'),
    'required' => TRUE,
    
    'default_value' => array(
      0 => array(
        'value' => 'graphic',
      ),
    ),
    'settings' => array(
      'allowed_values'  => array(
        'graphic' => st('Image Ad'),
        'text' => st('Text Ad'),
        'flash' => st('Flash Ad'),
      ),
      'user_register_form' => FALSE,
    ),
    'user_register_form' => FALSE,
    
    'widget' => array(
      'active' => 1,
      'type' => 'options_select',
      'weight' => -3,
      'module' => 'list',
    ),

    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'type' => 'list_default',
        'module' => 'list',
        'weight' => -1,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'type' => 'list_default',
        'module' => 'list',
        'weight' => -1,
      ),
    ),
  );
  field_create_instance($instance);
}

/**
 * Rearrange SimleAds fields.
 */
function simpleads_update_7002(&$sandbox) {

  user_role_grant_permissions(DRUPAL_ANONYMOUS_RID, array('count ad impressions', 'count ad clicks'));

  $instance = array(
    'field_name' => 'field_ad_flash',
    'entity_type' => 'node',
    'label' => st('Ad Flash'),
    'bundle' => 'simpleads',
    'description' => st('Upload Flash file for this Ad.'),
    'required' => FALSE,

    'settings' => array(
      'file_directory' => 'field/flash',
      'file_extensions' => 'swf',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'alt_field' => FALSE,
      'title_field' => '',
    ),

    'widget' => array(
      'type' => 'file_generic',
      'settings' => array(
      ),
      'weight' => -1,
    ),

    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'type' => 'file_default',
        'weight' => -1,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'type' => 'file_default',
        'weight' => -1,
      ),
    ),
  );
  field_update_instance($instance);

  $instance = array(
    'field_name' => 'field_ad_url',
    'entity_type' => 'node',
    'bundle' => 'simpleads',
    'label' => st('URL Address'),
    'required' => FALSE,
    'widget' => array(
      'type' => 'text_textfield',
      'settings' => array(
        'size' => 60,
      ),
      'weight' => 1,
    ),
    'settings' => array(
      'text_processing' => 0,
    ),
    'display' => array(
      'default' => array(
        'label' => 'above',
        'type' => 'text_default',
        'settings' => array(),
      ),
    ),
  );
  field_update_instance($instance);
}

/**
 * Modify block settings field.
 */
function simpleads_update_7003(&$sandbox) {
  db_change_field('simpleads_blocks', 'settings', 'settings', array('type' => 'text', 'not null' => TRUE, 'description' => 'Serialized data (settings)'));
  
  $instance = array(
    'field_name' => 'field_ad_text',
    'entity_type' => 'node',
    'label' => st('Text Ad'),
    'bundle' => 'simpleads',
    'description' => st('Enter your text Ad. If you would like to add embeded code or formatted text, please configure settings of this field on content type field settings page'),
    'required' => FALSE,

    'settings' => array(
      'rows' => 5,
      'text_processing' => 1,
    ),

    'widget' => array(
      'type' => 'text_textarea',
      'settings' => array(
      ),
      'weight' => 0,
      'module' => 'text',
    ),

    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'type' => 'text_default',
        'weight' => -1,
        'module' => 'text',
      ),
      'teaser' => array(
        'label' => 'hidden',
        'type' => 'text_default',
        'weight' => -1,
      ),
    ),
  );
  field_update_instance($instance);

  $instance = array(
    'field_name' => 'field_ad_url',
    'entity_type' => 'node',
    'bundle' => 'simpleads',
    'label' => st('URL Address'),
    'required' => FALSE,
    'widget' => array(
      'type' => 'text_textfield',
      'settings' => array(
        'size' => 60,
      ),
      'weight' => 1,
    ),
    'settings' => array(
      'text_processing' => 0,
    ),
    'display' => array(
      'default' => array(
        'label' => 'above',
        'type' => 'text_default',
        'settings' => array(),
      ),
    ),
  );
  field_update_instance($instance);
}