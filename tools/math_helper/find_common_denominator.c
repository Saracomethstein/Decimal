#include "../../another_functions/s21_another_func.h"
#include "../../operators_comparison/s21_operators_comparison.h"
#include "../get/s21_get_tools.h"
#include "../set/s21_set_tools.h"
#include "s21_math_tools.h"

int find_common_denominator(s21_decimal *value_1, s21_decimal *value_2) {
  s21_decimal check_overflow = {0};
  int value_1_degree = get_decimal_power(*value_1);
  int value_2_degree = get_decimal_power(*value_2);
  int val_1_sign = get_decimal_sign(*value_1);
  int val_2_sign = get_decimal_sign(*value_2);
  int result_power = s21_MinDegree;

  if (value_1_degree == value_2_degree) {
    result_power = (value_1_degree + value_2_degree) / 2;
    trunc_for_arith(value_1, value_2, &result_power);
  } else if (value_1_degree > value_2_degree &&
             add_decimals(*value_1, *value_2, &check_overflow) !=
                 s21_ArithmeticIsBig) {
    result_power = find_denominator(value_1, value_2);
  } else if (value_2_degree > value_1_degree &&
             add_decimals(*value_1, *value_2, &check_overflow) !=
                 s21_ArithmeticIsBig) {
    result_power = find_denominator(value_2, value_1);
  } else {
    if (value_2_degree > value_1_degree) {
      s21_round(*value_2, value_2);
    }
    if (value_1_degree > value_2_degree) {
      s21_round(*value_1, value_1);
    }
  }
  set_decimal_power(value_1, result_power);
  set_decimal_power(value_2, result_power);
  set_decimal_sign(value_1, val_1_sign);
  set_decimal_sign(value_2, val_2_sign);
  return result_power;
}

int find_denominator(s21_decimal *value_1, s21_decimal *value_2) {
  s21_decimal copy = {{0, 0, 0, 0}};
  s21_decimal check_overflow = {0};
  int value_1_power = get_decimal_power(*value_1);
  int value_2_power = get_decimal_power(*value_2);
  int result_power = s21_MinDegree;

  while (value_1_power != value_2_power) {
    mul_decimals(*value_2, decimal_ten(), value_2);
    set_decimal_power(value_2, ++value_2_power);
    result_power = value_2_power;
    if (mul_decimals(*value_2, decimal_ten(), &check_overflow) ==
        s21_ArithmeticIsBig) {
      break;
    }
  }
  if (mul_decimals(*value_2, decimal_ten(), &check_overflow) ==
      s21_ArithmeticIsBig) {
    while (value_1_power != value_2_power) {
      div_decimal_integers(*value_1, decimal_ten(), &copy);
      decimal_copy(copy, value_1);
      set_zero_decimal(&copy);
      set_decimal_power(value_1, --value_1_power);
      if (s21_is_less(*value_1, decimal_ten()) == s21_True &&
          value_1_power != value_2_power) {
        set_zero_decimal(value_1);
        result_power = value_2_power;
        break;
      }
    }
  }
  return result_power;
}

void trunc_for_arith(s21_decimal *value_1, s21_decimal *value_2,
                     int *result_power) {
  s21_decimal if_mantissa_is_full = {{0, 0, 0, 0}};
  int add_answer = add_decimals(*value_1, *value_2, &if_mantissa_is_full);
  if (add_answer == s21_ArithmeticIsBig && *result_power != 0) {
    set_decimal_power(value_1, 1);
    set_decimal_power(value_2, 1);
    s21_truncate(*value_1, value_1);
    s21_truncate(*value_2, value_2);
    --*result_power;
  }
}