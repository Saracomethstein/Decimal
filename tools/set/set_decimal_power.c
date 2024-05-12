#include "set_tools.h"

void set_decimal_power(decimal *value, int power) {
  for (int i = BitsPowerAndSign + 16; i < BitsPowerAndSign + 23; i++) {
    set_decimal_bit(value, i, power & 1);
    power >>= 1;
  }
}