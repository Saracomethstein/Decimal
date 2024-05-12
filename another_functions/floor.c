#include "../arithmetic_operators/arithmetic_operators.h"
#include "../tools/get/get_tools.h"
#include "../tools/math_helper/math_tools.h"
#include "../tools/set/set_tools.h"
#include "another_func.h"

int floor_dec(decimal value, decimal *result) {
  int answer = AnotherOK;

  if (!result) {
    answer = AnotherERROR;
  } else {
    decimal fractional = {{0, 0, 0, 0}};
    decimal value_after_trunc = {{0, 0, 0, 0}};
    set_zero_decimal(result);
    int sign = get_decimal_sign(value);
    set_decimal_sign(&value, Positive);
    truncate_dec(value, &value_after_trunc);
    if (sign == Positive) {
      sub_dec(value, value_after_trunc, &fractional);
      decimal_copy(value_after_trunc, result);
    } else {
      set_decimal_sign(&value_after_trunc, Positive);
      add_dec(value_after_trunc, decimal_one(), result);
    }
    set_decimal_sign(result, sign);
    set_decimal_power(result, MinDegree);
  }
  return answer;
}
