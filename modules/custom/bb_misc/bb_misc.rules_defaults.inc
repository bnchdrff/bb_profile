<?php
/**
 * @file
 * bb_misc.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function bb_misc_default_rules_configuration() {
  $items = array();
  $items['commerce_checkout_order_email'] = entity_import('rules_config', '{ "commerce_checkout_order_email" : {
      "LABEL" : "Send an order notification e-mail",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "4",
      "OWNER" : "rules",
      "TAGS" : [ "Commerce Checkout" ],
      "REQUIRES" : [ "rules", "commerce_checkout" ],
      "ON" : { "commerce_checkout_complete" : [] },
      "DO" : [
        { "mail" : {
            "to" : [ "commerce-order:mail" ],
            "subject" : "Order [commerce-order:order-number] at [site:name]",
            "message" : "Thanks for your order [commerce-order:order-number] at [site:name].\\n\\nIf this is your first order with us, you will receive a separate e-mail with login instructions. You can view your order history with us at any time by logging into our website at:\\n\\n[site:login-url]\\n\\nYou can find the status of your current order at:\\n\\n[commerce-order:customer-url]\\n\\nPlease contact us if you have any questions about your order.",
            "from" : ""
          }
        }
      ]
    }
  }');
  $items['commerce_tax_rate_sample_michigan_sales_tax'] = entity_import('rules_config', '{ "commerce_tax_rate_sample_michigan_sales_tax" : {
      "LABEL" : "Calculate Sample Michigan Sales Tax 6%",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "commerce_order", "commerce_tax" ],
      "USES VARIABLES" : { "commerce_line_item" : { "label" : "Line item", "type" : "commerce_line_item" } },
      "IF" : [
        { "commerce_order_compare_address" : {
            "commerce_order" : [ "commerce-line-item:order" ],
            "address_field" : "commerce_customer_shipping|commerce_customer_address",
            "address_component" : "administrative_area",
            "value" : "MI"
          }
        }
      ],
      "DO" : [
        { "commerce_tax_rate_apply" : {
            "USING" : {
              "commerce_line_item" : [ "commerce-line-item" ],
              "tax_rate_name" : "sample_michigan_sales_tax"
            },
            "PROVIDE" : { "applied_tax" : { "applied_tax" : "Applied tax" } }
          }
        }
      ]
    }
  }');
  $items['rules_order_paid_in_full_order_state_to_processing'] = entity_import('rules_config', '{ "rules_order_paid_in_full_order_state_to_processing" : {
      "LABEL" : "Order paid in full: Order state to processing",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "1",
      "OWNER" : "rules",
      "REQUIRES" : [ "commerce_cart", "commerce_order", "commerce_payment" ],
      "ON" : { "commerce_payment_order_paid_in_full" : [] },
      "IF" : [
        { "NOT commerce_order_is_cart" : { "commerce_order" : [ "commerce_order" ] } }
      ],
      "DO" : [
        { "commerce_order_update_status" : { "commerce_order" : [ "commerce_order" ], "order_status" : "processing" } }
      ]
    }
  }');
  $items['rules_update_the_order_status_on_checkout_completion_if_payment_'] = entity_import('rules_config', '{ "rules_update_the_order_status_on_checkout_completion_if_payment_" : {
      "LABEL" : "Update the order status on checkout completion (if payment complete)",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "10",
      "OWNER" : "rules",
      "TAGS" : [ "Commerce Checkout" ],
      "REQUIRES" : [ "commerce_payment", "commerce_order", "commerce_checkout" ],
      "ON" : { "commerce_checkout_complete" : [] },
      "IF" : [
        { "commerce_payment_order_balance_comparison" : { "commerce_order" : [ "commerce_order" ], "value" : "0" } }
      ],
      "DO" : [
        { "commerce_order_update_status" : { "commerce_order" : [ "commerce_order" ], "order_status" : "processing" } }
      ]
    }
  }');
  return $items;
}
