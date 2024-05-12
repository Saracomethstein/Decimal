#include "../operators_comparison//operators_comparison.h"
#include "../tools/get/get_tools.h"
#include "../tools/math_helper/math_tools.h"
#include "../tools/set/set_tools.h"
#include "arithmetic_operators.h"

int div_dec(decimal value_1, decimal value_2, decimal *result) {
  int answer = ArithmeticOK;
  int overflow = ArithmeticOK;
  int value_1_degree = get_decimal_power(value_1);
  int value_2_degree = get_decimal_power(value_2);

  if (!result) {
    answer = ArithmeticNotCorrect;
  } else {
    if (value_2.bits[0] == 0 && value_2.bits[1] == 0 && value_2.bits[2] == 0) {
      answer = ArithmeticDivByZero;
      set_zero_decimal(result);
      set_decimal_sign(result, 0);
    } else {
      set_zero_decimal(result);
      if ((value_1_degree <= MaxDegree && value_2_degree <= MaxDegree) &&
          (value_1_degree >= MinDegree && value_2_degree >= MinDegree)) {
        if (value_1.bits[0] == 0 && value_1.bits[1] == 0 &&
            value_1.bits[2] == 0) {
          set_decimal_sign(&value_2, Positive);
          set_zero_decimal(result);
          set_decimal_power(result, MinDegree);
          answer = ArithmeticOK;
        } else {
          overflow = signed_division(value_1, value_2, result);
          if (overflow == ArithmeticIsBig) {
            answer = ArithmeticIsBig;
          }
        }
      } else {
        answer = ArithmeticNotCorrect;
        set_zero_decimal(result);
      }
    }
  }
  return answer;
}