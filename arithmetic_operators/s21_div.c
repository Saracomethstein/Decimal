#include "../operators_comparison//s21_operators_comparison.h"
#include "../tools/get/s21_get_tools.h"
#include "../tools/math_helper/s21_math_tools.h"
#include "../tools/set/s21_set_tools.h"
#include "s21_arithmetic_operators.h"

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int answer = s21_ArithmeticOK;
  int overflow = s21_ArithmeticOK;
  int value_1_degree = get_decimal_power(value_1);
  int value_2_degree = get_decimal_power(value_2);

  if (!result) {
    answer = s21_ArithmeticNotCorrect;
  } else {
    if (value_2.bits[0] == 0 && value_2.bits[1] == 0 && value_2.bits[2] == 0) {
      answer = s21_ArithmeticDivByZero;
      set_zero_decimal(result);
      set_decimal_sign(result, 0);
    } else {
      set_zero_decimal(result);
      if ((value_1_degree <= s21_MaxDegree &&
           value_2_degree <= s21_MaxDegree) &&
          (value_1_degree >= s21_MinDegree &&
           value_2_degree >= s21_MinDegree)) {
        if (value_1.bits[0] == 0 && value_1.bits[1] == 0 &&
            value_1.bits[2] == 0) {
          set_decimal_sign(&value_2, s21_Positive);
          set_zero_decimal(result);
          set_decimal_power(result, s21_MinDegree);
          answer = s21_ArithmeticOK;
        } else {
          overflow = signed_division(value_1, value_2, result);
          if (overflow == s21_ArithmeticIsBig) {
            answer = s21_ArithmeticIsBig;
          }
        }
      } else {
        answer = s21_ArithmeticNotCorrect;
        set_zero_decimal(result);
      }
    }
  }
  return answer;
}