#include "../tools/get/s21_get_tools.h"
#include "s21_operators_comparison.h"

int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2) {
  int answer = s21_False;
  int v1_sign = get_decimal_sign(value_1);
  int v2_sign = get_decimal_sign(value_2);
  if ((value_1.bits[0] == 0 && value_1.bits[1] == 0 && value_1.bits[2] == 0) &&
      ((value_2.bits[0] == 0 && value_2.bits[1] == 0 &&
        value_2.bits[2] == 0))) {
    answer = s21_False;
  } else if (v1_sign != v2_sign)
    answer = s21_True;
  else {
    if (value_1.bits[0] != value_2.bits[0] ||
        value_1.bits[1] != value_2.bits[1] ||
        value_1.bits[2] != value_2.bits[2] ||
        value_1.bits[3] != value_2.bits[3])
      answer = s21_True;
  }
  return answer;
}

int s21_abs_not_equal(s21_decimal value_1, s21_decimal value_2) {
  int answer = s21_False;
  int v1_sign = get_decimal_sign(value_1);
  int v2_sign = get_decimal_sign(value_2);
  if (v1_sign != v2_sign)
    answer = s21_True;
  else {
    if (value_1.bits[0] != value_2.bits[0] ||
        value_1.bits[1] != value_2.bits[1] ||
        value_1.bits[2] != value_2.bits[2])
      answer = s21_True;
  }
  return answer;
}
