#include "s21_math_tools.h"

void decimal_copy(s21_decimal src, s21_decimal *dst) {
  for (int i = 0; i < 4; i++) {
    dst->bits[i] = src.bits[i];
  }
}