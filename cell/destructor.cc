//#define XERR
#include "cell.ih"

cell::~cell()
{
    //cout << "Cell Destroyed!" << " reward = " << d_reward << endl;
    delete[] d_QValue;
}
