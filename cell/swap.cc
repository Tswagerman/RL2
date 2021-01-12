//#define XERR
#include "cell.ih"

void cell::swap(cell &other)
{
    d_x = other.d_x;
    d_y = other.d_y;
    d_reward = other.d_reward;
    d_border = other.d_border;
    d_exit = other.d_exit;
    d_start = other.d_start;
    d_character = other.d_character;
    d_QValue = new float[SIZE];
    memcpy(d_QValue, other.d_QValue, sizeof(float) * SIZE);
}
