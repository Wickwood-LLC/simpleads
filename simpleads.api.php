<?php

/**
 * @file
 * SimpleAds API.
 */

/**
 *
 */
function hook_simpleads_order_info() {
  return array(
    'delta_1' => t('Random order'),
  );
}

/**
 *
 * @param string $delta
 * @param array $term_ids
 * @param int $limit
 * @return type
 */
function hook_simpleads_order($delta, $term_ids, $limit) {
  if ($delta == 'delta_1') {
    $query = db_select('node', 'n');
    $query->join('taxonomy_index', 'ti', 'n.nid = ti.nid');
    $query->fields('n', array('nid'));
    $query->condition('n.type', 'simpleads');
    $query->condition('ti.tid', $term_ids, 'IN');
    $query->orderRandom();
    $query->range(0, $limit);
    return $query->execute();
  }
}

/**
 *
 */
function hook_simpleads_integrate() {
  return array(
    'domain' => array(
      'description' => t('Integration with Domain Access module'),
    ),
  );
}

/**
 *
 * @global object $user
 * @param string $delta
 * @param object $node
 * @return object or FALSE if no access to a node.
 */
function hook_simpleads_access_node($delta, $node) {
  global $user;
  if ($delta == 'domain') {
    if (module_exists('domain')) {
      if (user_access('publish to any assigned domain')) {
        $user_domains = domain_get_user_domains($user);
        if (isset($node->domains) && _simpleads_array_in_array(array_values($user_domains), array_values($node->domains))) {
          return $node;
        }
        else {
          return FALSE;
        }
      }
      else {
        return $node;
      }
    }
  }
}

/**
 *
 * @param string $delta
 * @param array $info
 * @param object $node
 */
function hook_simpleads_stats_alter($delta, $node) {
  $output = array();
  if ($delta == 'domain') {
    if (module_exists('domain')) {
      $_domain = domain_get_domain();
      $gid = ($_domain['domain_id'] == 0) ? 1 : $_domain['domain_id'];
      $domain_name = isset($node->domain_site) ? join(", ", $node->subdomains) : '';
      if ($node->domain_site == $gid) {
        $output[] = '<span><b>' . t('Domain(s)') . ':</b> ' . check_plain($domain_name) . '</span>';
      }
    }
  }
  return $output;
}