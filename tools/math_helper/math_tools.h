#ifndef MATH_TOOLS_H
#define MATH_TOOLS_H

#include <stdlib.h>

#include "../tools.h"

// ADD  //
int add_decimals(decimal val_1, decimal val_2, decimal *res);
int signed_addition(decimal val_1, decimal val_2, decimal *res);

//  SUB //
void sub_decimals(decimal val_1, decimal val_2, decimal *res);
int signed_subtraction(decimal value_1, decimal value_2, decimal *result);

//  MUL //
int mul_decimals(decimal val_1, decimal val_2, decimal *res);
decimal mul_decimals_return(decimal val_1, decimal val_2, decimal res);
int signed_multiplication(decimal val_1, decimal val_2, decimal *res);

//  DIV //
int signed_division(decimal val_1, decimal val_2, decimal *res);
int div_decimals(decimal val_1, decimal val_2, decimal *res);
int div_decimal_integers(decimal val_1, decimal val_2, decimal *res);

// BANK //
void bank(decimal value, decimal *result);
void bank_round(decimal value, decimal fractional, decimal after_trunc,
                decimal *result);
int even(decimal value);

// FIND DENOMINATOR //
int find_common_denominator(decimal *value_1, decimal *value_2);
int find_denominator(decimal *value_1, decimal *value_2);
void trunc_for_arith(decimal *value_1, decimal *value_2, int *result_power);

// Other funk //
void decimal_copy(decimal src, decimal *dst);
int check_result_sign(decimal value_1, decimal value_2);
void left_shift(decimal *dec, int shift);

// Standard variables //
decimal decimal_zero();
decimal decimal_one();
decimal decimal_two();
decimal decimal_five();
decimal decimal_ten();
decimal decimal_negative();
decimal decimal_trunc_max();

#endif