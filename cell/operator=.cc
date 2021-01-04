//#define XERR
#include "cell.ih"

cell &cell::operator=(cell const &other)
//:
{
    cout << "=operator" << endl;
    cell tmp(other);
    swap(tmp);
    return *this;
}
