@api
Feature: Fulfil Orders
  In order to manage order statuses for shippable orders
  As an order fulfiller
  I need to be able to view "processing" orders and mark them as "completed"

  Background:
    Given customers:
      | name     | status | shipping address | previous orders |
      | Bobart   | 1      | domestic         | 0               |
      | Bilberto | 1      | international    | 0               |
      | Tom      | 1      | domestic         | 1               |
      | Tomas    | 1      | international    | 1               |
    And orders:
      | qty | status     | customer |
      | 10  | processing | Bobart   |
      | 9   | processing | Bilberto |
      | 8   | processing | Tom      |
      | 7   | processing | Tomas    |
      | 6   | completed  | Bobart   |
      | 5   | pending    | Tomas    |

  Scenario: View
    When I visit the /admin/commerce/orders/fulfill_international
    I should see a table with 10 orders,
    and each row should have a Quick Edit" link and a checkbox,
    and when I check 3 of the orders and select the "Set Order Status : Completed" option from the "Bulk Operations" dropdown and press "Apply",
    I should see a table with 7 orders.

