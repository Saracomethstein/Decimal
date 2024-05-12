#ifndef S21_CONVERTERS_H
#define S21_CONVERTERS_H

#include "../tools/s21_tools.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);

void round_power10(s21_decimal *decimal);
int check_errors(float src, s21_decimal *dst);
void round_with_zeroes(float src, s21_decimal *dst, int integer_part_length);
void round_default_float(float src, s21_decimal *dst, int integer_part_length);
int get_float_sign(float src);
void set_decimal_inf(s21_decimal *dst);

#endif