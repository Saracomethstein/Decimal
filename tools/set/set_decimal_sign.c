#include "s21_set_tools.h"

void set_decimal_sign(s21_decimal *value, int sign) {
  set_decimal_bit(value, 127, sign);
}