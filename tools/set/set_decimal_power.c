#include "s21_set_tools.h"

void set_decimal_power(s21_decimal *value, int power) {
  for (int i = s21_BitsPowerAndSign + 16; i < s21_BitsPowerAndSign + 23; i++) {
    set_decimal_bit(value, i, power & 1);
    power >>= 1;
  }
}