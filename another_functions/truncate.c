#include "../operators_comparison/operators_comparison.h"
#include "../tools/get/get_tools.h"
#include "../tools/math_helper/math_tools.h"
#include "../tools/set/set_tools.h"
#include "another_func.h"

int truncate_dec(decimal value, decimal *result) {
  int answer = AnotherOK;

  if (!result) {
    answer = AnotherERROR;
  } else {
    set_zero_decimal(result);
    int power = get_decimal_power(value);
    set_decimal_power(&value, MinDegree);
    if (power > MinDegree) {
      for (int i = 0; i < power; ++i) {
        div_decimal_integers(value, decimal_ten(), &value);
      }
    }
    decimal_copy(value, result);
  }

  return answer;
}