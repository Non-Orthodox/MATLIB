#include <iostream>
#include <string>
#include <cmath>
#include "cdouble.h"
#include "matlib.h"

int main()
{
    // matrix x(3,3);
    // x.set(0,0,0);
    // x.set(1,0,2);
    // x.set(2,0,1);
    // x.set(0,1,0);
    // x.set(1,1,2);
    // x.set(2,1,0);
    // x.set(0,2,5);
    // x.set(1,2,3);
    // x.set(2,2,4);
    // x.std_print();

    // matrix y = x.inverse();

    matrix x(eye(3));
    x *= 2;
    x.std_print();

    matrix y = x^5;
    y.std_print();

    //write interpreter cpp file with list class
    return 0;
}