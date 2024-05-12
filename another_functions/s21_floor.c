#include "../arithmetic_operators/s21_arithmetic_operators.h"
#include "../tools/get/s21_get_tools.h"
#include "../tools/math_helper/s21_math_tools.h"
#include "../tools/set/s21_set_tools.h"
#include "s21_another_func.h"

int s21_floor(s21_decimal value, s21_decimal *result) {
  int answer = s21_AnotherOK;

  if (!result) {
    answer = s21_AnotherERROR;
  } else {
    s21_decimal fractional = {{0, 0, 0, 0}};
    s21_decimal value_after_trunc = {{0, 0, 0, 0}};
    set_zero_decimal(result);
    int sign = get_decimal_sign(value);
    set_decimal_sign(&value, s21_Positive);
    s21_truncate(value, &value_after_trunc);
    if (sign == s21_Positive) {
      s21_sub(value, value_after_trunc, &fractional);
      decimal_copy(value_after_trunc, result);
    } else {
      set_decimal_sign(&value_after_trunc, s21_Positive);
      s21_add(value_after_trunc, decimal_one(), result);
    }
    set_decimal_sign(result, sign);
    set_decimal_power(result, s21_MinDegree);
  }
  return answer;
}
