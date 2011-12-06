<?php

/**
 * @file
 * SimpleAds Block template
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

?>
<div class="header">
  <div class="ad-link"><?php if(!is_null($ads_page)) : print l(t('Advertise with us'), $ads_page); endif; ?></div>
</div>
<div class="adslist">
  
  <script type="text/javascript">
    _simpelads_load('#ads-<?php print $tid; ?><?php if ($prefix) : ?>-<?php print $prefix; ?><?php endif; ?>', <?php print $tid; ?>, <?php print check_plain($ads_limit); ?>);
  </script>
  <div id="ads-<?php print $tid; ?><?php if ($prefix) :?>-<?php print $prefix; ?><?php endif; ?>"></div>
  
  <noscript>
  <?php if (count($ads) > 0) : ?>
    <?php foreach ($ads as $ad) : ?>
      <a href="<?php print url($ad['url']); ?>" target="_blank"><img src="<?php print $ad['image']; ?>" width="<?php print check_plain($ads_width); ?>" height="<?php print check_plain($ads_height); ?>" alt="<?php print check_plain($ad['alt']); ?>" border="0"></a>
    <?php endforeach; ?>
  <?php endif; ?>
  </noscript>
  
</div>