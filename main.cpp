#include <iostream>
#include "matlib.h"

int main()
{
    matrix mat;
    mat.elements[0][0] = 500.6;

    mat.resize(2,2);
    std::cout << mat.at(0,0) << " " << mat.at(0,1) << " " << mat.at(1,0) << " " << mat.at(1,1) << std::endl;

    matrix siz(1,2);
    siz = mat.size();

    //std::cout << "size is: " << siz.at(0,0) << " " << siz.at(0,1) << std::endl;

    for(int i = 0; i < 2; i++)
    {
        mat.elements[i][i] = 1.0;
        //std::cout << "stuff" << std::endl; //does not print right now
        //std::cout << mat.elements[i][0] << " " << mat.elements[i][1] << std::endl;
    }

    return 0;
}