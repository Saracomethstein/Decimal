#ifndef S21_OPERATORS_COMPARISON_H
#define S21_OPERATORS_COMPARISON_H

#include "../tools/s21_tools.h"

int s21_is_less(s21_decimal value_1, s21_decimal value_2);
int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2);

int s21_abs_equal(s21_decimal value_1, s21_decimal value_2);
int s21_abs_greater(s21_decimal value_1, s21_decimal value_2);
int s21_abs_less(s21_decimal value_1, s21_decimal value_2);
int s21_abs_less_or_equal(s21_decimal value_1, s21_decimal value_2);
int s21_abs_greater_or_equal(s21_decimal value_1, s21_decimal value_2);
int s21_abs_not_equal(s21_decimal value_1, s21_decimal value_2);

#endif