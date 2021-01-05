//#define XERR
#include "cell.ih"

void cell::print() const
{
    cout << "Width = " << d_x << " Height = " << d_y << " reward = "<< d_reward 
        << " border = " << d_border << endl << endl;
    for (size_t idx = 0; idx < SIZE; ++idx)
        cout << "Q value at " << idx << " = " << d_QValue[idx] << endl;
}
