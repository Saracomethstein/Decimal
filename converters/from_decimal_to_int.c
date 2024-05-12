#include <limits.h>

#include "../operators_comparison//operators_comparison.h"
#include "../tools/get/get_tools.h"
#include "converters.h"

int from_decimal_to_int(decimal src, int *dst) {
  int answer = ConvertOK;
  int sign = get_decimal_sign(src);
  decimal zero = {{0, 0, 0, 0}};

  if (!dst) {
    answer = ConvertERROR;
  } else if (is_equal(src, zero) == True) {
    if (sign == Negative) {
      *dst = -0;
    } else {
      *dst = 0;
    }
    answer = ConvertOK;
  } else {
    *dst = 0;
    for (int i = 0; i < 96; ++i) {
      if (get_decimal_bit(src, i) != 0) {
        *dst += (int)pow(2, i);
      }
    }
    *dst /= (int)pow(10, get_decimal_power(src));
    if (src.bits[0] > INT_MAX) {
      *dst = 0;
      answer = ConvertERROR;
    } else if (sign == Negative) {
      *dst *= -1;
    }
  }
  return answer;
}