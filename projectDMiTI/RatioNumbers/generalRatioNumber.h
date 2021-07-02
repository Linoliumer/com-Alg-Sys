#pragma once
#include "NaturalNumbera/generalNatNum.h"
#include "IntegerNumbers/generalZNum.h"
#include <vector>
struct numberRatio
{
    NaturalNumber natural;
    numberZ whole;
};
typedef struct numberRatio numberR;

numberR XtoRArrayX(int whole, unsigned long long natural);
