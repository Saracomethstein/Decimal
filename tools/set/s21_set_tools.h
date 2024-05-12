#ifndef S21_SET_TOOLS_H
#define S21_SET_TOOLS_H

#include "../s21_tools.h"

int set_decimal_bit(s21_decimal *decimal, int index, int bit);
void set_zero_decimal(s21_decimal *value);
void set_decimal_power(s21_decimal *value, int degree);
void set_decimal_sign(s21_decimal *value, int sign);

#endif