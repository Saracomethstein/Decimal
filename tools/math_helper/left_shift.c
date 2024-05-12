#include "../get/s21_get_tools.h"
#include "../set/s21_set_tools.h"
#include "s21_math_tools.h"

void left_shift(s21_decimal *dec, int shift) {
  for (int i = 0; i < shift; i++) {
    int dec_31 = (int)get_decimal_bit(*dec, 31);
    int dec_63 = (int)get_decimal_bit(*dec, 63);
    dec->bits[0] <<= 1u;
    dec->bits[1] <<= 1u;
    set_decimal_bit(dec, 32, dec_31);
    dec->bits[2] <<= 1u;
    set_decimal_bit(dec, 64, dec_63);
  }
}