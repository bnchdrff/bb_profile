<?php
/**
 * @file
 * Default theme implementation for express checkout link
 *
 * Available variables:
 * - $link: The whole link.
 * - $product_id: Product ID for which this checkout link is built.
 * - $path: Path to express checkout of product.
 * - $custom_qty: Whether or not to allow custom quantity.
 */
?>

<?php if ($custom_qty): ?>
<span class="qtl_ctl_widget">
  <a class="increase_qty glyphicon glyphicon-arrow-up" href="#"></a>
  <input class="qty_ctl" id="qty_ctl_<?php print $product_id; ?>" type="text" size="2" value="1" type="number" min="1" max="999" placeholder="Qty" />
  <a class="decrease_qty glyphicon glyphicon-arrow-down" href="#"></a>
</span>
<?php endif; ?>
<a type="button" class="btn btn-default btn-lg commerce_express_checkout" href="/<?php print $path; ?>">ORDER</a>
<span class="qty_delivered_wrap">Delivered for just $<span class="qty_delivered">19</span></span>
<div class="qty_error"></div>
