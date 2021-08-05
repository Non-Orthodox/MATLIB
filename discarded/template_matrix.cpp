#include "matrix.h"
#include <iostream>
#include <string>
#include <cmath>

//Constructors
    template<class Tp>
    matrix<Tp>::matrix()
    {
        n = m = 1;
        elements = new Tp* [1];
        elements[0] = new Tp [1];
        elements[0][0] = 0;
    }

    template<class Tp>
    matrix<Tp>::matrix(int height, int width)
    {
        if((height < 1) || (width < 1)){
            n = m = 1;
        } else{
            n = height;
            m = width;
        }
        
        elements = new Tp* [n];
        for(int i = 0; i < n; i++)
        {
            elements[i] = new Tp [m];
            for(int j = 0; j < m; j++)
            {
                elements[i][j] = 0;
            }
        }
    }

    template<class Tp>
    matrix<Tp>::matrix(const matrix &mat)
    {
        n = mat.n;
        m = mat.m;

        elements = new Tp* [n];
        for(int i = 0; i < n; i++)
        {
            elements[i] = new Tp [m];
            for(int j = 0; j < m; j++)
            {
                elements[i][j] = mat.elements[i][j];
            }
        }
    }


//Destructor
    template<class Tp>
    matrix<Tp>::~matrix()
    {
        for(int i = 0; i < n; i++)
        {
            delete [] elements[i];
        }
        delete [] elements;
    }


//Member Functions

    //Returns element (r,c) as a float
    template<class Tp>
    Tp matrix<Tp>::at(int r, int c)
    {
        if((r >= n) || (c >= m) || (r < 1) || (c < 1)){
            std::cout << "matrix .at error: indices out of bounds" << std::endl;
            return 0;
        }
        return(elements[r][c]);
    }

    //Returns n
    template<class Tp>
    int matrix<Tp>::rows()
    {
        return this->n;
    }

    //Returns m
    template<class Tp>
    int matrix<Tp>::cols()
    {
        return this->m;
    }

    //Set element (r,c) to a specified value val
    template<class Tp>
    void matrix<Tp>::set(int r, int c, Tp val)
    {
        if((r<n) && (c<m)){
            elements[r][c] = val;
        }
    }

    //Returns size of matrix, as a 1x2 matrix representing [n m]
    template<class Tp>
    matrix<Tp> matrix<Tp>::size()
    {
        matrix<int>* siz = new matrix<int>(1,2); //change from int?
        siz->elements[0][0] = n;
        siz->elements[0][1] = m;
        return(*siz);
    }

    //Returns dimension n or m of matrix, depending on if dim is 1 or 2, respectively. Returns 0 otherwise.
    template<class Tp>
    int matrix<Tp>::size(int dim)
    {
        if(dim == 1){
            return n;
        }
        if(dim == 2){
            return m;
        }
        return 0;
    }

    //Resizes the matrix. All indices which are not removed retain their elements. New elements are set to be 0.
    template<class Tp>
    void matrix<Tp>::resize(int rows, int cols)
    {
        matrix<Tp>* temp = new matrix<Tp>(rows,cols);

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
    template<class Tp>
    matrix<Tp> matrix<Tp>::T()
    {
        matrix<Tp>* tp = new matrix<Tp>(m,n);
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
    template<class Tp>
    void matrix<Tp>::setT()
    {
        matrix<Tp>* tp = new matrix<Tp>(m,n);
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
    template<class Tp>
    void matrix<Tp>::std_print()
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


//Produces an n x n identity matrix, with n as the input
template<class Tp>
matrix<Tp>& eye(int dim)
{
    if(dim <= 0){
        matrix<Tp>* err = new matrix<Tp>;
        err->set(0,0,dim);
        return *err;
    }

    matrix<Tp>* id = new matrix<Tp>(dim,dim);
    for(int i = 0; i < dim; i++){
        id->set(dim,dim,1);
    }
    return *id;
}

//Produces a matrix of ones, with dimensions specified as inputs
template<class Tp>
matrix<Tp>& ones(int rows, int cols)
{
    if((rows < 1) || (cols < 1)){
        matrix<Tp>* err = new matrix<Tp>;
        return *err;
    }

    matrix<Tp>* ones = new matrix<Tp>(rows,cols);
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            ones->set(i,j,1);
        }
    }

    return *ones;
}

//Finds the magnitude of a vector (so the matrix must be n x 1)
template<class Tp>
Tp vecNorm(matrix<Tp> &mat)
{
    float result = 0;
    
    if(mat.cols() != 1){
        return 1;
    }

    for(int i = 0; i < mat.rows(); i++){
        result += (mat.at(i,0) * mat.at(i,0));
    }

    return sqrt(result);
}

//Returns householder matrix for transforming the first column of the input matrix (x) into a vector of the form [ ||x|| 0 ... 0 ]^T
template<class Tp>
matrix<Tp>& householder(matrix<Tp> &mat)
{
    matrix<Tp>* u = new matrix<Tp>(mat.rows(),1);
    u->set(0,0,vecNorm(mat[0]));
    *u = mat[0] - *u;
    
    matrix<Tp>* HH = new matrix<Tp>;
    *HH = eye(mat.cols());
    *HH -= (*u) * ((*u).T()) * 2;
    return *HH;
}