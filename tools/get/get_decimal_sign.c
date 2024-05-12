#include "get_tools.h"

int get_decimal_sign(decimal value) {
  return (value.bits[3] >> MaxBits) & 0x01;
}