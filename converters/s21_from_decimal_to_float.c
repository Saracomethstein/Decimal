#include "../operators_comparison//s21_operators_comparison.h"
#include "../tools/get/s21_get_tools.h"
#include "s21_converters.h"

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  int answer = s21_ConvertOK;
  int sign = get_decimal_sign(src);
  int degree = get_decimal_power(src);
  s21_decimal zero = {{0, 0, 0, 0}};

  if (!dst) {
    answer = s21_ConvertERROR;
  } else if (s21_is_equal(src, zero) == s21_True) {
    if (sign == s21_Negative) {
      *dst = (float)-0.0;
    } else {
      *dst = (float)0.0;
    }
    answer = s21_ConvertOK;
  } else {
    *dst = (float)0.0;
    double tmp = 0.0;

    for (int i = 0; i < s21_BitsPowerAndSign; ++i) {
      if (get_decimal_bit(src, i) != 0) {
        tmp += pow(2.0, i);
      }
    }

    double degreeByTen = pow(10, degree);
    tmp /= degreeByTen;

    if (sign == s21_Negative) {
      tmp *= -1.0;
    }
    *dst = (float)tmp;
  }
  return answer;
}