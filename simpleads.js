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
      var ad_block_limit = $('form#block-admin-configure #edit-ads-limit').val();
      _simpelads_switch_block_settings(ad_block_limit, false);
      $('form#block-admin-configure #edit-ads-limit').change(function(){
        _simpelads_switch_block_settings($(this).val(), false);
      });
      var ad_block_rotation_type = $('form#block-admin-configure #edit-ads-rotation-type').val();
      _simpelads_switch_block_settings(ad_block_rotation_type, 'delay');
      $('form#block-admin-configure #edit-ads-rotation-type').change(function(){
        _simpelads_switch_block_settings($(this).val(), 'delay');
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
      $('form#simpleads-node-form #edit-field-ad-url').show();
      $('form#simpleads-node-form #edit-field-ad-flash').show();
      $('form#simpleads-node-form #edit-field-ad-text').hide();
    }
  }(jQuery));
}

/**
 * Show/hide block settings.
 */
function _simpelads_switch_block_settings(ad_setting_value, setting) {
  (function ($) {
    if (setting == false) {
      if (ad_setting_value != 1)
        $('form#block-admin-configure #ads_rotation_settings').show();
      else
        $('form#block-admin-configure #ads_rotation_settings').hide();
    }
    else {
      if (setting == 'delay') {
        if (ad_setting_value == 0)
          $('form#block-admin-configure #ads_rotation_settings .form-item-ads-rotation-delay').hide();
        else
          $('form#block-admin-configure #ads_rotation_settings .form-item-ads-rotation-delay').show();
      }
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

/**
 * jQuery Plugin.
 * SimpleAds rotator.
 */
(function ($) {
  $.simpleads_globals = {
    pos: []
  };
  $.simpleads_rotator = function(element, options) {
    this.options = {};
    element.data('simpleads_rotator', this);
    this.init = function (element, options) {
      this.options = $.extend({}, $.simpleads_rotator.defaultOptions, options);
      $.simpleads_globals.pos[options.tid] = 0;
      simpleads_start(element, this.options);
    };
    this.init(element, options);
  };

  $.fn.simpleads_rotator = function(options) {
    return this.each(function(){
      (new $.simpleads_rotator($(this), options));
    });
  }

  function get_random(total_ads) {
    return Math.floor(Math.random() * total_ads) + 1;
  }

  function run_rotation(element, options) {
    elem_id = element.attr('id');
    var temp = '';
    total_ads = $('#' + elem_id + " > div").size();
    if ($.simpleads_globals.pos[options.tid] == (total_ads - 1)) {
      $.simpleads_globals.pos[options.tid] = 0;
    }
    else {
      $.simpleads_globals.pos[options.tid]++;
    }

    $('#' + elem_id + " div").hide();
    var simpleads_elem = $('#' + elem_id + " > div:eq(" + $.simpleads_globals.pos[options.tid] + ")");
    
    if (options.rotation_type == 1) {
      simpleads_elem.show();
    }
    else if (options.rotation_type == 2) {
      simpleads_elem.fadeIn('fast');
    }
    else {
      simpleads_elem.show();
    }
    return false;
  }

  function simpleads_start(element, options) {
    run_rotation(element, options); 
    setInterval(function(){run_rotation(element, options);}, options.delay);
  };

  $.simpleads_rotator.defaultOptions = {
    rotation_type: 1,
    delay: 5,
    tid: 0
  };

}(jQuery));