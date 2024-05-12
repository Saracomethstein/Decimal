#include "../arithmetic_operators/s21_arithmetic_operators.h"
#include "../tools/math_helper/s21_math_tools.h"
#include "../tools/set/s21_set_tools.h"
#include "s21_another_func.h"

int s21_negate(s21_decimal value, s21_decimal *result) {
  int answer = s21_AnotherOK;
  int calc_answer = s21_ArithmeticOK;

  if (!result) {
    answer = s21_AnotherERROR;
  } else {
    set_zero_decimal(result);
    calc_answer = s21_mul(value, decimal_negative(), result);
    if (calc_answer != s21_ArithmeticOK) answer = s21_AnotherERROR;
  }

  return answer;
}