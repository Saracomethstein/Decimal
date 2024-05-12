#include "../operators_comparison//operators_comparison.h"
#include "../tools/get/get_tools.h"
#include "converters.h"

int from_decimal_to_float(decimal src, float *dst) {
  int answer = ConvertOK;
  int sign = get_decimal_sign(src);
  int degree = get_decimal_power(src);
  decimal zero = {{0, 0, 0, 0}};

  if (!dst) {
    answer = ConvertERROR;
  } else if (is_equal(src, zero) == True) {
    if (sign == Negative) {
      *dst = (float)-0.0;
    } else {
      *dst = (float)0.0;
    }
    answer = ConvertOK;
  } else {
    *dst = (float)0.0;
    double tmp = 0.0;

    for (int i = 0; i < BitsPowerAndSign; ++i) {
      if (get_decimal_bit(src, i) != 0) {
        tmp += pow(2.0, i);
      }
    }

    double degreeByTen = pow(10, degree);
    tmp /= degreeByTen;

    if (sign == Negative) {
      tmp *= -1.0;
    }
    *dst = (float)tmp;
  }
  return answer;
}