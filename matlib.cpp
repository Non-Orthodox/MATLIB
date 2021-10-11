#include "matlib.h"
#include <iostream>
#include <string>
#include <cmath>
#include <utility>

//Constructors
    matrix::matrix()
        : n(1)
        , m(1)
        , elements(new double* [1])
    {
        elements[0] = new double [1];
        elements[0][0] = 0;
    }

    matrix::matrix(int dim)
    {
        if(dim < 1){
            std::cout << "matrix::matrix(int) error: dimensions invalid" << std::endl;
            n = m = 1;
        } else{
            n = m = dim;
        }
        
        elements = new double* [n];
        for(int i = 0; i < n; i++)
        {
            elements[i] = new double [m];
            for(int j = 0; j < m; j++)
            {
                elements[i][j] = 0;
            }
        }
    }

    matrix::matrix(int height, int width)
    {
        if((height < 1) || (width < 1)){
            std::cout << "matrix::matrix(int,int) error: dimensions invalid" << std::endl;
            n = m = 1;
        } else{
            n = height;
            m = width;
        }
        
        elements = new double* [n];
        for(int i = 0; i < n; i++)
        {
            elements[i] = new double [m];
            for(int j = 0; j < m; j++)
            {
                elements[i][j] = 0;
            }
        }
    }

    matrix::matrix(const matrix &mat)
        : n(mat.n)
        , m(mat.m)
    {
        elements = new double* [n];
        for(int i = 0; i < n; i++)
        {
            elements[i] = new double [m];
            for(int j = 0; j < m; j++)
            {
                elements[i][j] = mat.elements[i][j];
            }
        }
    }

    matrix::matrix(matrix &&mat)
        : elements(nullptr)
        , n(0)
        , m(0)
    {
        n = mat.n;
        m = mat.m;
        elements = mat.elements;

        for(int i = 0; i < n; i++){
            mat.elements[i] = nullptr;
        }
        mat.elements = nullptr;

        mat.n = mat.m = 0;
    }

    //Experimental
    // matrix::matrix(const matrix &mat, int col)
    //     : n(mat.n)
    //     , m(1)
    // {
    //     elements = new double* [n];
    //     for(int i = 0; i < n; i++){
    //         elements[i] = new double [1];
    //         elements[i] = &(mat.elements[i][col]);
    //     }
    // }

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
        elements = new double* [n];
        for(int i = 0; i < n; i++)
        {
            elements[i] = new double [m];
            for(int j = 0; j < m; j++)
            {
                elements[i][j] = mat.elements[i][j];
            }
        }

        //Return left object to support operator chaining
        return *this;
    }

    matrix& matrix::operator=(matrix &&mat)
    {
        if(this != &mat){
            for(int k = 0; k < n; k++)
            {
                delete [] elements[k];
            }
            delete [] elements;

            n = mat.n;
            m = mat.m;
            elements = mat.elements;
            
            for(int i = 0; i < n; i++){
                mat.elements[i] = nullptr;
            }
            mat.elements = nullptr;
            mat.n = mat.m = 0;
        }
        return *this;
    }

    //Sets matrix elements according to syntax "[a11 a12; a21 a22]"
    matrix& matrix::operator=(const std::string &&str)
    {
        //TODO
        return *this;
    }

    //matrix& matrix::operator=(const double) TODO

    //Compound Assignment +=
    matrix& matrix::operator+=(const matrix &mat)
    {
        //For now, both matrices must be the same size, otherwise do not change the matrix
        if((this->n != mat.n) || (this->m != mat.m)){
            std::cout << "matrix addition error: dimensions incompatible" << std::endl << std::endl;
            return zeros(1);
        } 

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                this->elements[i][j] += mat.elements[i][j];
            }
        }
        return *this;
    }
    matrix& matrix::operator+=(const double &db)
    {
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                this->elements[i][j] += db;
            }
        }
        return *this;
    }
    matrix& matrix::operator+=(const float &fl)
    {
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                this->elements[i][j] += (double)fl;
            }
        }
        return *this;
    }
    matrix& matrix::operator+=(const int &in)
    {
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                this->elements[i][j] += (double)in;
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
            return zeros(1);
        } 

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                this->elements[i][j] -= mat.elements[i][j];
            }
        }
        return *this;
    }
    matrix& matrix::operator-=(const double &db)
    {
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                this->elements[i][j] -= db;
            }
        }
        return *this;
    }
    matrix& matrix::operator-=(const float &fl)
    {
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                this->elements[i][j] -= (double)fl;
            }
        }
        return *this;
    }
    matrix& matrix::operator-=(const int &in)
    {
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                this->elements[i][j] -= (double)in;
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
    matrix& matrix::operator*=(const double &db)
    {
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                this->elements[i][j] *= db;
            }
        }
        return *this;
    }
    matrix& matrix::operator*=(const float &fl)
    {
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                this->elements[i][j] *= (double)fl;
            }
        }
        return *this;
    }
    matrix& matrix::operator*=(const int &in)
    {
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                this->elements[i][j] *= (double)in;
            }
        }
        return *this;
    }

    //Compound Assignment /=
    matrix& matrix::operator/=(const matrix &mat)
    {
        if(this->m != mat.n){
            std::cout << "matrix operator/ error: dimensions incompatible" << std::endl;
            return zeros(1);
        }

        *this *= mat.inv();
        return *this;
    }
    matrix& matrix::operator/=(const double &db)
    {
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                this->elements[i][j] /= db;
            }
        }
        return *this;
    }
    matrix& matrix::operator/=(const float &fl)
    {
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                this->elements[i][j] /= (double)fl;
            }
        }
        return *this;
    }
    matrix& matrix::operator/=(const int &in)
    {
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                this->elements[i][j] /= (double)in;
            }
        }
        return *this;
    }

    //Compound Assignment ^=
    matrix& matrix::operator^=(const int &exp)
    {
        *this = *this ^ exp;
        return *this;
    }

    //Binary Arithmetic +
    const matrix matrix::operator+(const matrix &mat) const
    {
        matrix* result = new matrix(*this);
        *result += mat;
        return *result;
    }
    const matrix matrix::operator+(const double &db) const
    {
        matrix* result = new matrix(*this);
        *result += db;
        return *result;
    }
    const matrix matrix::operator+(const float &fl) const
    {
        matrix* result = new matrix(*this);
        *result += (double)fl;
        return *result;
    }
    const matrix matrix::operator+(const int &in) const
    {
        matrix* result = new matrix(*this);
        *result += (double)in;
        return *result;
    }
    const matrix operator+(const double &db, const matrix &mat)
    {
        matrix* result = new matrix(mat);
        *result += db;
        return *result;
    }
    const matrix operator+(const float &fl, const matrix &mat)
    {
        matrix* result = new matrix(mat);
        *result += (double)fl;
        return *result;
    }
    const matrix operator+(const int &in, const matrix &mat)
    {
        matrix* result = new matrix(mat);
        *result += (double)in;
        return *result;
    }

    //Binary Arithmetic -
    const matrix matrix::operator-(const matrix &mat) const
    {
        matrix* result = new matrix(*this);
        *result -= mat;
        return *result;
    }
    const matrix matrix::operator-(const double &db) const
    {
        matrix* result = new matrix(*this);
        *result -= db;
        return *result;
    }
    const matrix matrix::operator-(const float &fl) const
    {
        matrix* result = new matrix(*this);
        *result -= (double)fl;
        return *result;
    }
    const matrix matrix::operator-(const int &in) const
    {
        matrix* result = new matrix(*this);
        *result -= (double)in;
        return *result;
    }
    const matrix operator-(const double &db, const matrix &mat)
    {
        matrix* result = new matrix(mat);
        *result -= db;
        return *result;
    }
    const matrix operator-(const float &fl, const matrix &mat)
    {
        matrix* result = new matrix(mat);
        *result -= (double)fl;
        return *result;
    }
    const matrix operator-(const int &in, const matrix &mat)
    {
        matrix* result = new matrix(mat);
        *result -= (double)in;
        return *result;
    }

    //Binary Arithmetic *
    const matrix matrix::operator*(const matrix &mat) const
    {
        if(this->m != mat.n){
            std::cout << "matrix operator* error: dimensions incompatible" << std::endl;
            return zeros(1);
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
    const matrix matrix::operator*(const double &db) const
    {
        matrix* result = new matrix(*this);
        *result *= db;
        return *result;
    }
    const matrix matrix::operator*(const float &fl) const
    {
        matrix* result = new matrix(*this);
        *result *= (double)fl;
        return *result;
    }
    const matrix matrix::operator*(const int &in) const
    {
        matrix* result = new matrix(*this);
        *result *= (double)in;
        return *result;
    }
    const matrix operator*(const double &db, const matrix &mat)
    {
        matrix* result = new matrix(mat);
        *result *= db;
        return *result;
    }
    const matrix operator*(const float &fl, const matrix &mat)
    {
        matrix* result = new matrix(mat);
        *result *= (double)fl;
        return *result;
    }
    const matrix operator*(const int &in, const matrix &mat)
    {
        matrix* result = new matrix(mat);
        *result *= (double)in;
        return *result;
    }

    //Binary Arithmetic /
    const matrix matrix::operator/(const matrix &mat) const
    {
        matrix* result = new matrix(*this);
        *result /= mat;
        return *result;
    }
    const matrix matrix::operator/(const double &db) const
    {
        matrix* result = new matrix(*this);
        *result /= db;
        return *result;
    }
    const matrix matrix::operator/(const float &fl) const
    {
        matrix* result = new matrix(*this);
        *result /= (double)fl;
        return *result;
    }
    const matrix matrix::operator/(const int &in) const
    {
        matrix* result = new matrix(*this);
        *result /= (double)in;
        return *result;
    }

    //Operator ^ integer exponentiation
    const matrix& matrix::operator^(const int &exp) const
    {
        if(n != m){
            std::cout << "matrix operator^ error: matrix not square" << std::endl;
            return zeros(1);
        }

        if(exp == 0){
            return eye(n);
        }

        matrix* result = new matrix(eye(n));
        matrix* store = new matrix(*this);

        int abs = exp;
        if(exp < 0){
            abs = -exp;
        }

        while(abs > 0){
            if(abs%2){
                *result = *result * *store;
            }
            *store = *store * *store;
            abs = abs / 2;
        }

        if(exp < 0){
            *result = result->inv();
        }

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

    //Brackets [col] returns the column given by col
    matrix& matrix::operator[](const int col) const
    {
        matrix* vector = new matrix(n,1);

        for(int i = 0; i < n; i++){
            vector->elements[i][0] = this->elements[i][col];
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

    //Returns element (r,c) as a double
    double matrix::at(int r, int c) const
    {
        if((r > (n-1)) || (c > (m-1)) || (r < 0) || (c < 0)){
            std::cout << "matrix .at error: indices out of bounds" << std::endl;
            return 0;
        }
        return(elements[r][c]);
    }

    //Returns n
    int matrix::rows() const
    {
        return this->n;
    }

    //Returns m
    int matrix::cols() const
    {
        return this->m;
    }

    //Set element (r,c) to a specified value val
    void matrix::set(int r, int c, double val)
    {
        if((r >= n) || (c >= m) || (r < 0) || (c < 0)){
            std::cout << "matrix .set error: indices out of bounds" << std::endl;
        } else{
            elements[r][c] = val;
        }
    }

    //Returns size of matrix as a 1x2 matrix representing [n m]
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
        for(int i = 0; (i < n) && (i < temp->n); i++)
        {
            for(int j = 0; (j < m) && (j < temp->m); j++)
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
        n = temp->n;
        m = temp->m;
        
        //Set elements
        elements = temp->elements;
        delete temp;
    }

    //Returns the transpose of a matrix
    matrix& matrix::T() const
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
    void matrix::std_print() const
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

    //Print matrix element addresses
    void matrix::adr_print() const
    {
        std::cout << elements << std::endl;
        for(int k = 0; k < n; k++){
            std::cout << elements[k] << std::endl;
        }
        for(int i = 0; i < n; i++)
        {
            std::cout << "[ ";
            for(int j = 0; j < m; j++)
            {
                std::cout << &elements[i][j] << " ";
            }
            std::cout << "]" << std::endl;
        }
        std::cout << std::endl;
    }

    //Swaps the information in the two inputted row indices
    void matrix::rswap(int r1, int r2)
    {
        double* temp = new double [n];

        for(int i = 0; i < n; i++){
            temp[i] = elements[r1][i];
            elements[r1][i] = elements[r2][i];
            elements[r2][i] = temp[i];
        }

        delete [] temp;
    }

    //Adds scale*r1 to r2
    void matrix::radd(int r1, int r2, double scale)
    {
        for(int i = 0; i < n; i++){
            elements[r2][i] += scale * elements[r1][i];
        }
    }

    //Multiplies row r by scale
    void matrix::rscale(int r, double scale)
    {
        for(int i = 0; i < n; i++){
            elements[r][i] *= scale;
        }
    }

    //Returns inverse of matrix input
    matrix& matrix::inv() const
    {
        //Step 0: check if matrix is square
        if(n != m){
            std::cout << "inverse error: matrix not square" << std::endl;
            matrix* err = new matrix;
            return *err;
        }
        
        matrix* inverse = new matrix(eye(n));
        matrix* copy = new matrix(*this);

        double scale = 1.0;
        for(int i = 0; i < m; i++){
            //Make sure that diagonal is nonzero
            if(copy->elements[i][i] == 0){
                for(int k = (i+1); k < n; k++){
                    if(copy->elements[k][i] != 0){
                        copy->radd(k,i,1.0);
                        inverse->radd(k,i,1.0);
                        break;
                    }
                }
                if(copy->elements[i][i] == 0){
                    std::cout << "inverse error: matrix singular " << std::endl;
                    matrix* err = new matrix;
                    return *err;
                }
            }

            //Scale current column so that diagonal is 1
            scale = 1.0/copy->elements[i][i];
            copy->rscale(i,scale);
            inverse->rscale(i,scale);

            //Make rest of column 0
            for(int j = 0; j < n; j++){
                if((i != j) && (copy->elements[j][i] != 0)){
                    scale = -1*copy->elements[j][i];
                    copy->radd(i,j,scale);
                    inverse->radd(i,j,scale);
                }
            }
        }

        delete copy;
        return *inverse;
    }


//Friend Functions

    //Produces an n x n identity matrix, with n as the input
    matrix& eye(int dim)
    {
        matrix* id = new matrix(dim);
        for(int i = 0; i < dim; i++){
            id->elements[i][i] = 1;
        }
        return *id;
    }

    //Produces a matrix of ones, with dimensions specified as inputs
    matrix& ones(int rows, int cols)
    {
        matrix* ones = new matrix(rows,cols);
        for(int i = 0; i < ones->n; i++){
            for(int j = 0; j < ones->m; j++){
                ones->elements[i][j] = 1;
            }
        }
        return *ones;
    }

    //Produces matrix of zeros with the specified dimensions
    matrix& zeros(int rows, int cols)
    {
        matrix* result = new matrix(rows,cols);
        return *result;
    }

    //Produces square matrix of zeros with specified dimension
    matrix& zeros(int dim)
    {
        matrix* result = new matrix(dim);
        return *result;
    }

    //Finds the magnitude of a vector (so the matrix must be n x 1)
    double vecNorm(matrix &mat)
    {
        double result = 0;
        
        if(mat.m != 1){
            std::cout << "vecNorm error: input matrix dimensions invalid" << std::endl;
            return 0;
        }

        for(int i = 0; i < mat.n; i++){
            result += (mat.elements[i][0] * mat.elements[i][0]);
        }

        return sqrt(result);
    }

    //Returns householder matrix for transforming the first column of the input matrix (x) into a vector of the form [ ||x|| 0 ... 0 ]^T
    matrix& householder(matrix &mat)
    {
        matrix* u = new matrix(mat.n,1);
        u->elements[0][0] = vecNorm(mat[0]);
        *u = mat[0] - *u;
        
        double squNorm = 0;
        for(int i = 0; i < u->n; i++){
            squNorm += u->elements[i][0] * u->elements[i][0];
        }

        matrix* HH = new matrix;
        *HH = eye(mat.n);
        *HH -= (*u) * ((*u).T()) * (2 / squNorm);
        return *HH;
    }

    //Returns input matrix without first row and first column
    matrix& chipFront(matrix &mat)
    {
        if((mat.n < 2) || (mat.m < 2)){
            std::cout << "chip error: input matrix dimensions invalid" << std::endl;
            matrix* err = new matrix;
            return *err;
        }

        matrix* result = new matrix((mat.n-1),(mat.m-1));
        for(int i = 0; i < result->n; i++)
        {
            for(int j = 0; j < result->m; j++)
            {
                result->elements[i][j] = mat.elements[i+1][j+1];
            }
        }
        return *result;
    }

    //Returns input matrix with extra row and column put at the beginning. All added elements are 0 except for [0][0], which is given the value of 1.
    matrix& pushFront(matrix &mat)
    {
        matrix* result = new matrix((mat.n+1),(mat.m+1));
        result->elements[0][0] = 1;

        for(int i = 0; i < mat.n; i++){
            for(int j = 0; j < mat.m; j++){
                result->elements[i+1][j+1] = mat.elements[i][j];
            }
        }
        return *result;
    }

    //Returns orthogonal matrix Q found with Householder QR factorization. Tested up to 3x3 matrices so far.
    matrix& QR(matrix &mat)
    {
        matrix* Q = new matrix(mat.n);
        *Q = eye(mat.n);

        if(mat.n < mat.m){
            std::cout << "QR error: dimensions invalid (more columns than rows)" << std::endl;
            return *Q;
        }
        
        matrix* A = new matrix(mat);
        matrix* P = new matrix;
        for(int i = 0; i < (mat.m-1); i++){
            *P = householder(*A);
            for(int j = 0; j < i; j++){
                *P = pushFront(*P);
            }
            *Q = *P * *Q;
            *A = *Q * mat;
            for(int j = 0; j < (i+1); j++){
                *A = chipFront(*A);
            }
        }
        delete P;
        delete A;
        return (*Q).T();
    }

