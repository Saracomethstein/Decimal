#include "../../converters/converters.h"
#include "../../operators_comparison/operators_comparison.h"
#include "../get/get_tools.h"
#include "../set/set_tools.h"
#include "math_tools.h"

void bank_for_div(decimal val, decimal *result) {
  set_decimal_power(&val, 1);
  bank(val, result);
}

int div_decimals(decimal value_1, decimal value_2, decimal *result) {
  decimal res = {{0, 0, 0, 0}};
  decimal temp = {{0, 0, 0, 0}};
  decimal check_overflow = {{0, 0, 0, 0}};
  int answer = ArithmeticOK;
  int value_1_degree = get_decimal_power(value_1);
  int value_2_degree = get_decimal_power(value_2);
  set_decimal_sign(&value_1, Positive);
  set_decimal_sign(&value_2, Positive);
  int res_degree = value_1_degree - value_2_degree;

  while ((res_degree < MaxDegree && res_degree >= 0) ||
         abs_equal(value_1, decimal_zero()) != True) {
    decimal_copy(value_2, &temp);
    decimal multiple = {{1, 0, 0, 0}};
    if (abs_greater_or_equal(value_1, value_2) == True) {
      while (abs_greater_or_equal(
                 value_1, mul_decimals_return(temp, decimal_two(), temp)) ==
                 True &&
             mul_decimals(temp, decimal_two(), &check_overflow) !=
                 ArithmeticIsBig) {
        mul_decimals(temp, decimal_two(), &temp);
        mul_decimals(multiple, decimal_two(), &multiple);
      }
      sub_decimals(value_1, temp, &value_1);
      add_decimals(res, multiple, &res);
    } else {
      if (abs_greater(value_1, decimal_zero()) == True &&
          abs_less(value_1, value_2) == True) {
        while (abs_greater(value_1, value_2) != True &&
               res_degree < MaxDegree) {
          mul_decimals(res, decimal_ten(), &res);
          mul_decimals(value_1, decimal_ten(), &value_1);
          mul_decimals(*result, decimal_ten(), result);
          res_degree++;
        }
        add_decimals(*result, res, result);
        if (abs_greater_or_equal(*result, decimal_trunc_max()) == True ||
            res_degree >= MaxDegree) {
          div_decimal_integers(res, decimal_ten(), &res);
          add_decimals(*result, res, result);
          bank_for_div(*result, result);
          break;
        }
        set_zero_decimal(&res);
      } else if (res_degree > MaxDegree ||
                 abs_equal(value_1, decimal_zero()) == True) {
        add_decimals(*result, res, result);
        set_zero_decimal(&res);
        break;
      }
    }
  }
  set_decimal_power(result, abs(res_degree));
  if (result->bits[0] == 0 && result->bits[1] == 0 && result->bits[2] == 0) {
    set_decimal_power(result, 0);
    answer = ArithmeticIsBig;
  }
  return answer;
}

int div_decimal_integers(decimal value_1, decimal value_2, decimal *result) {
  int answer = ArithmeticOK;
  decimal copy = {0};
  decimal tmp = {{0}};
  if (value_2.bits[0] == 0 && value_2.bits[1] == 0 && value_2.bits[2] == 0)
    answer = ArithmeticDivByZero;
  int sign1 = get_decimal_sign(value_1), sign2 = get_decimal_sign(value_2);
  int exp = get_decimal_power(value_1) - get_decimal_power(value_2);
  set_decimal_power(&value_1, MinDegree);
  set_decimal_power(&value_2, MinDegree);
  set_decimal_sign(&value_1, Positive);
  set_decimal_sign(&value_2, Positive);
  decimal_copy(value_2, &copy);
  set_zero_decimal(result);
  int i = BitsPowerAndSign - 1;
  int j = BitsPowerAndSign - 1;
  while (get_decimal_bit(value_2, j) != 1) {
    j--;
  }
  while (get_decimal_bit(value_1, i) != 1) {
    i--;
  }
  while (i >= j) {
    left_shift(&value_2, i - j);
    if (abs_greater_or_equal(value_1, value_2)) {
      sub_decimals(value_1, value_2, &value_1);
      set_decimal_bit(result, i - j, 1);
    } else {
      set_decimal_bit(result, i - j, 0);
    }
    decimal_copy(copy, &value_2);
    i--;
  }
  set_decimal_power(result, exp);
  if (exp < 0) {
    set_decimal_power(result, MinDegree);
    exp = abs(exp);
    int multiply = (int)pow(10, exp);
    from_int_to_decimal(multiply, &tmp);
    mul_decimals(*result, tmp, result);
  }
  if (sign1 != sign2) set_decimal_sign(result, Negative);
  if (sign1 == sign2) set_decimal_sign(result, Positive);
  if (get_decimal_bit(*result, BitsPowerAndSign) == 1) answer = ArithmeticIsBig;
  if (answer == 1 && get_decimal_sign(*result) == 1) answer = ArithmeticIsSmall;
  return answer;
}

int signed_division(decimal value_1, decimal value_2, decimal *result) {
  int overflow = ArithmeticOK;
  int value_1_sign = get_decimal_sign(value_1);
  int value_2_sign = get_decimal_sign(value_2);
  if (value_1_sign == Positive && value_2_sign == Positive) {
    overflow = div_decimals(value_1, value_2, result);
    set_decimal_sign(result, Positive);
  } else if (value_1_sign == Positive && value_2_sign == Negative) {
    overflow = div_decimals(value_1, value_2, result);
    set_decimal_sign(result, Negative);
  } else if (value_1_sign == Negative && value_2_sign == Positive) {
    overflow = div_decimals(value_1, value_2, result);
    set_decimal_sign(result, Negative);
  } else if (value_1_sign == Negative && value_2_sign == Negative) {
    overflow = div_decimals(value_1, value_2, result);
    set_decimal_sign(result, Positive);
  }
  return overflow;
}