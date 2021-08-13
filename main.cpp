#include <iostream>
#include <string>
#include <cmath>
#include "cdouble.h"
#include "matlib.h"

int main()
{
    // //PROBLEM: returns zeros
    // cdouble x(8.0,-4.0);
    // x = x.inv();
    // x.rect_print();
    // x.polar_print();

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

    matrix x(3,3);
    x.adr_print();

    //write interpreter cpp file with list class
    return 0;
}