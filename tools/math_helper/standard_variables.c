#include "math_tools.h"

decimal decimal_zero() {
  decimal zero = {{0, 0, 0, 0}};
  return zero;
}

decimal decimal_one() {
  decimal one = {{1, 0, 0, 0}};
  return one;
}

decimal decimal_two() {
  decimal two = {{2, 0, 0, 0}};
  return two;
}

decimal decimal_five() {
  decimal five = {{5, 0, 0, 0}};
  return five;
}

decimal decimal_ten() {
  decimal ten = {{10, 0, 0, 0}};
  return ten;
}

decimal decimal_negative() {
  decimal negative = {{1, 0, 0, 0x80000000}};
  return negative;
}

decimal decimal_trunc_max() {
  decimal trunc_max = {{0x99999999, 0x99999999, 0x19999999, 0}};
  return trunc_max;
}