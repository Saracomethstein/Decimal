#include "../operators_comparison//operators_comparison.h"
#include "../tools/get/get_tools.h"
#include "../tools/math_helper/math_tools.h"
#include "../tools/set/set_tools.h"
#include "arithmetic_operators.h"

int check_mul_overflow(decimal val_1, decimal val_2) {
  int answer = ArithmeticOK;
  decimal result = {0};
  answer = mul_decimals(val_1, val_2, &result);
  return answer;
}

int mul_dec(decimal value_1, decimal value_2, decimal *result) {
  int answer = ArithmeticOK;
  int check_overflow = check_mul_overflow(value_1, value_2);
  int value_1_degree = get_decimal_power(value_1);
  int value_2_degree = get_decimal_power(value_2);
  int result_degree = value_1_degree + value_2_degree;

  if (!result) {
    answer = ArithmeticNotCorrect;
  } else {
    set_zero_decimal(result);
    if ((value_1_degree <= MaxDegree && value_2_degree <= MaxDegree) &&
        (value_1_degree >= MinDegree && value_2_degree >= MinDegree)) {
      if (check_overflow == ArithmeticIsBig) {
        bank(value_1, &value_1);
        bank(value_2, &value_2);
      }
      answer = signed_multiplication(value_1, value_2, result);
      if (answer == ArithmeticIsBig) {
        set_zero_decimal(result);
        int sign = get_decimal_sign(*result);
        if (sign == Negative) {
          answer = ArithmeticIsSmall;
        }
      }
    } else {
      answer = ArithmeticNotCorrect;
      set_zero_decimal(result);
    }

    if (result_degree > MaxDegree) {
      answer = ArithmeticNotCorrect;
      set_zero_decimal(result);
    } else {
      set_decimal_power(result, result_degree);
    }
  }

  return answer;
}