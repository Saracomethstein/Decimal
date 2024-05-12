#ifndef ANOTHER_FUNC_H
#define ANOTHER_FUNC_H

#include "../tools/tools.h"

int floor_dec(decimal value, decimal *result);
int round_dec(decimal value, decimal *result);
int truncate_dec(decimal value, decimal *result);
int negate_dec(decimal value, decimal *result);

#endif