#include "../../another_functions/another_func.h"
#include "../../operators_comparison/operators_comparison.h"
#include "../get/get_tools.h"
#include "../set/set_tools.h"
#include "math_tools.h"

int even(decimal value) {
  int answer = 0;
  decimal res = {0};
  set_decimal_power(&value, MinDegree);
  div_decimal_integers(value, decimal_two(), &res);
  if (get_decimal_power(res) > 0) {
    answer = 1;
  }
  return answer;
}

void bank_round(decimal value, decimal fractional, decimal after_trunc,
                decimal *result) {
  int power = get_decimal_power(value);
  for (int i = 0; i < power - 1; ++i) {
    mul_decimals(fractional, decimal_ten(), &fractional);
  }
  if (is_equal(fractional, decimal_five()) == True) {
    if (even(after_trunc) == 0) {
      decimal_copy(after_trunc, result);
    } else {
      add_decimals(after_trunc, decimal_one(), result);
    }
  } else if (is_greater(fractional, decimal_five()) == True) {
    add_decimals(after_trunc, decimal_one(), result);
  } else {
    decimal_copy(after_trunc, result);
  }
  set_decimal_power(result, MinDegree);
}

void bank(decimal value, decimal *result) {
  decimal fractional = {{0, 0, 0, 0}};
  decimal value_after_trunc = {{0, 0, 0, 0}};
  decimal copy = {0};
  decimal copy_val_after_trunc = {0};
  int power = get_decimal_power(value);
  truncate_dec(value, &value_after_trunc);
  decimal_copy(value_after_trunc, &copy_val_after_trunc);

  for (int i = 0; i < power; ++i) {
    mul_decimals(value_after_trunc, decimal_ten(), &value_after_trunc);
  }

  decimal_copy(value_after_trunc, &copy);
  sub_decimals(value, copy, &fractional);
  bank_round(value, fractional, copy_val_after_trunc, result);
}