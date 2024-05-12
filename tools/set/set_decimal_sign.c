#include "set_tools.h"

void set_decimal_sign(decimal *value, int sign) {
  set_decimal_bit(value, 127, sign);
}