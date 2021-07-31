#include "matlib.h"
#include <iostream>

//Constructors
    matrix::matrix()
    {
        n = m = 1;
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

    matrix::matrix(const matrix &mat)
    {
        n = mat.n;
        m = mat.m;

        elements = new float* [n];
        for(int i = 0; i < n; i++)
        {
            elements[i] = new float [m];
            for(int j = 0; j < m; j++)
            {
                elements[i][j] = mat.elements[i][j];
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


//Operators

    //Assignmet Operator
    matrix& matrix::operator=(const matrix &mat)
    {
        //Check for self-assignment
        if(this == &mat)
            return *this;
        
        //De-allocate memory
        for(int k = 0; k < n; k++)
        {
            delete [] elements[k];
        }
        delete [] elements;

        //Change dimensions
        n = mat.n;
        m = mat.m;

        //Re-allocate memory and copy information of mat
        elements = new float* [n];
        for(int i = 0; i < n; i++)
        {
            elements[i] = new float [m];
            for(int j = 0; j < m; j++)
            {
                elements[i][j] = mat.elements[i][j];
            }
        }

        //Return left object to support operator chaining
        return *this;
    }

    //Compound Assignment +=
    matrix& matrix::operator+=(const matrix &mat)
    {
        //For now, both matrices must be the same size, otherwise do not change the matrix
        if((this->n != mat.n) || (this->m != mat.m)){
            std::cout << "matrix addition error: dimensions incompatible" << std::endl << std::endl;
            return *this;
        } 

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                this->elements[i][j] += mat.elements[i][j];
            }
        }
        return *this;
    }

    //Compound Assignment -=
    matrix& matrix::operator-=(const matrix &mat)
    {
        //For now, both matrices must be the same size, otherwise do not change the matrix
        if((this->n != mat.n) || (this->m != mat.m)){
            std::cout << "matrix subtraction error: dimensions incompatible" << std::endl << std::endl;
            return *this;
        } 

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                this->elements[i][j] -= mat.elements[i][j];
            }
        }
        return *this;
    }

    //Binary Arithmetic +
    const matrix& matrix::operator+(const matrix &mat) const
    {
        matrix* result = new matrix;
        *result = *this;
        *result += mat;
        return *result;
    }

    //Binary Arithmetic -
    const matrix& matrix::operator-(const matrix &mat) const
    {
        matrix* result = new matrix;
        *result = *this;
        *result -= mat;
        return *result;
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
        matrix* siz = new matrix(1,2);
        siz->elements[0][0] = n;
        siz->elements[0][1] = m;
        return(*siz);
    }

    //Resizes the matrix. All indices which are not removed retain their elements. New elements are set to be 0.
    void matrix::resize(int rows, int cols)
    {
        matrix* temp = new matrix(rows,cols);

        //Copy all relevant elements to new matrix 
        for(int i = 0; (i < n) && (i < rows); i++)
        {
            for(int j = 0; (j < m) && (j < cols); j++)
            {
                temp->elements[i][j] = elements[i][j];
            }
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
        elements = temp->elements;
    }

    //Returns the transpose of a matrix
    matrix matrix::T()
    {
        matrix* tp = new matrix(m,n);
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                tp->elements[i][j] = elements[j][i];
            }
        }
        return(*tp);
        delete tp;
    }

    //Sets the matrix to be its transpose
    void matrix::setT()
    {
        matrix* tp = new matrix(m,n);
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                tp->elements[i][j] = elements[j][i];
            }
        }
        *this = *tp;
        delete tp;
    }

    //Print matrix in console
    void matrix::std_print()
    {
        for(int i = 0; i < n; i++)
        {
            std::cout << "[ ";
            for(int j = 0; j < m; j++)
            {
                std::cout << elements[i][j] << " ";
            }
            std::cout << "]" << std::endl;
        }
        std::cout << std::endl;
    }