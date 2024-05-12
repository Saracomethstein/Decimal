#include "s21_get_tools.h"

int get_decimal_sign(s21_decimal value) {
  return (value.bits[3] >> s21_MaxBits) & 0x01;
}