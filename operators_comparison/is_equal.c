#include "../tools/get/get_tools.h"
#include "operators_comparison.h"

int is_equal(decimal value_1, decimal value_2) {
  int answer = False;
  int v1_sign = get_decimal_sign(value_1);
  int v2_sign = get_decimal_sign(value_2);
  if ((value_1.bits[0] == 0 && value_1.bits[1] == 0 && value_1.bits[2] == 0) &&
      ((value_2.bits[0] == 0 && value_2.bits[1] == 0 &&
        value_2.bits[2] == 0))) {
    answer = True;
  } else if (v1_sign == v2_sign) {
    if (value_1.bits[0] == value_2.bits[0] &&
        value_1.bits[1] == value_2.bits[1] &&
        value_1.bits[2] == value_2.bits[2] &&
        value_1.bits[3] == value_2.bits[3])
      answer = True;
  }
  return answer;
}

int abs_equal(decimal value_1, decimal value_2) {
  int answer = False;
  int v1_sign = get_decimal_sign(value_1);
  int v2_sign = get_decimal_sign(value_2);
  if (v1_sign == v2_sign) {
    if (value_1.bits[0] == value_2.bits[0] &&
        value_1.bits[1] == value_2.bits[1] &&
        value_1.bits[2] == value_2.bits[2])
      answer = True;
  }
  return answer;
}
