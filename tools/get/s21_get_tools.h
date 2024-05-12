#ifndef S21_GET_TOOLS_H
#define S21_GET_TOOLS_H

#include "../s21_tools.h"

int get_decimal_power(s21_decimal value);
int get_decimal_sign(s21_decimal value);
void print_decimal(s21_decimal decimal);
void print_binary(unsigned int value);
unsigned int get_decimal_bit(s21_decimal value, int index);

#endif