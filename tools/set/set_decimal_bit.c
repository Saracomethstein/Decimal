#include "s21_set_tools.h"

int set_decimal_bit(s21_decimal *decimal, int index, int bit) {
  //  int number_of_int = index / 32;
  //  int number_of_bit = index % 32;
  if (bit == 1) {
    decimal->bits[index / 32] |= (1U << index % 32);
  } else {
    decimal->bits[index / 32] &= ~((1U) << index % 32);
  }
  return 0;
}