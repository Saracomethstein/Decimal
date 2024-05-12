#ifndef CONVERTERS_H
#define CONVERTERS_H

#include "../tools/tools.h"

int from_int_to_decimal(int src, decimal *dst);
int from_float_to_decimal(float src, decimal *dst);
int from_decimal_to_int(decimal src, int *dst);
int from_decimal_to_float(decimal src, float *dst);

void round_power10(decimal *decimal);
int check_errors(float src, decimal *dst);
void round_with_zeroes(float src, decimal *dst, int integer_part_length);
void round_default_float(float src, decimal *dst, int integer_part_length);
int get_float_sign(float src);
void set_decimal_inf(decimal *dst);

#endif