#include "../operators_comparison/s21_operators_comparison.h"
#include "../tools/set/s21_set_tools.h"
#include "s21_converters.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  int answer = s21_ConvertOK;
  int sign = s21_Positive;
  set_zero_decimal(dst);

  if (!src) {
    answer = s21_ConvertERROR;
  } else if (src < 0) {
    sign = s21_Negative;
    src *= -1;
  }

  dst->bits[0] = src;
  set_decimal_sign(dst, sign);
  return answer;
}