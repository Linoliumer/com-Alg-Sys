#pragma once
#include <vector>
#include "RatioNumbers/generalRatioNumber.h"

struct POLINOM{
    long long int olderCoef;
    std::vector<numberR> arrayNum;
};
typedef struct POLINOM polinom;

void correct(polinom& number1);

