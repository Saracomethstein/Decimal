#include "../../operators_comparison/operators_comparison.h"
#include "../get/get_tools.h"
#include "math_tools.h"

int add_decimals(decimal value_1, decimal value_2, decimal *result) {
  unsigned int carry = 0;
  int flag = ArithmeticOK;
  for (int i = 0; i <= 2; i++) {
    unsigned long long sum =
        (unsigned long long)value_1.bits[i] + value_2.bits[i] + carry;
    result->bits[i] = (unsigned int)sum;
    carry = sum >> 32;

    if (i == 2 && carry > ArithmeticOK) {
      flag = ArithmeticIsBig;
    }
  }
  return flag;
}

int signed_addition(decimal value_1, decimal value_2, decimal *result) {
  int value_1_sign = get_decimal_sign(value_1);
  int value_2_sign = get_decimal_sign(value_2);
  int flag = ArithmeticOK;
  if (value_1_sign == Positive && value_2_sign == Positive) {
    flag = add_decimals(value_1, value_2, result);
  } else if (value_1_sign == Positive && value_2_sign == Negative) {
    if (abs_greater(value_1, value_2))
      sub_decimals(value_1, value_2, result);
    else
      sub_decimals(value_2, value_1, result);
  } else if (value_1_sign == Negative && value_2_sign == Positive) {
    if (abs_greater(value_2, value_1))
      sub_decimals(value_2, value_1, result);
    else
      sub_decimals(value_1, value_2, result);
  } else if (value_1_sign == Negative && value_2_sign == Negative) {
    flag = add_decimals(value_1, value_2, result);
  }
  return flag;
}