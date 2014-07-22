(function($) {

Drupal.behaviors.cec_custom_qty = {
  attach: function(context, settings) {
    var $qty_ctl = $('.qty_ctl', context);
    var cb_context = {
      qty_ctl: $qty_ctl[0],
      max_qty: $('.field-name-commerce-product-limit-max .field-item').text() * 1
    };
    $qty_ctl.on('keydown keyup click input submit mouseenter', function(ev) {
      var qty = this.value;
      var $a = $(this).parent().parent().find('a.commerce_express_checkout').eq(0);
      var $a_href = $a.attr('href');
      $a.attr('href', $a_href.replace(/(.*commerce-express-checkout\/\d*)\/\d*/, '$1/' + qty));
    });
    $('a.increase_qty', context).on('click', null, cb_context, function(ev) {
      ev.preventDefault();
      ev.data.qty_ctl.value++;
      if (ev.data.qty_ctl.value > ev.data.max_qty) {
        ev.data.qty_ctl.value = ev.data.max_qty;
      }
      $(this).siblings('input.qty_ctl').click();
    });
    $('a.decrease_qty', context).on('click', null, cb_context, function(ev) {
      ev.preventDefault();
      ev.data.qty_ctl.value--;
      if (ev.data.qty_ctl.value < 1) {
        ev.data.qty_ctl.value = 1;
      }
      $(this).siblings('input.qty_ctl').click();
    });
  }
};

})(jQuery);
