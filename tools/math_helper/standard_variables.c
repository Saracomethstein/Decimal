#include "s21_math_tools.h"

s21_decimal decimal_zero() {
  s21_decimal zero = {{0, 0, 0, 0}};
  return zero;
}

s21_decimal decimal_one() {
  s21_decimal one = {{1, 0, 0, 0}};
  return one;
}

s21_decimal decimal_two() {
  s21_decimal two = {{2, 0, 0, 0}};
  return two;
}

s21_decimal decimal_five() {
  s21_decimal five = {{5, 0, 0, 0}};
  return five;
}

s21_decimal decimal_ten() {
  s21_decimal ten = {{10, 0, 0, 0}};
  return ten;
}

s21_decimal decimal_negative() {
  s21_decimal negative = {{1, 0, 0, 0x80000000}};
  return negative;
}

s21_decimal decimal_trunc_max() {
  s21_decimal trunc_max = {{0x99999999, 0x99999999, 0x19999999, 0}};
  return trunc_max;
}