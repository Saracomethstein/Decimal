#include "math_tools.h"

void decimal_copy(decimal src, decimal *dst) {
  for (int i = 0; i < 4; i++) {
    dst->bits[i] = src.bits[i];
  }
}