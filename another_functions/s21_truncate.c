#include "../operators_comparison/s21_operators_comparison.h"
#include "../tools/get/s21_get_tools.h"
#include "../tools/math_helper/s21_math_tools.h"
#include "../tools/set/s21_set_tools.h"
#include "s21_another_func.h"

int s21_truncate(s21_decimal value, s21_decimal *result) {
  int answer = s21_AnotherOK;

  if (!result) {
    answer = s21_AnotherERROR;
  } else {
    set_zero_decimal(result);
    int power = get_decimal_power(value);
    set_decimal_power(&value, s21_MinDegree);
    if (power > s21_MinDegree) {
      for (int i = 0; i < power; ++i) {
        div_decimal_integers(value, decimal_ten(), &value);
      }
    }
    decimal_copy(value, result);
  }

  return answer;
}