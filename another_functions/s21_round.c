#include "../arithmetic_operators/s21_arithmetic_operators.h"
#include "../operators_comparison/s21_operators_comparison.h"
#include "../tools/get/s21_get_tools.h"
#include "../tools/math_helper/s21_math_tools.h"
#include "../tools/set/s21_set_tools.h"
#include "s21_another_func.h"

int s21_round(s21_decimal value, s21_decimal *result) {
  int answer = s21_AnotherOK;

  if (!result) {
    answer = s21_AnotherERROR;
  } else {
    s21_decimal fractional = {{0, 0, 0, 0}};
    s21_decimal value_after_trunc = {{0, 0, 0, 0}};
    s21_decimal copy_val_after_trunc = {0};
    s21_decimal five = {{5, 0, 0, 0}};
    int power = get_decimal_power(value);
    int sign = get_decimal_sign(value);
    set_zero_decimal(result);

    set_decimal_sign(&value, s21_Positive);
    s21_truncate(value, &value_after_trunc);
    decimal_copy(value_after_trunc, &copy_val_after_trunc);
    for (int i = 0; i < power; ++i) {
      mul_decimals(value_after_trunc, decimal_ten(), &value_after_trunc);
    }
    sub_decimals(value, value_after_trunc, &fractional);
    for (int i = 0; i < power - 1; ++i) {
      mul_decimals(five, decimal_ten(), &five);
    }
    if (s21_is_equal(five, fractional) || s21_is_greater(fractional, five)) {
      add_decimals(copy_val_after_trunc, decimal_one(), result);
    } else {
      decimal_copy(copy_val_after_trunc, result);
    }
    set_decimal_sign(result, sign);
  }
  return answer;
}