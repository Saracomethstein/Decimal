#include "../another_functions/s21_another_func.h"
#include "../tools/get/s21_get_tools.h"
#include "../tools/math_helper/s21_math_tools.h"
#include "../tools/set/s21_set_tools.h"
#include "s21_arithmetic_operators.h"

int check_add_overflow(s21_decimal val_1, s21_decimal val_2) {
  s21_decimal result = {0};
  return signed_addition(val_1, val_2, &result);
}

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int answer = s21_ArithmeticOK;
  int result_sign = s21_Positive;
  int result_degree = s21_MinDegree;
  int value_1_degree = get_decimal_power(value_1);
  int value_2_degree = get_decimal_power(value_2);
  int check_overflow = check_add_overflow(value_1, value_2);

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
      result_degree = find_common_denominator(&value_1, &value_2);
      result_sign = check_result_sign(value_1, value_2);
      answer = signed_addition(value_1, value_2, result);
      if (answer == s21_ArithmeticIsBig) {
        set_zero_decimal(result);
        if (result_sign == s21_Negative) {
          answer = s21_ArithmeticIsSmall;
        }
      }
    } else {
      answer = s21_ArithmeticNotCorrect;
      set_zero_decimal(result);
    }

    set_decimal_power(result, result_degree);
    set_decimal_sign(result, result_sign);
  }

  return answer;
}