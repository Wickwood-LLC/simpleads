<?php

/**
 * @file
 * SimpleAds Integration with other contributed modules.
 */

/**
 * Implements hook_views_api().
 */
function simpleads_views_api() {
  return array(
    'api' => 3,
    'path' => drupal_get_path('module', 'simpleads') . '/includes',
    'template path' => drupal_get_path('module', 'simpleads') . '/templates',
  );
}

/**
 * Implements hook_views_plugins().
 */
function simpleads_views_plugins() {
  return array(
    'style' => array( //declare the views_json style plugin
      'simpleads' => array(
        'title' => t('SimpleAds'),
        'help' => t('Displays ads in block'),
        'handler' => 'views_simpleads_plugin',
        'theme' => 'views_simpleads',
        'theme path' => drupal_get_path('module', 'simpleads') . '/templates',
        'theme file' => 'views-simpleads.tpl.php',
        'uses row plugin' => FALSE,
        'uses fields' => TRUE,
        'uses options' => TRUE,
        'type' => 'normal',
      ),
    ),
  );
}

/**
 * Implements hook_views_default_views().
 */
function simpleads_views_default_views() {
  $view = new view;
  $view->name = 'simpleads_block_example';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'SimpleAds Block Example';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = TRUE;

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'SimpleAds Block Example';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'simpleads';
  $handler->display->display_options['style_options']['ads_rotation_type'] = '1';
  $handler->display->display_options['style_options']['ads_rotation_delay'] = '5';
  /* Field: Content: Ad Group */
  $handler->display->display_options['fields']['field_ad_category']['id'] = 'field_ad_category';
  $handler->display->display_options['fields']['field_ad_category']['table'] = 'field_data_field_ad_category';
  $handler->display->display_options['fields']['field_ad_category']['field'] = 'field_ad_category';
  $handler->display->display_options['fields']['field_ad_category']['label'] = '';
  $handler->display->display_options['fields']['field_ad_category']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_ad_category']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_ad_category']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_ad_category']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_ad_category']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_ad_category']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_ad_category']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_ad_category']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_ad_category']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_ad_category']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_ad_category']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_ad_category']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_ad_category']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ad_category']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_ad_category']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_ad_category']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_ad_category']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_ad_category']['field_api_classes'] = 0;
  /* Sort criterion: Global: Random */
  $handler->display->display_options['sorts']['random']['id'] = 'random';
  $handler->display->display_options['sorts']['random']['table'] = 'views';
  $handler->display->display_options['sorts']['random']['field'] = 'random';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'simpleads' => 'simpleads',
  );
  /* Filter criterion: Content: Status (field_ad_status) */
  $handler->display->display_options['filters']['field_ad_status_value']['id'] = 'field_ad_status_value';
  $handler->display->display_options['filters']['field_ad_status_value']['table'] = 'field_data_field_ad_status';
  $handler->display->display_options['filters']['field_ad_status_value']['field'] = 'field_ad_status_value';
  $handler->display->display_options['filters']['field_ad_status_value']['value'] = array(
    1 => '1',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['block_description'] = 'Views: SimpleAds Block Example';

  $views[$view->name] = $view;
  return $views;
}