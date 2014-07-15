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
<?php print $link; ?>
<?php if ($custom_qty): ?>
<input class="qty_ctl" id="qty_ctl_<?php print $product_id; ?>" type="text" size="2" value="" type="number" min="1" max="999" placeholder="Qty" />
<?php endif; ?>
