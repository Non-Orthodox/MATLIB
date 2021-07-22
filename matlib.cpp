#include "matlib.h"
#include <iostream>

//Constructors
    matrix::matrix()
    {
        elements = new float* [1];
        elements[0] = new float [1];
        elements[0][0] = 0;
    }

    matrix::matrix(int height, int width)
    {
        //make sure to check if dimensions are positive numbers
        n = height;
        m = width;
        
        elements = new float* [n];
        for(int i = 0; i < n; i++)
        {
            elements[i] = new float [m];
            for(int j = 0; j < m; j++)
            {
                elements[i][j] = 0;
            }
        }
    }


//Destructor
    matrix::~matrix()
    {
        for(int i = 0; i < n; i++)
        {
            delete [] elements[i];
        }
        delete [] elements;
    }


//Member Functions

    //Returns element (r,c) as a float
    float matrix::at(int r, int c)
    {
        return(elements[r][c]);
    }

    //Returns size of matrix, as a 1x2 matrix representing [n m]
    matrix matrix::size()
    {
        matrix siz(1,2);
        siz.elements[0][0] = n;
        siz.elements[0][1] = m;
        return(siz);
    }

    //Resizes the matrix. All indices which are not removed retain their elements. New elements are set to be 0.
    void matrix::resize(int rows, int cols)
    {
        matrix temp(rows,cols);

        //Copy all relevant elements to new matrix 
        for(int i = 0; (i < n) && (i < rows); i++)
        {
            for(int j = 0; (j < m) && (j < cols); j++)
            {
                temp.elements[i][j] = elements[i][j];

                std::cout << temp.elements[i][j] << " "; //TEMP
            }
            std::cout << std::endl; //TEMP
        }
        
        //Delete old pointers
        for(int k = 0; k < n; k++)
        {
            delete [] elements[k];
        }
        delete [] elements;

        //Set new sizes
        n = rows;
        m = cols;
        
        //Set elements
        elements = temp.elements;
    }