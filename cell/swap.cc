//#define XERR
#include "cell.ih"

void cell::swap(cell &other)
{
    d_x = other.d_x;
    d_y = other.d_y;
    d_reward = other.d_reward;
    d_border = other.d_border;
    d_start = other.d_start;
    d_QValue = new float[4];
    memcpy(d_QValue, other.d_QValue, 4);
}
