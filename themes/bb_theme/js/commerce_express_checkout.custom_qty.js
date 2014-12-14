(function($) {

Drupal.behaviors.cec_custom_qty = {
  attach: function(context, settings) {
    'use strict'; // limit scope of eval()ed code
    var $qty_ctl = $('.qty_ctl', context);
    var $qty_delivered = $('.qty_delivered', context);
    var $qty_error = $('.qty_error', context);
    var price_check = function price_check(num_cans) {
      return eval($qty_delivered.data('calc'));
    };

    var cb_context = {
      qty_ctl: $qty_ctl[0],
      qty_delivered: $qty_delivered[0],
      qty_error: $qty_error[0],
      max_qty: $('.field-name-commerce-product-limit-max .field-item').text() * 1
    };

    $qty_ctl.on('keydown keyup click input submit mouseenter', null, cb_context, function(ev) {
      if (ev.data.qty_ctl.value > ev.data.max_qty) {
        ev.data.qty_ctl.value = ev.data.max_qty;
      }
      if (ev.data.qty_ctl.value < 12) {
        ev.data.qty_ctl.value = 12;
      }
      if (ev.data.qty_ctl.value == ev.data.max_qty) {
        ev.data.qty_error.innerHTML = 'If you want more than ' + ev.data.max_qty + ' cans, <a href="mailto:admin@beardbalm.us">email us!</a>';
      }
      if (ev.data.qty_ctl.value < ev.data.max_qty) {
        ev.data.qty_error.innerHTML = '';
      }
      var $a = $(this).parent().parent().find('a.commerce_express_checkout').eq(0);
      var $a_href = $a.attr('href');
      $a.attr('href', $a_href.replace(/(.*commerce-express-checkout\/\d*)\/\d*/, '$1/' + ev.data.qty_ctl.value));
      ev.data.qty_delivered.innerHTML = price_check(ev.data.qty_ctl.value*1);
    });

    $('a.increase_qty', context).on('click', null, cb_context, function(ev) {
      ev.preventDefault();
      ev.data.qty_ctl.value = parseInt(ev.data.qty_ctl.value) + 12;
      $(this).siblings('input.qty_ctl').click();
    });

    $('a.decrease_qty', context).on('click', null, cb_context, function(ev) {
      ev.preventDefault();
      ev.data.qty_ctl.value = parseInt(ev.data.qty_ctl.value) - 12;
      $(this).siblings('input.qty_ctl').click();
    });

    // set default qty
    $qty_ctl.val(12).click();
  }
};

})(jQuery);
