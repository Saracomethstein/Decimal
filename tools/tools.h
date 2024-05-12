#ifndef TOOLS_H
#define TOOLS_H

#include <stdio.h>
#include <math.h>

#define INFINITY_DEC (float)(1/0.)
#define NEGATIVE_INFINITY_DEC (-(float)(1/0.))
#define NAN_DEC ((float)0/0.)
#define MAX_FLT 79228162514264337593543950335.f
#define MIN_FLT 1e-28F
#define SIGNIFICAND_PART 7


typedef struct decimal {
    unsigned int bits[4];
} decimal;

typedef enum MaxMinDegree {
    MaxDegree = 28,
    MinDegree = 0,
} MaxMinDegree;

typedef enum AnotherAnswer {
    AnotherOK = 0,
    AnotherERROR = 1,
} AnotherAnswer;

typedef enum ConvertAnswer {
    ConvertOK = 0,
    ConvertERROR = 1,
} ConvertAnswer;

typedef enum CompareAnswer {
    True = 1,
    False = 0,
} CompareAnswer;

typedef enum ArithmeticAnswer {
    ArithmeticOK = 0,
    ArithmeticIsBig = 1,
    ArithmeticIsSmall = 2,
    ArithmeticDivByZero = 3,
    ArithmeticNotCorrect = 4,
} ArithmeticAnswer;


typedef enum ArithmeticSign {
    Positive = 0,
    Negative = 1,
} ArithmeticSign;

typedef enum ByteNumber {
    ZeroByte = 0,
    FirstByte = 1,
    SecondByte = 2,
    ThirdByte = 3,
} ByteNumber;

typedef enum BitsNumber {
    MinBits = 0,
    MaxBits = 31,
} BitsNumber;

typedef enum BitsInfo{
    BitsLow = 0,
    BitsMiddle = 32,
    BitsHigh = 64,
    BitsPowerAndSign = 96,
} BitsInfo;

#endif