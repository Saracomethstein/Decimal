#include "../tools/get/get_tools.h"
#include "../tools/math_helper/math_tools.h"
#include "operators_comparison.h"

int abs_greater(decimal value_1, decimal value_2) {
  int answer = False;
  for (int i = 2; i >= 0; i--) {
    if (value_1.bits[i] < value_2.bits[i]) {
      answer = False;
      break;
    } else if (value_1.bits[i] > value_2.bits[i]) {
      answer = True;
      break;
    }
  }
  return answer;
}

int is_greater(decimal value_1, decimal value_2) {
  int answer = False;
  int v1_sign = get_decimal_sign(value_1);
  int v2_sign = get_decimal_sign(value_2);

  find_common_denominator(&value_1, &value_2);

  if ((value_1.bits[0] == 0 && value_1.bits[1] == 0 && value_1.bits[2] == 0) &&
      ((value_2.bits[0] == 0 && value_2.bits[1] == 0 &&
        value_2.bits[2] == 0))) {
    answer = False;
  } else if (v1_sign == Positive && v1_sign == v2_sign) {
    for (int i = 2; i >= 0; --i) {
      if (value_1.bits[i] > value_2.bits[i]) {
        answer = True;
        break;
      } else if (value_1.bits[i] < value_2.bits[i]) {
        answer = False;
        break;
      } else
        continue;
    }
  } else if (v1_sign == Negative && v1_sign == v2_sign) {
    for (int i = 2; i >= 0; --i) {
      if (value_1.bits[i] < value_2.bits[i]) {
        answer = True;
        break;
      } else if (value_1.bits[i] > value_2.bits[i]) {
        answer = False;
        break;
      } else
        continue;
    }
  } else if (v1_sign != v2_sign) {
    if (v1_sign == Negative)
      answer = False;
    else
      answer = True;
  }
  return answer;
}