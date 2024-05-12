#include "../tools/get/s21_get_tools.h"
#include "../tools/math_helper/s21_math_tools.h"
#include "s21_operators_comparison.h"

int s21_abs_greater(s21_decimal value_1, s21_decimal value_2) {
  int answer = s21_False;
  for (int i = 2; i >= 0; i--) {
    if (value_1.bits[i] < value_2.bits[i]) {
      answer = s21_False;
      break;
    } else if (value_1.bits[i] > value_2.bits[i]) {
      answer = s21_True;
      break;
    }
  }
  return answer;
}

int s21_is_greater(s21_decimal value_1, s21_decimal value_2) {
  int answer = s21_False;
  int v1_sign = get_decimal_sign(value_1);
  int v2_sign = get_decimal_sign(value_2);

  find_common_denominator(&value_1, &value_2);

  if ((value_1.bits[0] == 0 && value_1.bits[1] == 0 && value_1.bits[2] == 0) &&
      ((value_2.bits[0] == 0 && value_2.bits[1] == 0 &&
        value_2.bits[2] == 0))) {
    answer = s21_False;
  } else if (v1_sign == s21_Positive && v1_sign == v2_sign) {
    for (int i = 2; i >= 0; --i) {
      if (value_1.bits[i] > value_2.bits[i]) {
        answer = s21_True;
        break;
      } else if (value_1.bits[i] < value_2.bits[i]) {
        answer = s21_False;
        break;
      } else
        continue;
    }
  } else if (v1_sign == s21_Negative && v1_sign == v2_sign) {
    for (int i = 2; i >= 0; --i) {
      if (value_1.bits[i] < value_2.bits[i]) {
        answer = s21_True;
        break;
      } else if (value_1.bits[i] > value_2.bits[i]) {
        answer = s21_False;
        break;
      } else
        continue;
    }
  } else if (v1_sign != v2_sign) {
    if (v1_sign == s21_Negative)
      answer = s21_False;
    else
      answer = s21_True;
  }
  return answer;
}