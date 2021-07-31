#include <iostream>
#include "matlib.h"
#include <string>

int main()
{
    //make a function to edit elements rather than editing them directly!
    matrix mat(3,3);
    mat.elements[1][0] = 10;
    mat.elements[0][1] = 1;
    mat.elements[1][1] = 11;
    mat.elements[2][1] = 21;
    mat.elements[1][2] = 12;
    mat.elements[2][0] = 20;
    mat.elements[0][2] = 2;
    mat.elements[2][2] = 22;
    mat.std_print();

    //identity test
    matrix mat2(3,1);
    mat2.elements[0][0] = 1;
    mat2.elements[1][0] = 1;
    mat2.elements[2][0] = 1;
    mat2.std_print();

    matrix mat3 = mat;
    mat3 *= mat2;
    mat3.std_print();

    return 0;
}