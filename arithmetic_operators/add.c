#include "../another_functions/another_func.h"
#include "../tools/get/get_tools.h"
#include "../tools/math_helper/math_tools.h"
#include "../tools/set/set_tools.h"
#include "arithmetic_operators.h"

int check_add_overflow(decimal val_1, decimal val_2) {
  decimal result = {0};
  return signed_addition(val_1, val_2, &result);
}

int add_dec(decimal value_1, decimal value_2, decimal *result) {
  int answer = ArithmeticOK;
  int result_sign = Positive;
  int result_degree = MinDegree;
  int value_1_degree = get_decimal_power(value_1);
  int value_2_degree = get_decimal_power(value_2);
  int check_overflow = check_add_overflow(value_1, value_2);

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
      result_degree = find_common_denominator(&value_1, &value_2);
      result_sign = check_result_sign(value_1, value_2);
      answer = signed_addition(value_1, value_2, result);
      if (answer == ArithmeticIsBig) {
        set_zero_decimal(result);
        if (result_sign == Negative) {
          answer = ArithmeticIsSmall;
        }
      }
    } else {
      answer = ArithmeticNotCorrect;
      set_zero_decimal(result);
    }

    set_decimal_power(result, result_degree);
    set_decimal_sign(result, result_sign);
  }

  return answer;
}