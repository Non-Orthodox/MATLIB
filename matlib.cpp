#include "matlib.h"
#include <iostream>
#include <string>
#include <cmath>

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
        
        if((this->n == mat.n) && (this->m == mat.m)){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    this->elements[i][j] = mat.elements[i][j];
                }
            }
            return *this;
        }

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

    //matrix& matrix::operator=(const std::string &str);

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

    //Compound Assignment *=
    matrix& matrix::operator*=(const matrix &mat)
    {
        *this = *this * mat;
        return *this;
    }
    matrix& matrix::operator*=(const float &fl)
    {
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                this->elements[i][j] *= fl;
            }
        }
        return *this;
    }
    matrix& matrix::operator*=(const double &db)
    {
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                this->elements[i][j] *= (float)db;
            }
        }
        return *this;
    }
    matrix& matrix::operator*=(const int &in)
    {
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                this->elements[i][j] *= (float)in;
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

    //Binary Arithmetic *
    const matrix& matrix::operator*(const matrix &mat) const
    {
        if(this->m != mat.n){
            std::cout << "matrix multiplication error: dimensions incompatible" << std::endl;
            return *this;
        }

        matrix* result = new matrix(this->n,mat.m);

        for(int i = 0; i < this->n; i++){
            for(int j = 0; j < mat.m; j++){
                for(int k = 0; k < this->m; k++){
                    result->elements[i][j] += (this->elements[i][k] * mat.elements[k][j]);
                }
            }
        }

        return *result;
    }
    const matrix& matrix::operator*(const float &fl) const
    {
        matrix* result = new matrix(*this);
        *result *= fl;
        return *result;
    }
    const matrix& matrix::operator*(const double &db) const
    {
        matrix* result = new matrix(*this);
        *result *= (float)db;
        return *result;
    }
    const matrix& matrix::operator*(const int &in) const
    {
        matrix* result = new matrix(*this);
        *result *= (float)in;
        return *result;
    }

    //Unary operator - (multiplies all elements by -1)
    matrix& matrix::operator-() const
    {
        matrix* result = new matrix(n,m);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                result->elements[i][j] = this->elements[i][j]*(-1);
            }
        }
        return *result;
    }

    //Brackets [int] returns the column given by int
    matrix& matrix::operator[](const int col) const
    {
        matrix* vector = new matrix(this->n,1);
        for(int i = 0; i < n; i++){
            vector->elements[i][1] = this->elements[i][col];
        }
        return *vector;
    }

    //Logical Comparison ==
    bool matrix::operator==(const matrix &mat) const
    {
        if((this->n != mat.n) || (this->m != mat.m)){
            return false;
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(this->elements[i][j] != mat.elements[i][j]){
                    return false;
                }
            }
        }
        return true;
    }

    //Logical Comparison !=
    bool matrix::operator!=(const matrix &mat) const
    {
        return !(*this == mat);
    }


//Member Functions

    //Returns element (r,c) as a float
    float matrix::at(int r, int c)
    {
        if((r >= n) || (c >= m)){
            std::cout << "matrix .at error: indices out of bounds" << std::endl;
            return 0;
        }
        return(elements[r][c]);
    }

    //Returns n
    int matrix::rows()
    {
        return this->n;
    }

    //Returns m
    int matrix::cols()
    {
        return this->m;
    }

    //Set element (r,c) to a specified value val
    void matrix::set(int r, int c, float val)
    {
        if((r<n) && (c<m)){
            elements[r][c] = val;
        }
    }

    //Returns size of matrix, as a 1x2 matrix representing [n m]
    matrix matrix::size()
    {
        matrix* siz = new matrix(1,2);
        siz->elements[0][0] = n;
        siz->elements[0][1] = m;
        return(*siz);
    }

    //Returns dimension n or m of matrix, depending on if dim is 1 or 2, respectively. Returns 0 otherwise.
    int matrix::size(int dim)
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


//Produces an n x n identity matrix, with n as the input
matrix& eye(int dim)
{
    if(dim <= 0){
        matrix* err = new matrix;
        err->set(0,0,dim);
        return *err;
    }

    matrix* id = new matrix(dim,dim);
    for(int i = 0; i < dim; i++){
        id->set(dim,dim,1);
    }
    return *id;
}

//Produces a matrix of ones, with dimensions specified as inputs
matrix& ones(int rows, int cols)
{
    if((rows < 1) || (cols < 1)){
        matrix* err = new matrix;
        return *err;
    }

    matrix* ones = new matrix(rows,cols);
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            ones->set(i,j,1);
        }
    }

    return *ones;
}

//Finds the magnitude of a vector (so the matrix must be n x 1)
float vecNorm(matrix &mat)
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
matrix& householder(matrix &mat)
{
    matrix* u = new matrix(mat.rows(),1);
    u->set(0,0,vecNorm(mat[0]));
    *u = mat[0] - *u;
    
    matrix* HH = new matrix;
    *HH = eye(mat.cols());
    *HH -= (*u) * ((*u).T()) * 2;
    return *HH;
}