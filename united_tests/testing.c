//
// Created by Rachel Sanford on 2/22/24.
//

#include <check.h>
#include <stdio.h>
#include <string.h>

#include "../decimal.h"

START_TEST(decimal_plus_plus) {
  decimal x = {{0xFFFFFFFF, 0xFFFFFFFF, 0, 0}};
  decimal y = {{1, 0, 0, 0}};
  decimal z = {{0, 0, 0, 0}};
  add_dec(x, y, &z);
  char res1[1000] = "0 0 0 0";
  char res2[1000] = "0 0 1 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(decimal_plus_plus_2) {
  decimal x = {{21, 0, 0, 0}};
  decimal y = {{20, 0, 0, 0}};
  decimal z = {{0, 0, 0, 0}};
  add_dec(x, y, &z);
  char res1[1000], res2[1000] = "41 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(decimal_plus_plus_3) {
  decimal x = {{20, 1, 0, 0}};
  decimal y = {{21, 0, 0, 0}};
  decimal z = {{0, 0, 0, 0}};
  x.bits[3] = 0x80000000;
  y.bits[3] = 0x80000000;
  add_dec(x, y, &z);
  char res1[1000], res2[1000] = "41 1 0 2147483648";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(decimal_plus_plus_4) {
  decimal x = {{20, 1, 0, 0}};
  decimal y = {{21, 0, 0, 0}};
  decimal z = {{0, 0, 0, 0}};
  y.bits[3] = 0x80000000;
  add_dec(x, y, &z);
  char res1[1000], res2[1000] = "4294967295 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(decimal_plus_plus_5) {
  decimal x = {{20, 0, 0, 0}};
  decimal y = {{21, 0, 0, 0}};
  decimal z = {{0, 0, 0, 0}};
  x.bits[3] = 0x80000000;
  add_dec(x, y, &z);
  char res1[1000], res2[1000] = "1 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(decimal_plus_plus_6) {
  decimal x = {{25, 0, 0, 0x80000000}};
  decimal y = {{21, 0, 0, 0}};
  decimal z = {{0, 0, 0, 0}};
  add_dec(x, y, &z);
  char res1[1000], res2[1000] = "4 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(decimal_plus_plus_7) {
  decimal x = {{100, 0, 0, 0}};
  decimal y = {{100, 0, 0, 0}};
  decimal z = {{0, 0, 0, 0}};
  x.bits[3] = 0x80000000;
  add_dec(x, y, &z);
  char res1[1000], res2[1000] = "0 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(decimal_plus_plus_8) {
  decimal x = {{99, 0, 0, 0}};
  decimal y = {{100, 0, 0, 0}};
  decimal z = {{0, 0, 0, 0}};
  y.bits[3] = 0x80000000;

  add_dec(x, y, &z);
  char res1[1000], res2[1000] = "1 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(decimal_plus_plus_9) {
  decimal x = {{0, 0, 300000000, 1835008}};
  decimal y = {{0, 0, 300000000, 1835008}};
  decimal z = {{0, 0, 0, 0}};
  add_dec(x, y, &z);
  char res1[1000], res2[1000] = "0 0 600000000 1835008";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(decimal_plus_plus_10) {
  decimal x = {{0, 0, 3000000000, 0}};
  decimal y = {{0, 0, 3000000000, 0}};
  decimal z = {{0, 0, 0, 0}};
  add_dec(x, y, &z);
  char res1[1000], res2[1000] = "0 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(decimal_plus_plus_11) {
  decimal x = {{1, 0, 0, 1835008}};
  decimal y = {{1, 0, 0, 2149318656}};
  decimal z = {{0, 0, 0, 0}};
  add_dec(x, y, &z);
  char res1[1000], res2[1000] = "0 0 0 1835008";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(decimal_plus_plus_12) {
  decimal x = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  decimal y = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  decimal z = {{0, 0, 0, 0}};
  add_dec(x, y, &z);
  char res1[1000] = "0 0 0 0";
  char res2[1000] = "858993458 858993459 858993459 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(decimal_plus_plus_13) {
  decimal x = {{1, 0, 0, 0}};
  decimal y = {{2, 0, 0, 0x20000}};
  decimal z = {{0, 0, 0, 0}};
  add_dec(x, y, &z);
  char res1[1000] = "0 0 0 0";
  char res2[1000] = "102 0 0 131072";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(decimal_plus_plus_14) {
  decimal x = {{1, 0, 0, 0x1C0000}};
  decimal y = {{20000000, 0, 0, 0}};
  decimal z = {{0, 0, 0, 0}};
  add_dec(x, y, &z);
  char res1[1000] = "0 0 0 0";
  char res2[1000] = "2147483648 2364136404 1046034848 1507328";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

/* ----------------------------------------------------------------
 * is_less    <
 * ---------------------------------------------------------------- */

START_TEST(decimal_is_less_1) {
  decimal x = {{4294967295, 0, 0, 0}};
  decimal y = {{0, 1, 0, 0}};
  int res1 = is_less(x, y);
  int res2 = True;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_less_2) {
  decimal x = {{0, 0, 1, 0}};
  decimal y = {{0, 0, 2, 0}};
  int res1 = is_less(y, x);
  int res2 = False;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_less_3) {
  decimal x = {{0, 0, 1, 0}};
  decimal y = {{0, 0, 1, 0}};
  int res1 = is_less(y, x);
  int res2 = False;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_less_4) {
  decimal x = {{0, 0, 1, 0}};
  decimal y = {{0, 0, 2, 0}};
  x.bits[3] = 0x80000000;
  y.bits[3] = 0x80000000;
  int res1 = is_less(x, y);
  int res2 = False;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_less_5) {
  decimal x = {{0, 0, 1, 0}};
  decimal y = {{0, 0, 2, 0}};
  //    x.bits[3] = 0x80000000;
  y.bits[3] = 0x80000000;
  int res1 = is_less(y, x);
  int res2 = True;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_less_6) {
  decimal x = {{0, 0, 1, 0}};
  decimal y = {{0, 0, 1, 0}};
  x.bits[3] = 0x80000000;
  y.bits[3] = 0x80000000;

  int res1 = is_less(y, x);
  int res2 = False;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_less_7) {
  decimal x = {{0, 0, 1, 0x80000000}};
  decimal y = {{0, 0, 1, 0}};
  int res1 = is_less(x, y);
  int res2 = True;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_less_8) {
  decimal x = {{0, 0, 1, 0}};
  decimal y = {{0, 0, 1, 0}};
  y.bits[3] = 0x80000000;

  int res1 = is_less(x, y);
  int res2 = 0;
  ck_assert_int_eq(res1, res2);
}
END_TEST

/* ----------------------------------------------------------------
 * 21_is_less_or_equal    <=
 * ---------------------------------------------------------------- */

START_TEST(decimal_is_less_or_equal_1) {
  decimal x = {{0, 0, 1, 0}};
  decimal y = {{0, 0, 2, 0}};
  int res1 = is_less_or_equal(x, y);
  int res2 = True;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_less_or_equal_2) {
  decimal x = {{0, 0, 1, 0}};
  decimal y = {{0, 0, 2, 0}};
  int res1 = is_less_or_equal(y, x);
  int res2 = False;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_less_or_equal_or_equal_3) {
  decimal x = {{0, 0, 1, 0}};
  decimal y = {{0, 0, 1, 0}};
  int res1 = is_less_or_equal(y, x);
  int res2 = True;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_less_or_equal_4) {
  decimal x = {{0, 0, 1, 0}};
  decimal y = {{0, 0, 2, 0}};
  x.bits[3] = 0x80000000;
  y.bits[3] = 0x80000000;

  int res1 = is_less_or_equal(x, y);
  int res2 = False;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_less_or_equal_5) {
  decimal x = {{0, 0, 1, 0}};
  decimal y = {{0, 0, 2, 0}};
  x.bits[3] = 0x80000000;

  int res1 = is_less_or_equal(x, y);
  int res2 = True;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_less_or_equal_6) {
  decimal x = {{0, 0, 1, 0}};
  decimal y = {{0, 0, 1, 0}};
  x.bits[3] = 0x80000000;
  y.bits[3] = 0x80000000;

  int res1 = is_less_or_equal(y, x);
  int res2 = True;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_less_or_equal_7) {
  decimal x = {{0, 0, 1, 0}};
  decimal y = {{0, 0, 1, 0}};
  x.bits[3] = 0x80000000;

  int res1 = is_less_or_equal(x, y);
  int res2 = True;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_less_or_equal_8) {
  decimal x = {{0, 0, 1, 0}};
  decimal y = {{0, 0, 1, 0}};
  y.bits[3] = 0x80000000;

  int res1 = is_less_or_equal(x, y);
  int res2 = False;
  ck_assert_int_eq(res1, res2);
}
END_TEST

// /* ----------------------------------------------------------------
//  * is_greater   >
//  * ---------------------------------------------------------------- */

START_TEST(decimal_is_greater_1) {
  decimal x = {{0, 0, 1, 0}};
  decimal y = {{0, 0, 2, 0}};
  int res1 = is_greater(x, y);
  int res2 = False;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_greater_2) {
  decimal x = {{0, 0, 1, 0}};
  decimal y = {{0, 0, 2, 0}};
  int res1 = is_greater(y, x);
  int res2 = True;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_greater_3) {
  decimal x = {{0, 0, 1, 0}};
  decimal y = {{0, 0, 1, 0}};
  int res1 = is_greater(y, x);
  int res2 = False;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_greater_4) {
  decimal x = {{0, 0, 1, 0}};
  decimal y = {{0, 0, 2, 0}};
  x.bits[3] = 0x80000000;
  y.bits[3] = 0x80000000;

  int res1 = is_greater(x, y);
  int res2 = True;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_greater_5) {
  decimal x = {{0, 0, 1, 0}};
  decimal y = {{0, 0, 2, 0}};
  x.bits[3] = 0x80000000;
  y.bits[3] = 0x80000000;
  int res1 = is_greater(y, x);
  int res2 = False;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_greater_6) {
  decimal x = {{0, 0, 1, 0}};
  decimal y = {{0, 0, 1, 0}};
  x.bits[3] = 0x80000000;
  y.bits[3] = 0x80000000;

  int res1 = is_greater(y, x);
  int res2 = False;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_greater_7) {
  decimal x = {{0, 0, 1, 0}};
  decimal y = {{0, 0, 1, 0}};
  x.bits[3] = 0x80000000;

  int res1 = is_greater(x, y);
  int res2 = False;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_greater_8) {
  decimal x = {{0, 0, 1, 0}};
  decimal y = {{0, 0, 1, 0}};
  y.bits[3] = 0x80000000;

  int res1 = is_greater(x, y);
  int res2 = True;
  ck_assert_int_eq(res1, res2);
}
END_TEST

// /* ----------------------------------------------------------------
//  * 21_is_greater_or_equal   >=
//  * ---------------------------------------------------------------- */

START_TEST(decimal_is_greater_or_equal_1) {
  decimal x = {{0, 0, 1, 0}};
  decimal y = {{0, 0, 2, 0}};
  int res1 = is_greater_or_equal(x, y);
  int res2 = False;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_greater_or_equal_2) {
  decimal x = {{0, 0, 1, 0}};
  decimal y = {{0, 0, 2, 0}};
  int res1 = is_greater_or_equal(y, x);
  int res2 = True;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_greater_or_equal_or_equal_3) {
  decimal x = {{0, 0, 1, 0}};
  decimal y = {{0, 0, 1, 0}};
  int res1 = is_greater_or_equal(y, x);
  int res2 = True;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_greater_or_equal_4) {
  decimal x = {{0, 0, 1, 0}};
  decimal y = {{0, 0, 2, 0}};
  x.bits[3] = 0x80000000;
  y.bits[3] = 0x80000000;

  int res1 = is_greater_or_equal(x, y);
  int res2 = True;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_greater_or_equal_5) {
  decimal x = {{0, 0, 1, 0}};
  decimal y = {{0, 0, 2, 0}};
  x.bits[3] = 0x80000000;
  y.bits[3] = 0x80000000;

  int res1 = is_greater_or_equal(y, x);
  int res2 = False;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_greater_or_equal_6) {
  decimal x = {{0, 0, 1, 0}};
  decimal y = {{0, 0, 1, 0}};
  x.bits[3] = 0x80000000;
  y.bits[3] = 0x80000000;

  int res1 = is_greater_or_equal(y, x);
  int res2 = True;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_greater_or_equal_7) {
  decimal x = {{0, 0, 1, 0}};
  decimal y = {{0, 0, 1, 0}};
  x.bits[3] = 0x80000000;

  int res1 = is_greater_or_equal(x, y);
  int res2 = False;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_greater_or_equal_8) {
  decimal x = {{0, 0, 1, 0}};
  decimal y = {{0, 0, 1, 0}};
  y.bits[3] = 0x80000000;

  int res1 = is_greater_or_equal(x, y);
  int res2 = True;
  ck_assert_int_eq(res1, res2);
}
END_TEST

// /* ----------------------------------------------------------------
//  * is_equal      ==
//  * ---------------------------------------------------------------- */

START_TEST(decimal_is_equal_1) {
  decimal x = {{0, 0, 1, 0}};
  decimal y = {{0, 0, 1, 0}};
  int res1 = is_equal(x, y);
  int res2 = 1;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_equal_2) {
  decimal x = {{0, 0, 1, 0}};
  decimal y = {{0, 0, 1, 0}};
  x.bits[3] = 0x80000000;
  y.bits[3] = 0x80000000;

  int res1 = is_equal(x, y);
  int res2 = 1;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_equal_3) {
  decimal x = {{0, 0, 1, 0}};
  decimal y = {{0, 0, 1, 0}};
  y.bits[3] = 0x80000000;

  int res1 = is_equal(x, y);
  int res2 = 0;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_equal_4) {
  decimal x = {{0, 0, 1, 0}};
  decimal y = {{0, 0, 1, 0}};
  x.bits[3] = 0x80000000;

  int res1 = is_equal(x, y);
  int res2 = 0;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_equal_5) {
  decimal x = {{0, 52, 1, 0}};
  decimal y = {{0, 0, 1, 0}};
  int res1 = is_equal(x, y);
  int res2 = 0;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_equal_6) {
  decimal x = {{0, 0, 1, 0}};
  decimal y = {{1747, 0, 1, 0}};
  int res1 = is_equal(x, y);
  int res2 = 0;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_equal_7) {
  decimal x = {{0, 0, 1, 0}};
  decimal y = {{1747, 0, 1, 0}};
  x.bits[3] = 0x80000000;

  int res1 = is_equal(x, y);
  int res2 = 0;
  ck_assert_int_eq(res1, res2);
}
END_TEST

// /* ----------------------------------------------------------------
//  * is_not_equal     !=
//  * ---------------------------------------------------------------- */

START_TEST(decimal_is_not_equal_1) {
  decimal x = {{0, 0, 1, 0}};
  decimal y = {{0, 0, 1, 0}};
  int res1 = is_not_equal(x, y);
  int res2 = 0;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_not_equal_2) {
  decimal x = {{0, 0, 1, 0}};
  decimal y = {{0, 0, 1, 0}};
  x.bits[3] = 0x80000000;
  y.bits[3] = 0x80000000;

  int res1 = is_not_equal(x, y);
  int res2 = 0;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_not_equal_3) {
  decimal x = {{0, 0, 1, 0}};
  decimal y = {{0, 0, 1, 0}};
  y.bits[3] = 0x80000000;

  int res1 = is_not_equal(x, y);
  int res2 = 1;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_not_equal_4) {
  decimal x = {{0, 0, 1, 0}};
  decimal y = {{0, 0, 1, 0}};
  x.bits[3] = 0x80000000;

  int res1 = is_not_equal(x, y);
  int res2 = 1;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_not_equal_5) {
  decimal x = {{0, 52, 1, 0}};
  decimal y = {{0, 0, 1, 0}};
  int res1 = is_not_equal(x, y);
  int res2 = 1;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_not_equal_6) {
  decimal x = {{0, 0, 1, 0}};
  decimal y = {{1747, 0, 1, 0}};
  int res1 = is_not_equal(x, y);
  int res2 = 1;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_not_equal_7) {
  decimal x = {{0, 0, 1, 0}};
  decimal y = {{1747, 0, 1, 0}};
  x.bits[3] = 0x80000000;

  int res1 = is_not_equal(x, y);
  int res2 = 1;
  ck_assert_int_eq(res1, res2);
}
END_TEST

// /* ----------------------------------------------------------------
//  * int mul_dec(decimal value_1, decimal value_2, decimal *result)
//  * ---------------------------------------------------------------- */

START_TEST(decimal_mul_dec_1) {
  decimal x = {{0, 0, 0, 0xF0000}};
  decimal y = {{0, 0, 0, 0x20000}};
  decimal z = {{0, 0, 0, 0}};
  mul_dec(x, y, &z);
  char res1[1000], res2[1000] = "0 0 0 1114112";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(decimal_mul_dec_2) {
  decimal x = {{2, 0, 0, 0}};
  decimal y = {{5, 0, 0, 0}};
  decimal z = {{0, 0, 0, 0}};
  mul_dec(x, y, &z);
  char res1[1000], res2[1000] = "10 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(decimal_mul_dec_3) {
  decimal x = {{2, 1, 2, 0}};
  decimal y = {{5, 0, 0, 0}};
  decimal z = {{0, 0, 0, 0}};
  mul_dec(x, y, &z);
  char res1[1000], res2[1000] = "10 5 10 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(decimal_mul_dec_4) {
  decimal x = {{2, 0, 0, 0}};
  decimal y = {{0, 0, 10, 0}};
  decimal z = {{0, 0, 0, 0}};
  mul_dec(x, y, &z);
  char res1[1000], res2[1000] = "0 0 20 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(decimal_mul_dec_5) {
  decimal x = {{1000000000, 0, 0, 0}};
  decimal y = {{6, 0, 0, 0}};
  decimal z = {{0, 0, 0, 0}};
  mul_dec(x, y, &z);
  char res1[1000], res2[1000] = "1705032704 1 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(decimal_mul_dec_6) {
  decimal x = {{1000000000, 0, 0, 0}};
  decimal y = {{6, 0, 0, 0}};
  decimal z = {{0, 0, 0, 0}};
  x.bits[3] = 0x80000000;
  y.bits[3] = 0x80000000;
  mul_dec(x, y, &z);
  char res1[1000], res2[1000] = "1705032704 1 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(decimal_mul_dec_7) {
  decimal x = {{1000000000, 0, 0, 0}};
  decimal y = {{6, 0, 0, 0}};
  decimal z = {{0, 0, 0, 0}};
  x.bits[3] = 0x80000000;
  mul_dec(x, y, &z);

  char res1[1000], res2[1000] = "1705032704 1 0 2147483648";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(decimal_mul_dec_8) {
  decimal x = {{1000000000, 0, 0, 0xF0000}};
  decimal y = {{6, 0, 0, 0x80010000}};
  decimal z = {{0, 0, 0, 0}};
  mul_dec(x, y, &z);
  char res1[1000], res2[1000] = "1705032704 1 0 2148532224";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(decimal_mul_dec_9) {
  decimal x = {{1, 0, 0, 0}};
  decimal y = {{165, 22, 6587456, 0}};
  decimal z = {{0, 0, 0, 0}};
  mul_dec(x, y, &z);
  char res1[1000], res2[1000] = "165 22 6587456 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(decimal_mul_dec_10) {
  decimal x = {{400, 0, 0, 0xE0000}};
  decimal y = {{500, 0, 0, 0xE0000}};
  decimal z = {{0, 0, 0, 0}};
  mul_dec(x, y, &z);
  char res1[1000], res2[1000] = "200000 0 0 1835008";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(decimal_mul_dec_11) {
  decimal x = {{0, 0, 555555555, 0}};
  decimal y = {{1, 0, 0, 0x10000}};
  decimal z = {{0, 0, 0, 0}};
  mul_dec(x, y, &z);
  char res1[1000], res2[1000] = "0 0 555555555 65536";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(decimal_mul_dec_14) {
  decimal x = {{500, 0, 0, 0x00110000}};
  decimal y = {{500, 0, 0, 0x00220000}};
  decimal z = {{0, 0, 0, 0}};
  int ans = mul_dec(x, y, &z);
  char res1[1000], res2[1000] = "0 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(ans, 4);
}
END_TEST

START_TEST(decimal_mul_dec_16) {
  decimal src1, src2;
  int a = 9403;
  int b = 202;
  int res_our_dec = 0;
  from_int_to_decimal(a, &src1);
  from_int_to_decimal(b, &src2);
  int res_origin = 1899406;
  decimal res_od;
  mul_dec(src1, src2, &res_od);
  from_decimal_to_int(res_od, &res_our_dec);
  ck_assert_int_eq(res_our_dec, res_origin);
}
END_TEST

START_TEST(decimal_mul_dec_17) {
  decimal src1, src2;
  double a = 457755754335745;
  double b = 457755543574511;
  from_float_to_decimal(a, &src1);
  from_float_to_decimal(b, &src2);
  decimal res_od = {0};
  int err = mul_dec(src1, src2, &res_od);
  char res1[1000], res2[1000] = "0 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", res_od.bits[0],
           res_od.bits[1], res_od.bits[2], res_od.bits[3]);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(err, 1);
}
END_TEST

// /* ----------------------------------------------------------------
//  * sub_dec    вычитание
//  * ---------------------------------------------------------------- */

START_TEST(decimal_sub_dec_1) {
  decimal x = {{1, 0, 0, 0}};
  decimal y = {{1, 0, 0, 0}};
  decimal z = {{0, 0, 0, 0}};
  sub_dec(x, y, &z);
  char res1[1000], res2[1000] = "0 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(decimal_sub_dec_2) {
  decimal x = {{2, 0, 0, 0}};
  decimal y = {{1, 0, 0, 0}};
  decimal z = {{0, 0, 0, 0}};
  sub_dec(x, y, &z);
  char res1[1000], res2[1000] = "1 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(decimal_sub_dec_3) {
  decimal x = {{1, 0, 0, 0}};
  decimal y = {{2, 0, 0, 0}};
  decimal z = {{0, 0, 0, 0}};
  sub_dec(x, y, &z);
  char res1[1000], res2[1000] = "1 0 0 2147483648";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(decimal_sub_dec_4) {
  decimal x = {{2, 0, 0, 0}};
  decimal y = {{2, 0, 0, 0}};
  decimal z = {{0, 0, 0, 0}};
  x.bits[3] = 0x80000000;
  y.bits[3] = 0x80000000;
  sub_dec(x, y, &z);
  char res1[1000], res2[1000] = "0 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(decimal_sub_dec_5) {
  decimal x = {{1, 0, 0, 0}};
  decimal y = {{2, 0, 0, 0}};
  decimal z = {{0, 0, 0, 0}};
  x.bits[3] = 0x80000000;
  y.bits[3] = 0x80000000;

  sub_dec(x, y, &z);
  char res1[1000], res2[1000] = "1 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(decimal_sub_dec_6) {
  decimal x = {{2, 0, 0, 0}};
  decimal y = {{1, 0, 0, 0}};
  decimal z = {{0, 0, 0, 0}};
  x.bits[3] = 0x80000000;
  y.bits[3] = 0x80000000;

  sub_dec(x, y, &z);
  char res1[1000], res2[1000] = "1 0 0 2147483648";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(decimal_sub_dec_7) {
  decimal x = {{2, 0, 0, 0}};
  decimal y = {{1, 0, 0, 0}};
  decimal z = {{0, 0, 0, 0}};
  y.bits[3] = 0x80000000;

  sub_dec(x, y, &z);
  char res1[1000], res2[1000] = "3 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(decimal_sub_dec_8) {
  decimal x = {{2, 0, 0, 0}};
  decimal y = {{1, 0, 0, 0}};
  decimal z = {{0, 0, 0, 0}};
  x.bits[3] = 0x80000000;

  sub_dec(x, y, &z);
  char res1[1000], res2[1000] = "3 0 0 2147483648";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(decimal_sub_dec_9) {
  decimal x = {{0, 0, 5, 0x80000000}};
  decimal y = {{0, 0, 4, 0}};
  decimal z = {{0, 0, 0, 0}};
  sub_dec(x, y, &z);
  char res1[1000], res2[1000] = "0 0 9 2147483648";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(decimal_sub_dec_10) {
  decimal x = {{0, 0, 3000000000, 0x80000000}};
  decimal y = {{0, 0, 3000000001, 0}};

  decimal z = {{0, 0, 0, 0}};
  sub_dec(x, y, &z);
  char res1[1000], res2[1000] = "0 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(decimal_sub_dec_11) {
  decimal x = {{1, 0, 0, 0x8001C000}};
  decimal y = {{1, 0, 0, 0x8001C000}};

  decimal z = {{0, 0, 0, 0}};
  sub_dec(x, y, &z);
  char res1[1000], res2[1000] = "0 0 0 65536";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(decimal_sub_dec_12) {
  decimal x = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  decimal y = {{1, 0, 0, 0}};

  decimal z = {{0, 0, 0, 0}};
  sub_dec(x, y, &z);
  char res1[1000], res2[1000] = "4294967294 4294967295 4294967295 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(decimal_sub_dec_13) {
  decimal x = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  decimal y = {{6, 0, 0, 0x10000}};

  decimal z = {{0, 0, 0, 0}};
  sub_dec(x, y, &z);
  char res1[1000], res2[1000] = "4294967294 4294967295 4294967295 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

// /* ----------------------------------------------------------------
//  * from_int_to_decimal;
//  * ---------------------------------------------------------------- */

START_TEST(from_int_to_decimal_1) {
  decimal x = {{0, 0, 0, 0}};
  decimal y = {{15, 0, 0, 0}};
  int z = 15;
  from_int_to_decimal(z, &x);
  char res1[1000], res2[1000];
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", x.bits[0], x.bits[1],
           x.bits[2], x.bits[3]);
  snprintf(res2, sizeof(char) * 1000, "%u %u %u %u", y.bits[0], y.bits[1],
           y.bits[2], y.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(from_int_to_decimal_2) {
  decimal x = {{0, 0, 0, 0}};
  decimal y = {{15, 0, 0, 2147483648}};
  int z = -15;
  from_int_to_decimal(z, &x);
  char res1[1000], res2[1000];
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", x.bits[0], x.bits[1],
           x.bits[2], x.bits[3]);
  snprintf(res2, sizeof(char) * 1000, "%u %u %u %u", y.bits[0], y.bits[1],
           y.bits[2], y.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(from_int_to_decimal_3) {
  decimal x = {{0, 0, 0, 0}};
  decimal y = {{0, 0, 0, 0}};
  int z = 0;
  from_int_to_decimal(z, &x);
  char res1[1000], res2[1000];
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", x.bits[0], x.bits[1],
           x.bits[2], x.bits[3]);
  snprintf(res2, sizeof(char) * 1000, "%u %u %u %u", y.bits[0], y.bits[1],
           y.bits[2], y.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

// /* ----------------------------------------------------------------
//  * from_decimal_to_int;
//  * ---------------------------------------------------------------- */

START_TEST(from_decimal_to_int_1) {
  decimal x = {{150, 0, 0, 0x80000000}};
  int y;
  from_decimal_to_int(x, &y);
  ck_assert_int_eq(y, -150);
}
END_TEST

START_TEST(from_decimal_to_int_2) {
  decimal x = {{150, 0, 0, 0x10000}};

  int y;
  from_decimal_to_int(x, &y);
  ck_assert_int_eq(y, 15);
}
END_TEST

START_TEST(from_decimal_to_int_3) {
  decimal x = {{150, 0, 0, 0xA0000}};

  int y = 0;
  from_decimal_to_int(x, &y);
  ck_assert_int_eq(y, 0);
}
END_TEST

START_TEST(from_decimal_to_int_4) {
  decimal x = {{2100000000, 0, 0, 0}};

  int y;
  from_decimal_to_int(x, &y);
  ck_assert_int_eq(y, 2100000000);
}
END_TEST

START_TEST(from_decimal_to_int_5) {
  decimal x = {{2100000000, 0, 0, 0x80000000}};

  int y;
  from_decimal_to_int(x, &y);
  ck_assert_int_eq(y, -2100000000);
}
END_TEST

START_TEST(from_decimal_to_int_6) {
  decimal x = {{3100000000, 0, 0, 0x80000000}};

  int y = 0;
  from_decimal_to_int(x, &y);
  ck_assert_int_eq(y, 0);
}
END_TEST

START_TEST(from_decimal_to_int_7) {
  decimal x = {{3100000000, 0, 0, 0}};

  int y;
  int n1 = from_decimal_to_int(x, &y);
  ck_assert_int_eq(n1, 1);
}
END_TEST

START_TEST(from_decimal_to_int_8) {
  decimal x = {{9, 0, 0, 0x10000}};

  int y;
  from_decimal_to_int(x, &y);
  ck_assert_int_eq(y, 0);
}
END_TEST

START_TEST(from_decimal_to_int_9) {
  decimal x = {{9, 0, 0, 0x10000}};

  int y = from_decimal_to_int(x, NULL);
  ck_assert_int_eq(y, 1);
}
END_TEST

START_TEST(from_decimal_to_int_10) {
  decimal x = {{0, 0, 0, 0x80000000}};
  int res;
  int y = from_decimal_to_int(x, &res);
  ck_assert_int_eq(res, -0);
  ck_assert_int_eq(y, 0);
}
END_TEST

START_TEST(from_decimal_to_int_11) {
  decimal x = {{0, 0, 0, 0}};
  int res;
  int y = from_decimal_to_int(x, &res);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(y, 0);
}
END_TEST

// /* ----------------------------------------------------------------
//  * div_dec;
//  * ---------------------------------------------------------------- */

START_TEST(div_dec_1) {
  decimal x = {{3100000000, 0, 0, 0}};
  decimal y = {{1, 0, 0, 0}};
  decimal z = {{0, 0, 0, 0}};
  div_dec(x, y, &z);
  char res1[1000], res2[1000] = "3100000000 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(div_dec_2) {
  decimal x = {{1, 0, 0, 0}};
  decimal y = {{2, 0, 0, 0}};
  decimal z = {{0, 0, 0, 0}};
  div_dec(x, y, &z);
  char res1[1000], res2[1000] = "5 0 0 65536";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(div_dec_3) {
  decimal x = {{52525252, 0, 0, 0}};
  decimal y = {{0, 0, 0, 0}};
  decimal z = {{0, 0, 0, 0}};
  int n1 = 0;
  n1 = div_dec(x, y, &z);
  char res1[1000], res2[1000] = "0 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(n1, 3);
}
END_TEST

START_TEST(div_dec_4) {
  decimal x = {{52525252, 0, 0, 0}};
  decimal y = {{0, 0, 0, 0}};
  decimal z = {{0, 0, 0, 0}};
  x.bits[3] = 0x80000000;

  int n1 = 0;
  n1 = div_dec(x, y, &z);
  char res1[1000], res2[1000] = "0 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(n1, 3);
}
END_TEST

START_TEST(div_dec_5) {
  decimal x = {{52525252, 0, 0, 0}};
  decimal y = {{0, 0, 0, 0}};
  decimal z = {{0, 0, 0, 0}};
  y.bits[3] = 0x80000000;

  int n1 = 0;
  n1 = div_dec(x, y, &z);
  char res1[1000], res2[1000] = "0 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(n1, 3);
}
END_TEST

START_TEST(div_dec_6) {
  decimal x = {{52525252, 0, 0, 8845}};
  decimal y = {{0, 0, 0, 10}};
  decimal z = {{0, 0, 0, 0}};
  int n1 = 0;
  n1 = div_dec(x, y, &z);
  char res1[1000], res2[1000] = "0 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(n1, 3);
}
END_TEST

START_TEST(div_dec_7) {
  decimal x = {{52525252, 0, 0, 65465}};
  decimal y = {{0, 0, 0, 9598595}};
  decimal z = {{0, 0, 0, 0}};
  int n1 = 0;
  n1 = div_dec(x, y, &z);
  char res1[1000], res2[1000] = "0 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(n1, 3);
}
END_TEST

START_TEST(div_dec_8) {
  decimal x = {{5, 0, 0, 0}};
  decimal y = {{3, 0, 0, 0x140000}};
  decimal z = {{0, 0, 0, 0}};

  int n1 = 0;
  n1 = div_dec(x, y, &z);
  char res1[1000], res2[1000] = "2192222891 173768805 90350181 524288";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(n1, 0);
}
END_TEST

START_TEST(div_dec_9) {
  decimal x = {{5, 0, 0, 0}};
  decimal y = {{3, 0, 0, 0x80140000}};
  decimal z = {{0, 0, 0, 0}};
  int n1 = 0;
  n1 = div_dec(x, y, &z);
  char res1[1000], res2[1000] = "2192222891 173768805 90350181 2148007936";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(n1, 0);
}
END_TEST

START_TEST(div_dec_10) {
  decimal x = {{5, 0, 0, 0x80000000}};
  decimal y = {{3, 0, 0, 0x140000}};
  decimal z = {{0, 0, 0, 0}};
  int n1 = 0;
  n1 = div_dec(x, y, &z);
  char res1[1000], res2[1000] = "2192222891 173768805 90350181 2148007936";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(n1, 0);
}
END_TEST

START_TEST(div_dec_11) {
  decimal x = {{5, 0, 0, 0x80000000}};
  decimal y = {{3, 0, 0, 0x80140000}};
  decimal z = {{0, 0, 0, 0}};
  int n1 = 0;
  n1 = div_dec(x, y, &z);
  char res1[1000], res2[1000] = "2192222891 173768805 90350181 524288";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(n1, 0);
}
END_TEST

START_TEST(div_dec_12) {
  decimal x = {{5, 0, 50, 0x80000000}};
  decimal y = {{5, 0, 0, 0x80140000}};
  decimal z = {{0, 0, 0, 0}};

  int n1 = 0;
  n1 = div_dec(x, y, &z);
  char res1[1000], res2[1000] = "0 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(n1, 1);
}
END_TEST

START_TEST(div_dec_13) {
  decimal x = {{0, 0, 0, 0x80000000}};
  decimal y = {{5, 0, 0, 0x80140000}};
  decimal z = {{0, 0, 0, 0}};

  int n1 = 0;
  n1 = div_dec(x, y, &z);
  char res1[1000], res2[1000] = "0 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(n1, 0);
}
END_TEST

START_TEST(div_dec_14) {
  decimal x = {{5, 0, 0, 0x80000000}};
  decimal y = {{0, 0, 0, 0x801C0000}};
  decimal z = {{0, 0, 0, 0}};

  int n1 = 0;
  n1 = div_dec(x, y, &z);
  char res1[1000], res2[1000] = "0 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(n1, 3);
}
END_TEST

START_TEST(div_dec_15) {
  decimal x = {{5, 0, 0, 0x801C0000}};
  decimal y = {{5, 0, 0, 0x801C0000}};
  decimal z = {{0, 0, 0, 0}};

  div_dec(x, y, &z);
  char res1[1000], res2[1000] = "1 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(div_dec_16) {
  decimal x = {{5, 0, 0, 0}};
  decimal y = {{0, 0, 0, 0}};
  decimal z = {{0, 0, 0, 0}};

  div_dec(x, y, &z);
  char res1[1000], res2[1000] = "0 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

// /* ----------------------------------------------------------------
//  * from_float_to_decimal;
//  * ---------------------------------------------------------------- */

START_TEST(from_float_to_decimal_1) {
  float src = 56.986;
  decimal z = {{0, 0, 0, 0}};
  int n1 = from_float_to_decimal(src, &z);
  char res1[1000], res2[1000] = "56986 0 0 196608";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(n1, 0);
}
END_TEST

START_TEST(from_float_to_decimal_2) {
  float src = 1.0 / 0.0;
  decimal z = {{0, 0, 0, 0}};
  int n1 = from_float_to_decimal(src, &z);
  char res1[1000], res2[1000] = "0 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(n1, 1);
}
END_TEST

START_TEST(from_float_to_decimal_3) {
  float src = -1.596;
  decimal z = {{0, 0, 0, 0}};
  int n1 = from_float_to_decimal(src, &z);
  char res1[1000], res2[1000] = "1596 0 0 2147680256";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(n1, 0);
}
END_TEST

START_TEST(from_float_to_decimal_4) {
  float src = 1 / 0.0;
  decimal z = {{0, 0, 0, 0}};
  int n1 = from_float_to_decimal(src, &z);
  char res1[1000], res2[1000] = "0 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(n1, 1);
}
END_TEST

START_TEST(from_float_to_decimal_5) {
  float src = 0;
  decimal z = {{0, 0, 0, 0}};
  int n1 = from_float_to_decimal(src, &z);
  char res1[1000], res2[1000] = "0 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(n1, 0);
}
END_TEST

START_TEST(from_float_to_decimal_6) {
  long double src = 0;
  decimal z = {{0, 0, 0, 0}};
  int n1 = from_float_to_decimal(src, &z);
  char res1[1000], res2[1000] = "0 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(n1, 0);
}
END_TEST

START_TEST(from_float_to_decimal_7) {
  float src = MAX_FLT * 2;
  decimal z = {{0, 0, 0, 0}};
  int n1 = from_float_to_decimal(src, &z);
  char res1[1000], res2[1000] = "0 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(n1, 1);
}
END_TEST

START_TEST(from_float_to_decimal_8) {
  float src = MIN_FLT * 0.1;
  decimal z = {{0, 0, 0, 0}};
  int n1 = from_float_to_decimal(src, &z);
  char res1[1000], res2[1000] = "0 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(n1, 1);
}
END_TEST

START_TEST(from_float_to_decimal_9) {
  float src = 1.0;
  decimal z = {{0, 0, 0, 0}};
  int n1 = from_float_to_decimal(src, &z);
  char res1[1000], res2[1000] = "1 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(n1, 0);
}
END_TEST

// /* ----------------------------------------------------------------
//  * from_decimal_to_float;
//  * ---------------------------------------------------------------- */

START_TEST(from_decimal_to_float_1) {
  decimal x = {{15008, 0, 0, 0x30000}};

  float res1;
  int n1 = from_decimal_to_float(x, &res1);
  float res2 = 15.008;
  ck_assert_float_eq(res1, res2);
  ck_assert_int_eq(n1, 0);
}
END_TEST

START_TEST(from_decimal_to_float_2) {
  decimal x = {{15008, 0, 0, 0x80030000}};

  float res1;
  int n1 = from_decimal_to_float(x, &res1);
  float res2 = -15.008;
  ck_assert_float_eq(res1, res2);
  ck_assert_int_eq(n1, 0);
}
END_TEST

START_TEST(from_decimal_to_float_3) {
  decimal x = {{15008, 0, 0, 0x80030000}};

  float res1 = 0;
  int n1 = from_decimal_to_float(x, NULL);
  float res2 = 0;
  ck_assert_float_eq(res1, res2);
  ck_assert_int_eq(n1, 1);
}
END_TEST

START_TEST(from_decimal_to_float_4) {
  decimal x = {{0, 0, 0, 0x80000000}};

  float res1;
  int n1 = from_decimal_to_float(x, &res1);
  float res2 = -0.0;
  ck_assert_float_eq(res1, res2);
  ck_assert_int_eq(n1, 0);
}
END_TEST

START_TEST(from_decimal_to_float_5) {
  decimal x = {{0, 0, 0, 0}};

  float res1;
  int n1 = from_decimal_to_float(x, &res1);
  float res2 = 0.0;
  ck_assert_float_eq(res1, res2);
  ck_assert_int_eq(n1, 0);
}
END_TEST

// /* ----------------------------------------------------------------
//  * negate_dec;
//  * ---------------------------------------------------------------- */

START_TEST(negate_dec_1) {
  decimal x = {{100, 0, 0, 0}};
  decimal z = {{0, 0, 0, 0}};
  x.bits[3] = 0x80000000;

  negate_dec(x, &z);
  char res1[1000], res2[1000] = "100 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(negate_dec_2) {
  decimal x = {{100, 0, 0, 0}};
  decimal z = {{0, 0, 0, 0}};
  negate_dec(x, &z);
  char res1[1000], res2[1000] = "100 0 0 2147483648";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(negate_dec_3) {
  decimal x = {{0, 0, 0, 0}};
  decimal z = {{0, 0, 0, 0}};
  int err = negate_dec(x, &z);
  ck_assert_int_eq(err, 0);
}
END_TEST

// /* ----------------------------------------------------------------
//  * truncate_dec;
//  * ---------------------------------------------------------------- */

START_TEST(truncate_dec_1) {
  decimal x = {{15008, 0, 0, 0x80030000}};

  decimal z = {{0, 0, 0, 0}};
  truncate_dec(x, &z);
  char res1[1000], res2[1000] = "15 0 0 2147483648";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(truncate_dec_2) {
  decimal x = {{15008, 0, 0, 0x00020000}};

  decimal z = {{0, 0, 0, 0}};
  truncate_dec(x, &z);
  char res1[1000], res2[1000] = "150 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

/* ----------------------------------------------------------------
 * floor_dec;
 * ---------------------------------------------------------------- */

START_TEST(floor_dec_1) {
  decimal x = {{15008, 0, 0, 0x80030000}};

  decimal z = {{0, 0, 0, 0}};
  floor_dec(x, &z);
  char res1[1000], res2[1000] = "16 0 0 2147483648";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(floor_dec_2) {
  decimal x = {{15008, 0, 0, 0x30000}};

  decimal z = {{0, 0, 0, 0}};
  floor_dec(x, &z);
  char res1[1000], res2[1000] = "15 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(floor_dec_3) {
  decimal x = {{15008, 0, 0, 0x800A0000}};

  decimal z = {{0, 0, 0, 0}};
  floor_dec(x, &z);
  char res1[1000], res2[1000] = "1 0 0 2147483648";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(floor_dec_4) {
  decimal x = {{15008, 0, 0, 0x801D0000}};
  decimal z = {{0, 0, 0, 0}};
  int err = floor_dec(x, &z);
  char res1[1000], res2[1000] = "1 0 0 2147483648";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(err, 0);
}
END_TEST

// /* ----------------------------------------------------------------
//  * round_dec;
//  * ---------------------------------------------------------------- */

START_TEST(round_dec_1) {
  decimal x = {{95008, 0, 0, 0}};

  decimal z = {{0, 0, 0, 0}};
  round_dec(x, &z);
  char res1[1000], res2[1000] = "95008 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(round_dec_2) {
  decimal x = {{95008, 0, 0, 0x10000}};

  decimal z = {{0, 0, 0, 0}};
  round_dec(x, &z);
  char res1[1000], res2[1000] = "9501 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(round_dec_3) {
  decimal x = {{95008, 0, 0, 0x20000}};

  decimal z = {{0, 0, 0, 0}};
  round_dec(x, &z);
  char res1[1000], res2[1000] = "950 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(round_dec_4) {
  decimal x = {{95008, 0, 0, 0x40000}};

  decimal z = {{0, 0, 0, 0}};
  round_dec(x, &z);
  char res1[1000], res2[1000] = "10 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(round_dec_5) {
  decimal x = {{95008, 0, 0, 0x50000}};

  decimal z = {{0, 0, 0, 0}};
  round_dec(x, &z);
  char res1[1000], res2[1000] = "1 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(round_dec_6) {
  decimal x = {{95008, 0, 0, 0x60000}};

  decimal z = {{0, 0, 0, 0}};
  round_dec(x, &z);
  char res1[1000], res2[1000] = "0 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(round_dec_7) {
  decimal x = {{95008, 0, 0, 0x80000000}};

  decimal z = {{0, 0, 0, 0}};
  round_dec(x, &z);
  char res1[1000], res2[1000] = "95008 0 0 2147483648";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(round_dec_8) {
  decimal x = {{95008, 0, 0, 0x80010000}};

  decimal z = {{0, 0, 0, 0}};
  round_dec(x, &z);
  char res1[1000], res2[1000] = "9501 0 0 2147483648";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(round_dec_9) {
  decimal x = {{95008, 0, 0, 0x80020000}};

  decimal z = {{0, 0, 0, 0}};
  round_dec(x, &z);
  char res1[1000], res2[1000] = "950 0 0 2147483648";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(round_dec_10) {
  decimal x = {{95008, 0, 0, 0x80040000}};

  decimal z = {{0, 0, 0, 0}};
  round_dec(x, &z);
  char res1[1000], res2[1000] = "10 0 0 2147483648";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(round_dec_11) {
  decimal x = {{95008, 0, 0, 0x80050000}};

  decimal z = {{0, 0, 0, 0}};
  round_dec(x, &z);
  char res1[1000], res2[1000] = "1 0 0 2147483648";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(round_dec_12) {
  decimal x = {{95008, 0, 0, 0x80060000}};

  decimal z = {{0, 0, 0, 0}};
  round_dec(x, &z);
  char res1[1000], res2[1000] = "0 0 0 2147483648";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

int main(void) {
  Suite *s1 = suite_create("Core");
  TCase *tc1_1 = tcase_create("Core");
  SRunner *sr = srunner_create(s1);
  int nf;

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, decimal_plus_plus);
  tcase_add_test(tc1_1, decimal_plus_plus_2);
  tcase_add_test(tc1_1, decimal_plus_plus_3);
  tcase_add_test(tc1_1, decimal_plus_plus_4);
  tcase_add_test(tc1_1, decimal_plus_plus_5);
  tcase_add_test(tc1_1, decimal_plus_plus_6);
  tcase_add_test(tc1_1, decimal_plus_plus_7);
  tcase_add_test(tc1_1, decimal_plus_plus_8);
  tcase_add_test(tc1_1, decimal_plus_plus_9);
  tcase_add_test(tc1_1, decimal_plus_plus_10);
  tcase_add_test(tc1_1, decimal_plus_plus_11);
  tcase_add_test(tc1_1, decimal_plus_plus_12);
  tcase_add_test(tc1_1, decimal_plus_plus_13);
  tcase_add_test(tc1_1, decimal_plus_plus_14);
  tcase_add_test(tc1_1, decimal_is_less_1);
  tcase_add_test(tc1_1, decimal_is_less_2);
  tcase_add_test(tc1_1, decimal_is_less_3);
  tcase_add_test(tc1_1, decimal_is_less_4);
  tcase_add_test(tc1_1, decimal_is_less_5);
  tcase_add_test(tc1_1, decimal_is_less_6);
  tcase_add_test(tc1_1, decimal_is_less_7);
  tcase_add_test(tc1_1, decimal_is_less_8);
  tcase_add_test(tc1_1, decimal_is_less_or_equal_1);
  tcase_add_test(tc1_1, decimal_is_less_or_equal_2);
  tcase_add_test(tc1_1, decimal_is_less_or_equal_or_equal_3);
  tcase_add_test(tc1_1, decimal_is_less_or_equal_4);
  tcase_add_test(tc1_1, decimal_is_less_or_equal_5);
  tcase_add_test(tc1_1, decimal_is_less_or_equal_6);
  tcase_add_test(tc1_1, decimal_is_less_or_equal_7);
  tcase_add_test(tc1_1, decimal_is_less_or_equal_8);
  tcase_add_test(tc1_1, decimal_is_greater_1);
  tcase_add_test(tc1_1, decimal_is_greater_2);
  tcase_add_test(tc1_1, decimal_is_greater_3);
  tcase_add_test(tc1_1, decimal_is_greater_4);
  tcase_add_test(tc1_1, decimal_is_greater_5);
  tcase_add_test(tc1_1, decimal_is_greater_6);
  tcase_add_test(tc1_1, decimal_is_greater_7);
  tcase_add_test(tc1_1, decimal_is_greater_8);
  tcase_add_test(tc1_1, decimal_is_greater_or_equal_1);
  tcase_add_test(tc1_1, decimal_is_greater_or_equal_2);
  tcase_add_test(tc1_1, decimal_is_greater_or_equal_or_equal_3);
  tcase_add_test(tc1_1, decimal_is_greater_or_equal_4);
  tcase_add_test(tc1_1, decimal_is_greater_or_equal_5);
  tcase_add_test(tc1_1, decimal_is_greater_or_equal_6);
  tcase_add_test(tc1_1, decimal_is_greater_or_equal_7);
  tcase_add_test(tc1_1, decimal_is_greater_or_equal_8);
  tcase_add_test(tc1_1, decimal_is_equal_1);
  tcase_add_test(tc1_1, decimal_is_equal_2);
  tcase_add_test(tc1_1, decimal_is_equal_3);
  tcase_add_test(tc1_1, decimal_is_equal_4);
  tcase_add_test(tc1_1, decimal_is_equal_5);
  tcase_add_test(tc1_1, decimal_is_equal_6);
  tcase_add_test(tc1_1, decimal_is_equal_7);
  tcase_add_test(tc1_1, decimal_is_not_equal_1);
  tcase_add_test(tc1_1, decimal_is_not_equal_2);
  tcase_add_test(tc1_1, decimal_is_not_equal_3);
  tcase_add_test(tc1_1, decimal_is_not_equal_4);
  tcase_add_test(tc1_1, decimal_is_not_equal_5);
  tcase_add_test(tc1_1, decimal_is_not_equal_6);
  tcase_add_test(tc1_1, decimal_is_not_equal_7);
  tcase_add_test(tc1_1, decimal_mul_dec_1);
  tcase_add_test(tc1_1, decimal_mul_dec_2);
  tcase_add_test(tc1_1, decimal_mul_dec_3);
  tcase_add_test(tc1_1, decimal_mul_dec_4);
  tcase_add_test(tc1_1, decimal_mul_dec_5);
  tcase_add_test(tc1_1, decimal_mul_dec_6);
  tcase_add_test(tc1_1, decimal_mul_dec_7);
  tcase_add_test(tc1_1, decimal_mul_dec_8);
  tcase_add_test(tc1_1, decimal_mul_dec_9);
  tcase_add_test(tc1_1, decimal_mul_dec_10);
  tcase_add_test(tc1_1, decimal_mul_dec_11);
  tcase_add_test(tc1_1, decimal_mul_dec_14);
  tcase_add_test(tc1_1, decimal_mul_dec_16);
  tcase_add_test(tc1_1, decimal_mul_dec_17);
  tcase_add_test(tc1_1, decimal_sub_dec_1);
  tcase_add_test(tc1_1, decimal_sub_dec_2);
  tcase_add_test(tc1_1, decimal_sub_dec_3);
  tcase_add_test(tc1_1, decimal_sub_dec_4);
  tcase_add_test(tc1_1, decimal_sub_dec_5);
  tcase_add_test(tc1_1, decimal_sub_dec_6);
  tcase_add_test(tc1_1, decimal_sub_dec_7);
  tcase_add_test(tc1_1, decimal_sub_dec_8);
  tcase_add_test(tc1_1, decimal_sub_dec_9);
  tcase_add_test(tc1_1, decimal_sub_dec_10);
  tcase_add_test(tc1_1, decimal_sub_dec_11);
  tcase_add_test(tc1_1, decimal_sub_dec_12);
  tcase_add_test(tc1_1, decimal_sub_dec_13);
  tcase_add_test(tc1_1, from_int_to_decimal_1);
  tcase_add_test(tc1_1, from_int_to_decimal_2);
  tcase_add_test(tc1_1, from_int_to_decimal_3);
  tcase_add_test(tc1_1, from_decimal_to_int_1);
  tcase_add_test(tc1_1, from_decimal_to_int_2);
  tcase_add_test(tc1_1, from_decimal_to_int_3);
  tcase_add_test(tc1_1, from_decimal_to_int_4);
  tcase_add_test(tc1_1, from_decimal_to_int_5);
  tcase_add_test(tc1_1, from_decimal_to_int_6);
  tcase_add_test(tc1_1, from_decimal_to_int_7);
  tcase_add_test(tc1_1, from_decimal_to_int_8);
  tcase_add_test(tc1_1, from_decimal_to_int_9);
  tcase_add_test(tc1_1, from_decimal_to_int_10);
  tcase_add_test(tc1_1, from_decimal_to_int_11);
  tcase_add_test(tc1_1, div_dec_1);
  tcase_add_test(tc1_1, div_dec_2);
  tcase_add_test(tc1_1, div_dec_3);
  tcase_add_test(tc1_1, div_dec_4);
  tcase_add_test(tc1_1, div_dec_5);
  tcase_add_test(tc1_1, div_dec_6);
  tcase_add_test(tc1_1, div_dec_7);
  tcase_add_test(tc1_1, div_dec_8);
  tcase_add_test(tc1_1, div_dec_9);
  tcase_add_test(tc1_1, div_dec_10);
  tcase_add_test(tc1_1, div_dec_11);
  tcase_add_test(tc1_1, div_dec_12);
  tcase_add_test(tc1_1, div_dec_13);
  tcase_add_test(tc1_1, div_dec_14);
  tcase_add_test(tc1_1, div_dec_15);
  tcase_add_test(tc1_1, div_dec_16);
  tcase_add_test(tc1_1, from_decimal_to_float_1);
  tcase_add_test(tc1_1, from_decimal_to_float_2);
  tcase_add_test(tc1_1, from_decimal_to_float_3);
  tcase_add_test(tc1_1, from_decimal_to_float_4);
  tcase_add_test(tc1_1, from_decimal_to_float_5);
  tcase_add_test(tc1_1, from_float_to_decimal_1);
  tcase_add_test(tc1_1, from_float_to_decimal_2);
  tcase_add_test(tc1_1, from_float_to_decimal_3);
  tcase_add_test(tc1_1, from_float_to_decimal_4);
  tcase_add_test(tc1_1, from_float_to_decimal_5);
  tcase_add_test(tc1_1, from_float_to_decimal_6);
  tcase_add_test(tc1_1, from_float_to_decimal_7);
  tcase_add_test(tc1_1, from_float_to_decimal_8);
  tcase_add_test(tc1_1, from_float_to_decimal_9);
  tcase_add_test(tc1_1, negate_dec_1);
  tcase_add_test(tc1_1, negate_dec_2);
  tcase_add_test(tc1_1, negate_dec_3);
  tcase_add_test(tc1_1, truncate_dec_1);
  tcase_add_test(tc1_1, truncate_dec_2);
  tcase_add_test(tc1_1, floor_dec_1);
  tcase_add_test(tc1_1, floor_dec_2);
  tcase_add_test(tc1_1, floor_dec_3);
  tcase_add_test(tc1_1, floor_dec_4);
  tcase_add_test(tc1_1, round_dec_1);
  tcase_add_test(tc1_1, round_dec_2);
  tcase_add_test(tc1_1, round_dec_3);
  tcase_add_test(tc1_1, round_dec_4);
  tcase_add_test(tc1_1, round_dec_5);
  tcase_add_test(tc1_1, round_dec_6);
  tcase_add_test(tc1_1, round_dec_7);
  tcase_add_test(tc1_1, round_dec_8);
  tcase_add_test(tc1_1, round_dec_9);
  tcase_add_test(tc1_1, round_dec_10);
  tcase_add_test(tc1_1, round_dec_11);
  tcase_add_test(tc1_1, round_dec_12);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}