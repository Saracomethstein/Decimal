#include "../operators_comparison//s21_operators_comparison.h"
#include "../tools/get/s21_get_tools.h"
#include "../tools/math_helper/s21_math_tools.h"
#include "../tools/set/s21_set_tools.h"
#include "s21_arithmetic_operators.h"

int check_mul_overflow(s21_decimal val_1, s21_decimal val_2) {
  int answer = s21_ArithmeticOK;
  s21_decimal result = {0};
  answer = mul_decimals(val_1, val_2, &result);
  return answer;
}

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int answer = s21_ArithmeticOK;
  int check_overflow = check_mul_overflow(value_1, value_2);
  int value_1_degree = get_decimal_power(value_1);
  int value_2_degree = get_decimal_power(value_2);
  int result_degree = value_1_degree + value_2_degree;

  if (!result) {
    answer = s21_ArithmeticNotCorrect;
  } else {
    set_zero_decimal(result);
    if ((value_1_degree <= s21_MaxDegree && value_2_degree <= s21_MaxDegree) &&
        (value_1_degree >= s21_MinDegree && value_2_degree >= s21_MinDegree)) {
      if (check_overflow == s21_ArithmeticIsBig) {
        bank(value_1, &value_1);
        bank(value_2, &value_2);
      }
      answer = signed_multiplication(value_1, value_2, result);
      if (answer == s21_ArithmeticIsBig) {
        set_zero_decimal(result);
        int sign = get_decimal_sign(*result);
        if (sign == s21_Negative) {
          answer = s21_ArithmeticIsSmall;
        }
      }
    } else {
      answer = s21_ArithmeticNotCorrect;
      set_zero_decimal(result);
    }

    if (result_degree > s21_MaxDegree) {
      answer = s21_ArithmeticNotCorrect;
      set_zero_decimal(result);
    } else {
      set_decimal_power(result, result_degree);
    }
  }

  return answer;
}