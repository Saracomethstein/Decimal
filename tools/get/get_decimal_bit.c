#include "get_tools.h"

unsigned int get_decimal_bit(decimal value, int index) {
  return (value.bits[index / 32] & (1u << (index % 32))) >> (index % 32);
}