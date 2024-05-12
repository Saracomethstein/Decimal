#include "../tools/math_helper/s21_math_tools.h"
#include "../tools/set/s21_set_tools.h"
#include "s21_converters.h"

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int answer = s21_ConvertOK;
  int sign = get_float_sign(src);
  float check_sign =
      (sign == 1) ? -1 : 1;  // otherwise can cause overloading,
                             // so we should make it positive to take int part
  int integer_part_length = (int)(log10f(check_sign * src) + 1);
  set_zero_decimal(dst);

  if (check_errors(src, dst) != 0)
    answer = check_errors(src, dst);
  else if (src == 0.0) {
    answer = s21_ConvertOK;
    set_zero_decimal(dst);
    set_decimal_sign(dst, sign);
  } else {
    if (integer_part_length > SIGNIFICAND_PART)
      round_with_zeroes(src, dst, integer_part_length);
    else
      round_default_float(src, dst, integer_part_length);
    set_decimal_sign(dst, sign);
  }
  return answer;
}

void round_power10(s21_decimal *decimal) {
  s21_decimal tmp = {{10, 0, 0, 0}};
  s21_decimal result;
  set_zero_decimal(&result);

  mul_decimals(*decimal, tmp, &result);
  decimal_copy(result, decimal);
}

int check_errors(float src, s21_decimal *dst) {
  int answer = s21_ConvertOK;
  int sign = src < 0.0 ? 1 : 0;
  if (!dst)
    answer = s21_ConvertERROR;
  else if (src == S21_INFINITY || src == S21_NEGATIVE_INFINITY ||
           src == S21_NAN) {
    answer = s21_ConvertERROR;
    set_zero_decimal(dst);
    set_decimal_sign(dst, sign);
  } else if (fabsf(src) > MAX_FLT) {
    answer = s21_ConvertERROR;
    set_zero_decimal(dst);
    set_decimal_sign(dst, sign);
  } else if (fabsf(src) < MIN_FLT && src != 0) {
    answer = s21_ConvertERROR;
    set_zero_decimal(dst);
    set_decimal_sign(dst, sign);
  }
  return answer;
}

void round_with_zeroes(float src, s21_decimal *dst, int integer_part_length) {
  unsigned int result =
      (unsigned int)(fabsf(src) /
                     pow(10, integer_part_length - SIGNIFICAND_PART));
  int exponent = integer_part_length - SIGNIFICAND_PART;
  dst->bits[0] = result;
  for (int i = 0; i < exponent; ++i) round_power10(dst);
  set_decimal_power(dst, 0);
}

void round_default_float(float src, s21_decimal *dst, int integer_part_length) {
  int sign = get_float_sign(src);
  float check_sign = sign == 1 ? -1 : 1;
  int power_of_ten =
      SIGNIFICAND_PART - integer_part_length;  // calculate properly
  unsigned int integer_part =
      (unsigned int)(round(check_sign * src * pow(10, power_of_ten)));
  if ((int)src == src) {
    dst->bits[0] = (unsigned int)src;
    set_decimal_power(dst, 0);
  } else {
    while (integer_part % 10 == 0) integer_part /= 10;
    int integer_part_len = (int)(log10f(integer_part) + 1);
    dst->bits[0] = integer_part;
    int res_exp = abs(integer_part_length - integer_part_len);
    set_decimal_power(dst, res_exp);  // second param is not correct
  }
}

int get_float_sign(float src) { return src < 0.0 ? 1 : 0; }
