#include "../../operators_comparison/s21_operators_comparison.h"
#include "../get/s21_get_tools.h"
#include "../set/s21_set_tools.h"
#include "s21_math_tools.h"

int mul_decimals(s21_decimal value_1, s21_decimal value_2,
                 s21_decimal *result) {
  int answer = s21_ArithmeticOK;
  s21_decimal copy = {0};
  set_zero_decimal(result);
  decimal_copy(value_2, &copy);

  for (int i = 0; i < s21_BitsPowerAndSign; ++i) {
    if (get_decimal_bit(value_1, i) == 1) {
      left_shift(&copy, i);
      answer = add_decimals(*result, copy, result);
      decimal_copy(value_2, &copy);

      if (answer == s21_ArithmeticIsBig) {
        set_zero_decimal(&value_1);
        break;
      }
    }
  }
  set_decimal_sign(result, s21_Positive);
  if (answer == s21_ArithmeticIsBig) set_zero_decimal(result);
  return answer;
}

int signed_multiplication(s21_decimal value_1, s21_decimal value_2,
                          s21_decimal *result) {
  int flag = s21_ArithmeticOK;
  int value_1_sign = get_decimal_sign(value_1);
  int value_2_sign = get_decimal_sign(value_2);
  if (value_1_sign == s21_Positive && value_2_sign == s21_Positive) {
    flag = mul_decimals(value_1, value_2, result);
    set_decimal_sign(result, s21_Positive);
  } else if (value_1_sign == s21_Positive && value_2_sign == s21_Negative) {
    flag = mul_decimals(value_1, value_2, result);
    set_decimal_sign(result, s21_Negative);
  } else if (value_1_sign == s21_Negative && value_2_sign == s21_Positive) {
    flag = mul_decimals(value_1, value_2, result);
    set_decimal_sign(result, s21_Negative);
  } else if (value_1_sign == s21_Negative && value_2_sign == s21_Negative) {
    flag = mul_decimals(value_1, value_2, result);
    set_decimal_sign(result, s21_Positive);
  }
  return flag;
}

s21_decimal mul_decimals_return(s21_decimal value_1, s21_decimal value_2,
                                s21_decimal result) {
  s21_decimal res = {0};
  mul_decimals(value_1, value_2, &result);
  decimal_copy(result, &res);
  return result;
}