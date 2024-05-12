#include "s21_get_tools.h"

int get_decimal_power(s21_decimal value) {
  return (value.bits[3] >> 16) & 0xFF;
}