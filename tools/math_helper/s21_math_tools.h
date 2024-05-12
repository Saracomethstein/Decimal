#ifndef S21_MATH_TOOLS_H
#define S21_MATH_TOOLS_H

#include <stdlib.h>

#include "../s21_tools.h"

// ADD  //
int add_decimals(s21_decimal val_1, s21_decimal val_2, s21_decimal *res);
int signed_addition(s21_decimal val_1, s21_decimal val_2, s21_decimal *res);

//  SUB //
void sub_decimals(s21_decimal val_1, s21_decimal val_2, s21_decimal *res);
int signed_subtraction(s21_decimal value_1, s21_decimal value_2,
                       s21_decimal *result);

//  MUL //
int mul_decimals(s21_decimal val_1, s21_decimal val_2, s21_decimal *res);
s21_decimal mul_decimals_return(s21_decimal val_1, s21_decimal val_2,
                                s21_decimal res);
int signed_multiplication(s21_decimal val_1, s21_decimal val_2,
                          s21_decimal *res);

//  DIV //
int signed_division(s21_decimal val_1, s21_decimal val_2, s21_decimal *res);
int div_decimals(s21_decimal val_1, s21_decimal val_2, s21_decimal *res);
int div_decimal_integers(s21_decimal val_1, s21_decimal val_2,
                         s21_decimal *res);

// BANK //
void bank(s21_decimal value, s21_decimal *result);
void bank_round(s21_decimal value, s21_decimal fractional,
                s21_decimal after_trunc, s21_decimal *result);
int even(s21_decimal value);

// FIND DENOMINATOR //
int find_common_denominator(s21_decimal *value_1, s21_decimal *value_2);
int find_denominator(s21_decimal *value_1, s21_decimal *value_2);
void trunc_for_arith(s21_decimal *value_1, s21_decimal *value_2,
                     int *result_power);

// Other funk //
void decimal_copy(s21_decimal src, s21_decimal *dst);
int check_result_sign(s21_decimal value_1, s21_decimal value_2);
void left_shift(s21_decimal *dec, int shift);

// Standard variables //
s21_decimal decimal_zero();
s21_decimal decimal_one();
s21_decimal decimal_two();
s21_decimal decimal_five();
s21_decimal decimal_ten();
s21_decimal decimal_negative();
s21_decimal decimal_trunc_max();

#endif