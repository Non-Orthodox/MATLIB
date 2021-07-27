#include <iostream>
#include "matlib.h"

int main()
{
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

    matrix mat2;
    mat2 = mat;
    mat2.std_print();

    //This section does not work
    matrix transpose;
    transpose = mat.T();
    std::cout << "set transpose" << std::endl; //does not run this line
    transpose.std_print();

    return 0;
}