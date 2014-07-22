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
<div class="qtl_ctl_widget">
  <a class="increase_qty" href="#">&uarr;</a>
  <input class="qty_ctl" id="qty_ctl_<?php print $product_id; ?>" type="text" size="2" value="1" type="number" min="1" max="999" placeholder="Qty" />
  <a class="decrease_qty" href="#">&darr;</a>
</div>
<?php endif; ?>
<a class="commerce_express_checkout" href="<?php print $path; ?>">ORDER</a>
