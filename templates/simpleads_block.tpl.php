<?php

/**
 * @file
 * SimpleAds Block template
 *
 * Use Javascript code below when you enable caching,
 * otherwise it will be cached and rotating will not work.
 * 
 * $ads_page
 *   Url to Advertise page (configurable in block settings).
 *
 * $tid
 *   Term ID
 *
 * $prefix
 *   Unique number (to identify container for ads)
 *
 * $ads
 *   Array of Ads
 *
 * $ads_width
 *   Ad width
 *
 * $ads_height
 *   Ad height
 *
 * $ads_limit
 *   Numer of ads to dispaly
 *
 */

  $ad_setting = array(
    'ads_width' => check_plain($ads_width),
    'ads_height' => check_plain($ads_height),
  );

?>
<div class="header">
  <div class="ad-link"><?php if(!is_null($ads_page)) : print l(t('Advertise with us'), $ads_page); endif; ?></div>
</div>
<div class="adslist">
<!--
  <script type="text/javascript">
    // Consider using only one method (javascript or code below).
    _simpelads_load('#ads-<?php print $tid; ?><?php if ($prefix) : ?>-<?php print $prefix; ?><?php endif; ?>', <?php print $tid; ?>, <?php print check_plain($ads_limit); ?>);
  </script>
  <div id="ads-<?php print $tid; ?><?php if ($prefix) :?>-<?php print $prefix; ?><?php endif; ?>"></div>
  -->

  <?php if (count($ads) > 0) : ?>
    <?php foreach ($ads as $ad) : ?>
      <?php if ($ad['type'] == 'graphic') : ?>
        <?php print theme('simpleads_img_element', array('ad' => $ad, 'settings' => $ad_setting)); ?>
      <?php elseif ($ad['type'] == 'text') : ?>
        <?php print theme('simpleads_text_element', array('ad' => $ad, 'settings' => $ad_setting)); ?>
      <?php else : ?>
        <?php print theme('simpleads_flash_element', array('ad' => $ad, 'settings' => $ad_setting)); ?>
      <?php endif; ?>
    <?php endforeach; ?>
  <?php endif; ?>
  
</div>