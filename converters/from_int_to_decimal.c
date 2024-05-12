#include "../operators_comparison/operators_comparison.h"
#include "../tools/set/set_tools.h"
#include "converters.h"

int from_int_to_decimal(int src, decimal *dst) {
  int answer = ConvertOK;
  int sign = Positive;
  set_zero_decimal(dst);

  if (!src) {
    answer = ConvertERROR;
  } else if (src < 0) {
    sign = Negative;
    src *= -1;
  }

  dst->bits[0] = src;
  set_decimal_sign(dst, sign);
  return answer;
}