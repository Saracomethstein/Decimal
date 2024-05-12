#include "../tools/get/s21_get_tools.h"
#include "s21_operators_comparison.h"

int s21_is_less(s21_decimal value_1, s21_decimal value_2) {
  int answer;
  if ((value_1.bits[0] == 0 && value_1.bits[1] == 0 && value_1.bits[2] == 0) &&
      ((value_2.bits[0] == 0 && value_2.bits[1] == 0 &&
        value_2.bits[2] == 0))) {
    answer = s21_False;
  } else
    answer = !s21_is_greater_or_equal(value_1, value_2);
  return answer;
}

int s21_abs_less(s21_decimal value_1, s21_decimal value_2) {
  int answer = s21_False;
  int v1_sign = get_decimal_sign(value_1);
  int v2_sign = get_decimal_sign(value_2);
  if (v1_sign == v2_sign) {
    for (int i = 2; i >= 0; i--) {
      if (value_1.bits[i] < value_2.bits[i]) {
        if (v1_sign == s21_Negative)
          answer = s21_False;
        else
          answer = s21_True;
        break;
      } else if (value_1.bits[i] > value_2.bits[i]) {
        if (v1_sign == s21_Negative)
          answer = s21_False;
        else
          answer = s21_True;
        break;
      }
    }
  } else if (v1_sign == s21_Negative && v2_sign == s21_Positive)
    answer = s21_True;
  else
    answer = s21_False;
  return answer;
}
