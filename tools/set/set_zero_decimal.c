#include "set_tools.h"

void set_zero_decimal(decimal *value) {
  value->bits[0] = 0;
  value->bits[1] = (0 >> 1);
  value->bits[2] = (0 >> 2);
  value->bits[3] = (0 >> 3);
}