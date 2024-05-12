#include "../../another_functions/s21_another_func.h"
#include "../../operators_comparison/s21_operators_comparison.h"
#include "../get/s21_get_tools.h"
#include "../set/s21_set_tools.h"
#include "s21_math_tools.h"

int even(s21_decimal value) {
  int answer = 0;
  s21_decimal res = {0};
  set_decimal_power(&value, s21_MinDegree);
  div_decimal_integers(value, decimal_two(), &res);
  if (get_decimal_power(res) > 0) {
    answer = 1;
  }
  return answer;
}

void bank_round(s21_decimal value, s21_decimal fractional,
                s21_decimal after_trunc, s21_decimal *result) {
  int power = get_decimal_power(value);
  for (int i = 0; i < power - 1; ++i) {
    mul_decimals(fractional, decimal_ten(), &fractional);
  }
  if (s21_is_equal(fractional, decimal_five()) == s21_True) {
    if (even(after_trunc) == 0) {
      decimal_copy(after_trunc, result);
    } else {
      add_decimals(after_trunc, decimal_one(), result);
    }
  } else if (s21_is_greater(fractional, decimal_five()) == s21_True) {
    add_decimals(after_trunc, decimal_one(), result);
  } else {
    decimal_copy(after_trunc, result);
  }
  set_decimal_power(result, s21_MinDegree);
}

void bank(s21_decimal value, s21_decimal *result) {
  s21_decimal fractional = {{0, 0, 0, 0}};
  s21_decimal value_after_trunc = {{0, 0, 0, 0}};
  s21_decimal copy = {0};
  s21_decimal copy_val_after_trunc = {0};
  int power = get_decimal_power(value);
  s21_truncate(value, &value_after_trunc);
  decimal_copy(value_after_trunc, &copy_val_after_trunc);

  for (int i = 0; i < power; ++i) {
    mul_decimals(value_after_trunc, decimal_ten(), &value_after_trunc);
  }

  decimal_copy(value_after_trunc, &copy);
  sub_decimals(value, copy, &fractional);
  bank_round(value, fractional, copy_val_after_trunc, result);
}