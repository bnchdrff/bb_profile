(function($) {

Drupal.behaviors.cec_custom_qty = {
  attach: function(context, settings) {
    $('.qty_ctl', context).on('keydown keyup click input submit mouseenter', function(ev) {
      var qty = this.value;
      var $a = $(this).siblings('a').eq(0);
      var $a_href = $a.attr('href');
      $a.attr('href', $a_href.replace(/(.*commerce-express-checkout\/\d*)\/\d*/, '$1/' + qty));
    });
  }
};

})(jQuery);
