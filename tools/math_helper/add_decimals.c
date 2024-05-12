#include "../../operators_comparison/s21_operators_comparison.h"
#include "../get/s21_get_tools.h"
#include "s21_math_tools.h"

int add_decimals(s21_decimal value_1, s21_decimal value_2,
                 s21_decimal *result) {
  unsigned int carry = 0;
  int flag = s21_ArithmeticOK;
  for (int i = 0; i <= 2; i++) {
    unsigned long long sum =
        (unsigned long long)value_1.bits[i] + value_2.bits[i] + carry;
    result->bits[i] = (unsigned int)sum;
    carry = sum >> 32;

    if (i == 2 && carry > s21_ArithmeticOK) {
      flag = s21_ArithmeticIsBig;
    }
  }
  return flag;
}

int signed_addition(s21_decimal value_1, s21_decimal value_2,
                    s21_decimal *result) {
  int value_1_sign = get_decimal_sign(value_1);
  int value_2_sign = get_decimal_sign(value_2);
  int flag = s21_ArithmeticOK;
  if (value_1_sign == s21_Positive && value_2_sign == s21_Positive) {
    flag = add_decimals(value_1, value_2, result);
  } else if (value_1_sign == s21_Positive && value_2_sign == s21_Negative) {
    if (s21_abs_greater(value_1, value_2))
      sub_decimals(value_1, value_2, result);
    else
      sub_decimals(value_2, value_1, result);
  } else if (value_1_sign == s21_Negative && value_2_sign == s21_Positive) {
    if (s21_abs_greater(value_2, value_1))
      sub_decimals(value_2, value_1, result);
    else
      sub_decimals(value_1, value_2, result);
  } else if (value_1_sign == s21_Negative && value_2_sign == s21_Negative) {
    flag = add_decimals(value_1, value_2, result);
  }
  return flag;
}