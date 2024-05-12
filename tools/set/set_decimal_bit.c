#include "set_tools.h"

int set_decimal_bit(decimal *value, int index, int bit) {
  if (bit == 1) {
    value->bits[index / 32] |= (1U << index % 32);
  } else {
    value->bits[index / 32] &= ~((1U) << index % 32);
  }
  return 0;
}