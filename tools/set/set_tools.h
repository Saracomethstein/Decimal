#ifndef SET_TOOLS_H
#define SET_TOOLS_H

#include "../tools.h"

int set_decimal_bit(decimal *decimal, int index, int bit);
void set_zero_decimal(decimal *value);
void set_decimal_power(decimal *value, int degree);
void set_decimal_sign(decimal *value, int sign);

#endif