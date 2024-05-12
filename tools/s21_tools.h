#ifndef S21_TOOLS_H
#define S21_TOOLS_H

#include <stdio.h>
#include <math.h>

#define S21_INFINITY (float)(1/0.)
#define S21_NEGATIVE_INFINITY (-(float)(1/0.))
#define S21_NAN ((float)0/0.)
#define MAX_FLT 79228162514264337593543950335.f
#define MIN_FLT 1e-28F
#define SIGNIFICAND_PART 7


typedef struct s21_decimal {
    unsigned int bits[4];
} s21_decimal;

typedef enum MaxMinDegree {
    s21_MaxDegree = 28,
    s21_MinDegree = 0,
} MaxMinDegree;

typedef enum AnotherAnswer {
    s21_AnotherOK = 0,
    s21_AnotherERROR = 1,
} AnotherAnswer;

typedef enum ConvertAnswer {
    s21_ConvertOK = 0,
    s21_ConvertERROR = 1,
} ConvertAnswer;

typedef enum CompareAnswer {
    s21_True = 1,
    s21_False = 0,
} CompareAnswer;

typedef enum ArithmeticAnswer {
    s21_ArithmeticOK = 0,
    s21_ArithmeticIsBig = 1,
    s21_ArithmeticIsSmall = 2,
    s21_ArithmeticDivByZero = 3,
    s21_ArithmeticNotCorrect = 4,
} ArithmeticAnswer;


typedef enum ArithmeticSign {
    s21_Positive = 0,
    s21_Negative = 1,
} ArithmeticSign;

typedef enum ByteNumber {
    s21_ZeroByte = 0,
    s21_FirstByte = 1,
    s21_SecondByte = 2,
    s21_ThirdByte = 3,
} ByteNumber;

typedef enum BitsNumber {
    s21_MinBits = 0,
    s21_MaxBits = 31,
} BitsNumber;

typedef enum BitsInfo{
    s21_BitsLow = 0,
    s21_BitsMiddle = 32,
    s21_BitsHigh = 64,
    s21_BitsPowerAndSign = 96,
} BitsInfo;

#endif