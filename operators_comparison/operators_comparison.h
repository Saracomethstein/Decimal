#ifndef OPERATORS_COMPARISON_H
#define OPERATORS_COMPARISON_H

#include "../tools/tools.h"

int is_less(decimal value_1, decimal value_2);
int is_less_or_equal(decimal value_1, decimal value_2);
int is_greater(decimal value_1, decimal value_2);
int is_greater_or_equal(decimal value_1, decimal value_2);
int is_equal(decimal value_1, decimal value_2);
int is_not_equal(decimal value_1, decimal value_2);

int abs_equal(decimal value_1, decimal value_2);
int abs_greater(decimal value_1, decimal value_2);
int abs_less(decimal value_1, decimal value_2);
int abs_less_or_equal(decimal value_1, decimal value_2);
int abs_greater_or_equal(decimal value_1, decimal value_2);
int abs_not_equal(decimal value_1, decimal value_2);

#endif