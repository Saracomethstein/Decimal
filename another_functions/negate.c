#include "../arithmetic_operators/arithmetic_operators.h"
#include "../tools/math_helper/math_tools.h"
#include "../tools/set/set_tools.h"
#include "another_func.h"

int negate_dec(decimal value, decimal *result) {
  int answer = AnotherOK;
  int calc_answer = ArithmeticOK;

  if (!result) {
    answer = AnotherERROR;
  } else {
    set_zero_decimal(result);
    calc_answer = mul_dec(value, decimal_negative(), result);
    if (calc_answer != ArithmeticOK) answer = AnotherERROR;
  }

  return answer;
}