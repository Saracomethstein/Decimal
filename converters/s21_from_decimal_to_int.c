#include <limits.h>

#include "../operators_comparison//s21_operators_comparison.h"
#include "../tools/get/s21_get_tools.h"
#include "s21_converters.h"

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int answer = s21_ConvertOK;
  int sign = get_decimal_sign(src);
  s21_decimal zero = {{0, 0, 0, 0}};

  if (!dst) {
    answer = s21_ConvertERROR;
  } else if (s21_is_equal(src, zero) == s21_True) {
    if (sign == s21_Negative) {
      *dst = -0;
    } else {
      *dst = 0;
    }
    answer = s21_ConvertOK;
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
      answer = s21_ConvertERROR;
    } else if (sign == s21_Negative) {
      *dst *= -1;
    }
  }
  return answer;
}