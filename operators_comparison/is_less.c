#include "../tools/get/get_tools.h"
#include "operators_comparison.h"

int is_less(decimal value_1, decimal value_2) {
  int answer;
  if ((value_1.bits[0] == 0 && value_1.bits[1] == 0 && value_1.bits[2] == 0) &&
      ((value_2.bits[0] == 0 && value_2.bits[1] == 0 &&
        value_2.bits[2] == 0))) {
    answer = False;
  } else
    answer = !is_greater_or_equal(value_1, value_2);
  return answer;
}

int abs_less(decimal value_1, decimal value_2) {
  int answer = False;
  int v1_sign = get_decimal_sign(value_1);
  int v2_sign = get_decimal_sign(value_2);
  if (v1_sign == v2_sign) {
    for (int i = 2; i >= 0; i--) {
      if (value_1.bits[i] < value_2.bits[i]) {
        if (v1_sign == Negative)
          answer = False;
        else
          answer = True;
        break;
      } else if (value_1.bits[i] > value_2.bits[i]) {
        if (v1_sign == Negative)
          answer = False;
        else
          answer = True;
        break;
      }
    }
  } else if (v1_sign == Negative && v2_sign == Positive)
    answer = True;
  else
    answer = False;
  return answer;
}
