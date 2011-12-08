/**
 * @file
 * SimpleAds JS Helper.
 */

(function ($) {
  Drupal.behaviors.simpleads = {
    attach: function(context) {
      var ad_type = $('#edit-field-ad-type select[id^=edit-field-ad-type]').val();
      _simpelads_switch_form(ad_type);
      $('#edit-field-ad-type select[id^=edit-field-ad-type]').change(function(){
        _simpelads_switch_form($(this).val());
      });
    }
  };
}(jQuery));

/**
 * Show/hide form elements.
 */
function _simpelads_switch_form(ad_type) {
  (function ($) {
    if (ad_type == 'graphic') {
      $('form#simpleads-node-form #edit-field-ad-image').show();
      $('form#simpleads-node-form #edit-field-ad-url').show();
      $('form#simpleads-node-form #edit-field-ad-flash').hide();
      $('form#simpleads-node-form #edit-field-ad-text').hide();
    }
    else if (ad_type == 'text') {
      $('form#simpleads-node-form #edit-field-ad-image').hide();
      $('form#simpleads-node-form #edit-field-ad-url').hide();
      $('form#simpleads-node-form #edit-field-ad-flash').hide();
      $('form#simpleads-node-form #edit-field-ad-text').show();
    }
    else if (ad_type == 'flash') {
      $('form#simpleads-node-form #edit-field-ad-image').hide();
      $('form#simpleads-node-form #edit-field-ad-url').hide();
      $('form#simpleads-node-form #edit-field-ad-flash').show();
      $('form#simpleads-node-form #edit-field-ad-text').hide();
    }
  }(jQuery));
}

/**
 * Ajax call for Ads.
 * elem - Ad container
 * tid  - term id
 * num - numer of ads to display
 * img_loader - image (ad load indicator), should be HTML tag <img src="loader.gif">
 */
function _simpelads_load(elem, tid, num, img_loader) {
  (function ($) {
    basepath = Drupal.settings.basePath;
    if (tid > 0 && num > 0) {
      if (img_loader != '')
        $(elem).html(img_loader);
      $.get(basepath + 'simpleads/load/' + tid + '/' + num, function (data) {
        $(elem).html(data);
      });
    }
  }(jQuery));
}