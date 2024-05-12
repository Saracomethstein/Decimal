#include "../arithmetic_operators/arithmetic_operators.h"
#include "../operators_comparison/operators_comparison.h"
#include "../tools/get/get_tools.h"
#include "../tools/math_helper/math_tools.h"
#include "../tools/set/set_tools.h"
#include "another_func.h"

int round_dec(decimal value, decimal *result) {
  int answer = AnotherOK;

  if (!result) {
    answer = AnotherERROR;
  } else {
    decimal fractional = {{0, 0, 0, 0}};
    decimal value_after_trunc = {{0, 0, 0, 0}};
    decimal copy_val_after_trunc = {0};
    decimal five = {{5, 0, 0, 0}};
    int power = get_decimal_power(value);
    int sign = get_decimal_sign(value);
    set_zero_decimal(result);

    set_decimal_sign(&value, Positive);
    truncate_dec(value, &value_after_trunc);
    decimal_copy(value_after_trunc, &copy_val_after_trunc);
    for (int i = 0; i < power; ++i) {
      mul_decimals(value_after_trunc, decimal_ten(), &value_after_trunc);
    }
    sub_decimals(value, value_after_trunc, &fractional);
    for (int i = 0; i < power - 1; ++i) {
      mul_decimals(five, decimal_ten(), &five);
    }
    if (is_equal(five, fractional) || is_greater(fractional, five)) {
      add_decimals(copy_val_after_trunc, decimal_one(), result);
    } else {
      decimal_copy(copy_val_after_trunc, result);
    }
    set_decimal_sign(result, sign);
  }
  return answer;
}