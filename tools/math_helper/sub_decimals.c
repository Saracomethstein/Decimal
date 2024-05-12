#include "../../operators_comparison/operators_comparison.h"
#include "../get/get_tools.h"
#include "../set/set_tools.h"
#include "math_tools.h"

void sub_decimals(decimal value_1, decimal value_2, decimal *result) {
  set_zero_decimal(result);
  int res = 0;
  int carry = 0;
  int size_dec = BitsPowerAndSign - 1;
  while (get_decimal_bit(value_1, size_dec) != 1) {
    size_dec--;
  }
  for (int i = 0; i <= size_dec; i++) {
    int x = (int)get_decimal_bit(value_1, i);
    int y = (int)get_decimal_bit(value_2, i);
    res = x - y - carry;
    if (res < 0) {
      carry = 1;
    } else {
      carry = 0;
    }
    res = abs(res);
    set_decimal_bit(result, i, res % 2);
  }
}

int signed_subtraction(decimal value_1, decimal value_2, decimal *result) {
  int v1_sign = get_decimal_sign(value_1);
  int v2_sign = get_decimal_sign(value_2);
  int answer = ArithmeticOK;

  if (v1_sign != v2_sign) {
    set_decimal_sign(&value_1, Positive);
    set_decimal_sign(&value_2, Positive);
    answer = add_decimals(value_1, value_2, result);
    if (answer == ArithmeticOK) {
      if (v1_sign == Positive && v2_sign == Negative)
        set_decimal_sign(result, Positive);
      else
        set_decimal_sign(result, Negative);
    } else {
      set_zero_decimal(result);
      set_decimal_sign(result, Positive);
    }
  } else {
    if (v1_sign == Positive) {
      if (is_greater_or_equal(value_1, value_2)) {
        sub_decimals(value_1, value_2, result);
        set_decimal_sign(result, Positive);
      } else {
        sub_decimals(value_2, value_1, result);
        set_decimal_sign(result, Negative);
      }
    } else {
      if (abs_greater(value_1, value_2)) {
        sub_decimals(value_1, value_2, result);
        set_decimal_sign(result, Negative);
      } else {
        sub_decimals(value_2, value_1, result);
        set_decimal_sign(result, Positive);
      }
    }
  }
  return answer;
}