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
  $items['commerce_checkout_bb_create_a_new_account_for_an_anonymous_order'] = entity_import('rules_config', '{ "commerce_checkout_bb_create_a_new_account_for_an_anonymous_order" : {
      "LABEL" : "Create a new account for an anonymous order (for paypal WPS)",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "2",
      "OWNER" : "rules",
      "TAGS" : [ "Commerce Checkout" ],
      "REQUIRES" : [ "rules", "commerce", "commerce_payment" ],
      "ON" : { "commerce_payment_order_paid_in_full" : [] },
      "IF" : [
        { "data_is" : { "data" : [ "commerce-order:uid" ], "value" : "0" } },
        { "NOT entity_exists" : {
            "type" : "user",
            "property" : "mail",
            "value" : [ "commerce-order:mail" ]
          }
        },
        { "data_is" : { "data" : [ "commerce-order:type" ], "value" : "commerce_order" } }
      ],
      "DO" : [
        { "entity_create" : {
            "USING" : {
              "type" : "user",
              "param_name" : [ "commerce-order:mail-username" ],
              "param_mail" : [ "commerce-order:mail" ]
            },
            "PROVIDE" : { "entity_created" : { "account_created" : "Created account" } }
          }
        },
        { "data_set" : { "data" : [ "account-created:status" ], "value" : 1 } },
        { "entity_save" : { "data" : [ "account-created" ], "immediate" : 1 } },
        { "entity_query" : {
            "USING" : {
              "type" : "user",
              "property" : "mail",
              "value" : [ "commerce-order:mail" ],
              "limit" : 1
            },
            "PROVIDE" : { "entity_fetched" : { "account_fetched" : "Fetched account" } }
          }
        },
        { "LOOP" : {
            "USING" : { "list" : [ "account-fetched" ] },
            "ITEM" : { "list_item" : "Current list item" },
            "DO" : [
              { "data_set" : { "data" : [ "commerce-order:uid" ], "value" : [ "list-item:uid" ] } },
              { "data_set" : {
                  "data" : [ "commerce-order:commerce-customer-billing:uid" ],
                  "value" : [ "list-item:uid" ]
                }
              },
              { "data_set" : {
                  "data" : [ "commerce-order:commerce-customer-shipping:uid" ],
                  "value" : [ "list-item:uid" ]
                }
              }
            ]
          }
        }
      ]
    }
  }');
  $items['commerce_checkout_completed_domestic_gift_order_notification'] = entity_import('rules_config', '{ "commerce_checkout_completed_domestic_gift_order_notification" : {
      "LABEL" : "Completed Domestic Gift Order - Send an order notification e-mail",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "4",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "commerce_order", "entity" ],
      "ON" : { "commerce_order_update" : [] },
      "IF" : [
        { "data_is" : { "data" : [ "commerce-order:status" ], "value" : "completed" } },
        { "NOT data_is" : { "data" : [ "commerce-order-unchanged:status" ], "value" : "completed" } },
        { "commerce_order_compare_address" : {
            "commerce_order" : [ "commerce_order" ],
            "address_field" : "commerce_customer_shipping|commerce_customer_address",
            "address_component" : "country",
            "value" : "US"
          }
        },
        { "entity_has_field" : { "entity" : [ "commerce-order" ], "field" : "field_gift_order" } },
        { "data_is" : { "data" : [ "commerce-order:field-gift-order" ], "value" : 1 } }
      ],
      "DO" : [
        { "mail" : {
            "to" : [ "commerce-order:mail" ],
            "subject" : "Order [commerce-order:order-number] at [site:name]",
            "message" : "Hi [commerce-order:commerce-customer-billing:commerce-customer-address:first_name], got this all packed up, will ship today!\\r\\n-Jon\\r\\n",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  $items['commerce_checkout_completed_domestic_normal_order_notification'] = entity_import('rules_config', '{ "commerce_checkout_completed_domestic_normal_order_notification" : {
      "LABEL" : "Completed Domestic Normal Order - Send an order notification e-mail",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "4",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "commerce_order", "entity" ],
      "ON" : { "commerce_order_update" : [] },
      "IF" : [
        { "data_is" : { "data" : [ "commerce-order:status" ], "value" : "completed" } },
        { "NOT data_is" : { "data" : [ "commerce-order-unchanged:status" ], "value" : "completed" } },
        { "commerce_order_compare_address" : {
            "commerce_order" : [ "commerce_order" ],
            "address_field" : "commerce_customer_shipping|commerce_customer_address",
            "address_component" : "country",
            "value" : "US"
          }
        },
        { "entity_has_field" : { "entity" : [ "commerce-order" ], "field" : "field_gift_order" } },
        { "data_is" : { "data" : [ "commerce-order:field-gift-order" ], "value" : 0 } }
      ],
      "DO" : [
        { "mail" : {
            "to" : [ "commerce-order:mail" ],
            "subject" : "Your Beard Balm has shipped!",
            "message" : "Hi [commerce-order:commerce-customer-billing:commerce-customer-address:first_name], got you all packed up, will ship today!\\r\\n\\r\\n-Jon\\r\\n\\r\\nPS: We\\u0027re just switching over our site and still working out some kinks, sorry for the wonky emails, feel free to write me directly if you have questions!",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  $items['commerce_checkout_intl_order_send_an_order_notification_email'] = entity_import('rules_config', '{ "commerce_checkout_intl_order_send_an_order_notification_email" : {
      "LABEL" : "International Order Completed - Send an order notification email",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "4",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "commerce_order", "entity" ],
      "ON" : { "commerce_order_update" : [] },
      "IF" : [
        { "data_is" : { "data" : [ "commerce-order:status" ], "value" : "completed" } },
        { "NOT data_is" : { "data" : [ "commerce-order-unchanged:status" ], "value" : "completed" } },
        { "NOT commerce_order_compare_address" : {
            "commerce_order" : [ "commerce_order" ],
            "address_field" : "commerce_customer_shipping|commerce_customer_address",
            "address_component" : "country",
            "value" : "US"
          }
        }
      ],
      "DO" : [
        { "mail" : {
            "to" : [ "commerce-order:mail" ],
            "subject" : "Your Beard Balm has shipped!",
            "message" : "Hi [commerce-order:commerce-customer-billing:commerce-customer-address:first_name], got you all packed up, will ship today!\\r\\n\\r\\nTrack your shipment: http:\\/\\/www.17track.net\\/en\\/result\\/post.shtml?nums=[commerce-order:field-customs-id]\\r\\n\\r\\n-Jon\\r\\n\\r\\nPS: We\\u0027re just switching over our site and still working out some kinks, sorry for the wonky emails, feel free to write me directly if you have questions!",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  $items['commerce_tax_rate_sample_michigan_sales_tax'] = entity_import('rules_config', '{ "commerce_tax_rate_sample_michigan_sales_tax" : {
      "LABEL" : "Calculate Sample Michigan Sales Tax 6%",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "commerce_order" ],
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
      "DO" : []
    }
  }');
  $items['rules_add_1_per_can'] = entity_import('rules_config', '{ "rules_add_1_per_can" : {
      "LABEL" : "Add $1 per can",
      "PLUGIN" : "reaction rule",
      "ACTIVE" : false,
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "commerce_line_item", "commerce_shipping" ],
      "ON" : { "commerce_shipping_calculate_rate" : [] },
      "DO" : [
        { "LOOP" : {
            "USING" : { "list" : [ "commerce-line-item:order:commerce-line-items" ] },
            "ITEM" : { "line_item" : "Line item" },
            "DO" : [
              { "data_calc" : {
                  "USING" : { "input_1" : [ "line-item:quantity" ], "op" : "*", "input_2" : "100" },
                  "PROVIDE" : { "result" : { "calculated_line_item_shipping" : "Calculated line item shipping" } }
                }
              },
              { "commerce_line_item_unit_price_add" : {
                  "commerce_line_item" : [ "commerce_line_item" ],
                  "amount" : [ "calculated-line-item-shipping" ],
                  "component_name" : "flat_rate_standard_global_shipping",
                  "round_mode" : "1"
                }
              }
            ]
          }
        }
      ]
    }
  }');
  $items['rules_notify_admin_on_order_cancellation'] = entity_import('rules_config', '{ "rules_notify_admin_on_order_cancellation" : {
      "LABEL" : "Notify admin on order cancellation",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "entity" ],
      "ON" : { "commerce_order_update" : [] },
      "IF" : [
        { "data_is" : { "data" : [ "commerce-order:status" ], "value" : "canceled" } },
        { "NOT data_is" : { "data" : [ "commerce-order-unchanged:status" ], "value" : "canceled" } }
      ],
      "DO" : [
        { "mail" : {
            "to" : "[site:mail]",
            "subject" : "Order [commerce-order:order-id] cancelled",
            "message" : "Order [commerce-order:order-id] was cancelled: [commerce-order:admin-url]",
            "from" : "[site:mail]",
            "language" : [ "" ]
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
  $items['rules_set_paid_in_full_for_no_payment_order'] = entity_import('rules_config', '{ "rules_set_paid_in_full_for_no_payment_order" : {
      "LABEL" : "set paid in full for no payment order",
      "PLUGIN" : "reaction rule",
      "ACTIVE" : false,
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "php", "commerce_checkout" ],
      "ON" : { "commerce_checkout_complete" : [] },
      "IF" : [
        { "data_is" : {
            "data" : [ "commerce-order:commerce-order-total:amount" ],
            "value" : "0"
          }
        }
      ],
      "DO" : [
        { "php_eval" : { "code" : "$payment_method = commerce_payment_method_instance_load(\\u0027commerce_payment_example|commerce_payment_commerce_payment_example\\u0027);\\r\\n\\r\\n\\/\\/ Creating new transaction via commerce_payment_example module.\\r\\n$charge = $commerce_order-\\u003Ecommerce_order_total[\\u0027und\\u0027][0];\\r\\n\\r\\n$transaction = commerce_payment_transaction_new(\\u0027commerce_payment_example\\u0027, $commerce_order-\\u003Eorder_id);\\r\\n$transaction-\\u003Einstance_id = $payment_method[\\u0027instance_id\\u0027];\\r\\n$transaction-\\u003Eamount = $charge[\\u0027amount\\u0027];\\r\\n$transaction-\\u003Ecurrency_code = $charge[\\u0027currency_code\\u0027];\\r\\n$transaction-\\u003Estatus = COMMERCE_PAYMENT_STATUS_SUCCESS;\\r\\n$transaction-\\u003Emessage = \\u0027Name: @name\\u0027;\\r\\n$transaction-\\u003Emessage_variables = array(\\u0027@name\\u0027 =\\u003E \\u0027Example payment\\u0027);\\r\\n\\r\\ncommerce_payment_transaction_save($transaction);\\r\\n\\r\\ncommerce_payment_commerce_payment_transaction_insert($transaction);\\r\\n\\r\\n\\/\\/ this would mark it as shipped:\\r\\n\\/\\/commerce_order_status_update($commerce_order, \\u0027completed\\u0027);" } }
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
