#include "../../operators_comparison/operators_comparison.h"
#include "../get/get_tools.h"
#include "math_tools.h"

int check_result_sign(decimal value_1, decimal value_2) {
  int result_sign = 0;
  int value_1_sign = get_decimal_sign(value_1);
  int value_2_sign = get_decimal_sign(value_2);

  if (value_1_sign == Negative && value_2_sign == Negative) {
    result_sign = Negative;
  } else {
    if (value_1_sign == Negative && value_2_sign == Positive) {
      if (is_less(value_1, value_2) == True) {
        result_sign = Positive;
      } else {
        result_sign = Negative;
      }
    } else if (value_1_sign == Positive && value_2_sign == Negative) {
      if (is_less(value_1, value_2) == True) {
        result_sign = Negative;
      } else {
        result_sign = Positive;
      }
    }
  }
  return result_sign;
}