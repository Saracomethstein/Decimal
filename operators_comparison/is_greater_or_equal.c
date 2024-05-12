#include "operators_comparison.h"

int is_greater_or_equal(decimal value_1, decimal value_2) {
  return is_greater(value_1, value_2) || is_equal(value_1, value_2);
}

int abs_greater_or_equal(decimal value_1, decimal value_2) {
  return abs_greater(value_1, value_2) || abs_equal(value_1, value_2);
}
