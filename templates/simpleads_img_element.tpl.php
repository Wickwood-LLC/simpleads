<?php

/**
 * @file
 * SimpleAds Image ad.
 */

  $alt = check_plain($ad['alt']);
  $width = check_plain($settings['ads_width']);
  $height = check_plain($settings['ads_height']);

?>
<div class="simplead-container image-ad">
<a href="<?php print url($ad['url']); ?>" target="_blank">
  <img src="<?php print $ad['image']; ?>" alt="<?php print $alt; ?>" width="<?php print $width; ?>" height="<?php print $height; ?>" border="0">
</a>
</div>