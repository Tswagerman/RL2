//#define XERR
#include "cell.ih"

cell::cell(cell&& tmp)
//:   
{
    cout << "Moved!" << endl;
    d_x = tmp.d_x;
    d_y = tmp.d_y;
    d_reward = tmp.d_reward;
    d_border = tmp.d_border;
    d_start = tmp.d_start;
    tmp.d_x = 0;
    tmp.d_y = 0;
    tmp.d_reward = 0;
    tmp.d_border = NULL;
    tmp.d_start = NULL;
    tmp.d_QValue = nullptr;
}
