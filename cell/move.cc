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
    d_exit = tmp.d_exit;
    d_start = tmp.d_start;
    d_character = tmp.d_character;
    d_QValue = tmp.d_QValue;
    tmp.d_x = 0;
    tmp.d_y = 0;
    tmp.d_reward = 0;
    tmp.d_character = 0;
    tmp.d_border = NULL;
    tmp.d_start = NULL;
    tmp.d_exit = NULL;
    tmp.d_QValue = nullptr;
}
