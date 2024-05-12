#include "../../operators_comparison/operators_comparison.h"
#include "../get/get_tools.h"
#include "../set/set_tools.h"
#include "math_tools.h"

int mul_decimals(decimal value_1, decimal value_2, decimal *result) {
  int answer = ArithmeticOK;
  decimal copy = {0};
  set_zero_decimal(result);
  decimal_copy(value_2, &copy);

  for (int i = 0; i < BitsPowerAndSign; ++i) {
    if (get_decimal_bit(value_1, i) == 1) {
      left_shift(&copy, i);
      answer = add_decimals(*result, copy, result);
      decimal_copy(value_2, &copy);

      if (answer == ArithmeticIsBig) {
        set_zero_decimal(&value_1);
        break;
      }
    }
  }
  set_decimal_sign(result, Positive);
  if (answer == ArithmeticIsBig) set_zero_decimal(result);
  return answer;
}

int signed_multiplication(decimal value_1, decimal value_2, decimal *result) {
  int flag = ArithmeticOK;
  int value_1_sign = get_decimal_sign(value_1);
  int value_2_sign = get_decimal_sign(value_2);
  if (value_1_sign == Positive && value_2_sign == Positive) {
    flag = mul_decimals(value_1, value_2, result);
    set_decimal_sign(result, Positive);
  } else if (value_1_sign == Positive && value_2_sign == Negative) {
    flag = mul_decimals(value_1, value_2, result);
    set_decimal_sign(result, Negative);
  } else if (value_1_sign == Negative && value_2_sign == Positive) {
    flag = mul_decimals(value_1, value_2, result);
    set_decimal_sign(result, Negative);
  } else if (value_1_sign == Negative && value_2_sign == Negative) {
    flag = mul_decimals(value_1, value_2, result);
    set_decimal_sign(result, Positive);
  }
  return flag;
}

decimal mul_decimals_return(decimal value_1, decimal value_2, decimal result) {
  decimal res = {0};
  mul_decimals(value_1, value_2, &result);
  decimal_copy(result, &res);
  return result;
}