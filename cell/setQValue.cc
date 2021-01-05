//#define XERR
#include "cell.ih"

void cell::setQValue(float* newQValue)
{
    for (size_t inc = 0; inc < SIZE; ++inc)
        d_QValue[inc] = newQValue[inc];
}
