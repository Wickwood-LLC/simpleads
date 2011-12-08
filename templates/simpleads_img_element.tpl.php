<?php

/**
 * @file
 * SimpleAds Image ad.
 */
?>
<a href="<?php print url($ad['url']); ?>" target="_blank">
  <img src="<?php print $ad['image']; ?>" alt="<?php print check_plain($ad['alt']); ?>" width="<?php print check_plain($settings['ads_width']); ?>" height="<?php print check_plain($settings['ads_height']); ?>" border="0">
</a>