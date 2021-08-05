#include <iostream>
#include <string>
#include <cmath>
#include "cdouble.h"
#include "matlib.h"

int main()
{
    matrix x(2,2);
    x.set(0,0,3);
    x.set(1,1,3);
    x.set(0,1,4);
    x.set(1,0,4);
    x.std_print();

    matrix y = householder(x);
    y.std_print();

    y *= x;
    y.std_print();

    //write interpreter cpp file with list class
    return 0;
}