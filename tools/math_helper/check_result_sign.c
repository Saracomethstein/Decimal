#include "../../operators_comparison/s21_operators_comparison.h"
#include "../get/s21_get_tools.h"
#include "s21_math_tools.h"

int check_result_sign(s21_decimal value_1, s21_decimal value_2) {
  int result_sign = 0;
  int value_1_sign = get_decimal_sign(value_1);
  int value_2_sign = get_decimal_sign(value_2);

  if (value_1_sign == s21_Negative && value_2_sign == s21_Negative) {
    result_sign = s21_Negative;
  } else {
    if (value_1_sign == s21_Negative && value_2_sign == s21_Positive) {
      if (s21_is_less(value_1, value_2) == s21_True) {
        result_sign = s21_Positive;
      } else {
        result_sign = s21_Negative;
      }
    } else if (value_1_sign == s21_Positive && value_2_sign == s21_Negative) {
      if (s21_is_less(value_1, value_2) == s21_True) {
        result_sign = s21_Negative;
      } else {
        result_sign = s21_Positive;
      }
    }
  }
  return result_sign;
}