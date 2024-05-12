#include "../tools/math_helper/math_tools.h"
#include "../tools/set/set_tools.h"
#include "converters.h"

int from_float_to_decimal(float src, decimal *dst) {
  int answer = ConvertOK;
  int sign = get_float_sign(src);
  float check_sign =
      (sign == 1) ? -1 : 1;  // otherwise can cause overloading,
                             // so we should make it positive to take int part
  int integer_part_length = (int)(log10f(check_sign * src) + 1);
  set_zero_decimal(dst);

  if (check_errors(src, dst) != 0)
    answer = check_errors(src, dst);
  else if (src == 0.0) {
    answer = ConvertOK;
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

void round_power10(decimal *value) {
  decimal tmp = {{10, 0, 0, 0}};
  decimal result;
  set_zero_decimal(&result);

  mul_decimals(*value, tmp, &result);
  decimal_copy(result, value);
}

int check_errors(float src, decimal *dst) {
  int answer = ConvertOK;
  int sign = src < 0.0 ? 1 : 0;
  if (!dst)
    answer = ConvertERROR;
  else if (src == INFINITY_DEC || src == NEGATIVE_INFINITY_DEC ||
           src == NAN_DEC) {
    answer = ConvertERROR;
    set_zero_decimal(dst);
    set_decimal_sign(dst, sign);
  } else if (fabsf(src) > MAX_FLT) {
    answer = ConvertERROR;
    set_zero_decimal(dst);
    set_decimal_sign(dst, sign);
  } else if (fabsf(src) < MIN_FLT && src != 0) {
    answer = ConvertERROR;
    set_zero_decimal(dst);
    set_decimal_sign(dst, sign);
  }
  return answer;
}

void round_with_zeroes(float src, decimal *dst, int integer_part_length) {
  unsigned int result =
      (unsigned int)(fabsf(src) /
                     pow(10, integer_part_length - SIGNIFICAND_PART));
  int exponent = integer_part_length - SIGNIFICAND_PART;
  dst->bits[0] = result;
  for (int i = 0; i < exponent; ++i) round_power10(dst);
  set_decimal_power(dst, 0);
}

void round_default_float(float src, decimal *dst, int integer_part_length) {
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
