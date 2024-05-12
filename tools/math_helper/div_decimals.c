#include "../../converters/s21_converters.h"
#include "../../operators_comparison/s21_operators_comparison.h"
#include "../get/s21_get_tools.h"
#include "../set/s21_set_tools.h"
#include "s21_math_tools.h"

void bank_for_div(s21_decimal val, s21_decimal *result) {
  set_decimal_power(&val, 1);
  bank(val, result);
}

int div_decimals(s21_decimal value_1, s21_decimal value_2,
                 s21_decimal *result) {
  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal temp = {{0, 0, 0, 0}};
  s21_decimal check_overflow = {{0, 0, 0, 0}};
  int answer = s21_ArithmeticOK;
  int value_1_degree = get_decimal_power(value_1);
  int value_2_degree = get_decimal_power(value_2);
  set_decimal_sign(&value_1, s21_Positive);
  set_decimal_sign(&value_2, s21_Positive);
  int res_degree = value_1_degree - value_2_degree;

  while ((res_degree < s21_MaxDegree && res_degree >= 0) ||
         s21_abs_equal(value_1, decimal_zero()) != s21_True) {
    decimal_copy(value_2, &temp);
    s21_decimal multiple = {{1, 0, 0, 0}};
    if (s21_abs_greater_or_equal(value_1, value_2) == s21_True) {
      while (s21_abs_greater_or_equal(
                 value_1, mul_decimals_return(temp, decimal_two(), temp)) ==
                 s21_True &&
             mul_decimals(temp, decimal_two(), &check_overflow) !=
                 s21_ArithmeticIsBig) {
        mul_decimals(temp, decimal_two(), &temp);
        mul_decimals(multiple, decimal_two(), &multiple);
      }
      sub_decimals(value_1, temp, &value_1);
      add_decimals(res, multiple, &res);
    } else {
      if (s21_abs_greater(value_1, decimal_zero()) == s21_True &&
          s21_abs_less(value_1, value_2) == s21_True) {
        while (s21_abs_greater(value_1, value_2) != s21_True &&
               res_degree < s21_MaxDegree) {
          mul_decimals(res, decimal_ten(), &res);
          mul_decimals(value_1, decimal_ten(), &value_1);
          mul_decimals(*result, decimal_ten(), result);
          res_degree++;
        }
        add_decimals(*result, res, result);
        if (s21_abs_greater_or_equal(*result, decimal_trunc_max()) ==
                s21_True ||
            res_degree >= s21_MaxDegree) {
          div_decimal_integers(res, decimal_ten(), &res);
          add_decimals(*result, res, result);
          bank_for_div(*result, result);
          break;
        }
        set_zero_decimal(&res);
      } else if (res_degree > s21_MaxDegree ||
                 s21_abs_equal(value_1, decimal_zero()) == s21_True) {
        add_decimals(*result, res, result);
        set_zero_decimal(&res);
        break;
      }
    }
  }
  set_decimal_power(result, abs(res_degree));
  if (result->bits[0] == 0 && result->bits[1] == 0 && result->bits[2] == 0) {
    set_decimal_power(result, 0);
    answer = s21_ArithmeticIsBig;
  }
  return answer;
}

int div_decimal_integers(s21_decimal value_1, s21_decimal value_2,
                         s21_decimal *result) {
  int answer = s21_ArithmeticOK;
  s21_decimal copy = {0};
  s21_decimal tmp = {{0}};
  if (value_2.bits[0] == 0 && value_2.bits[1] == 0 && value_2.bits[2] == 0)
    answer = s21_ArithmeticDivByZero;
  int sign1 = get_decimal_sign(value_1), sign2 = get_decimal_sign(value_2);
  int exp = get_decimal_power(value_1) - get_decimal_power(value_2);
  set_decimal_power(&value_1, s21_MinDegree);
  set_decimal_power(&value_2, s21_MinDegree);
  set_decimal_sign(&value_1, s21_Positive);
  set_decimal_sign(&value_2, s21_Positive);
  decimal_copy(value_2, &copy);
  set_zero_decimal(result);
  int i = s21_BitsPowerAndSign - 1;
  int j = s21_BitsPowerAndSign - 1;
  while (get_decimal_bit(value_2, j) != 1) {
    j--;
  }
  while (get_decimal_bit(value_1, i) != 1) {
    i--;
  }
  while (i >= j) {
    left_shift(&value_2, i - j);
    if (s21_abs_greater_or_equal(value_1, value_2)) {
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
    set_decimal_power(result, s21_MinDegree);
    exp = abs(exp);
    int multiply = (int)pow(10, exp);
    s21_from_int_to_decimal(multiply, &tmp);
    mul_decimals(*result, tmp, result);
  }
  if (sign1 != sign2) set_decimal_sign(result, s21_Negative);
  if (sign1 == sign2) set_decimal_sign(result, s21_Positive);
  if (get_decimal_bit(*result, s21_BitsPowerAndSign) == 1)
    answer = s21_ArithmeticIsBig;
  if (answer == 1 && get_decimal_sign(*result) == 1)
    answer = s21_ArithmeticIsSmall;
  return answer;
}

int signed_division(s21_decimal value_1, s21_decimal value_2,
                    s21_decimal *result) {
  int overflow = s21_ArithmeticOK;
  int value_1_sign = get_decimal_sign(value_1);
  int value_2_sign = get_decimal_sign(value_2);
  if (value_1_sign == s21_Positive && value_2_sign == s21_Positive) {
    overflow = div_decimals(value_1, value_2, result);
    set_decimal_sign(result, s21_Positive);
  } else if (value_1_sign == s21_Positive && value_2_sign == s21_Negative) {
    overflow = div_decimals(value_1, value_2, result);
    set_decimal_sign(result, s21_Negative);
  } else if (value_1_sign == s21_Negative && value_2_sign == s21_Positive) {
    overflow = div_decimals(value_1, value_2, result);
    set_decimal_sign(result, s21_Negative);
  } else if (value_1_sign == s21_Negative && value_2_sign == s21_Negative) {
    overflow = div_decimals(value_1, value_2, result);
    set_decimal_sign(result, s21_Positive);
  }
  return overflow;
}