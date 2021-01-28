/*//#define XERR
#include "cell.ih"

void cell::setQValueB(float* newQValue)
{
    for (size_t inc = 0; inc < SIZE; ++inc)
        d_QValueB[inc] = newQValue[inc];
}*/
