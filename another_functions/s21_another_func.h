#ifndef S21_ANOTHER_FUNC_H
#define S21_ANOTHER_FUNC_H

#include "../tools/s21_tools.h"

int s21_floor(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);

#endif