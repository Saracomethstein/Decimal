#include "operators_comparison.h"

int is_less_or_equal(decimal value_1, decimal value_2) {
  return is_less(value_1, value_2) || is_equal(value_1, value_2);
}

int abs_less_or_equal(decimal value_1, decimal value_2) {
  return abs_less(value_1, value_2) || abs_equal(value_1, value_2);
}
