#include "get_tools.h"

int get_decimal_power(decimal value) { return (value.bits[3] >> 16) & 0xFF; }