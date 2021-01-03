//#define XERR
#include "cell.ih"

void cell::print() const
{
    cout << "Width = " << d_x << " Height = " << d_y << " reward = "<< d_reward 
        << " border = " << d_border << endl << endl;
}
