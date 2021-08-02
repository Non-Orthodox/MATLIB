#ifndef H_MATLIB
#define H_MATLIB

#include <string>

//namespace Matlib?

class matrix
{
    private:
        int n; //number of rows
        int m; //number of columns

    public:
    //Variable Members
        //Matrix element values
        float** elements; //IMPORTANT: make this private when alternative method of editing elements is produced 

    //Constructors
        matrix();
        matrix(int,int);
        matrix(const matrix &);

    //Destructor
        ~matrix();

    //Member Functions
        float at(int, int);
        matrix size();
        int size(int);
        void resize(int, int);
        //void resize(int,int,float); //float is default value for new elements
        matrix T();
        void setT();
        //void zeros();
        //void ones();
        void std_print();
        //vector-wise addition
        //matrix push_back(matrix m)
        //matrix inv()
        //eig()


    //Operator Overloading
        matrix& operator=(const matrix &);
        //matrix& operator=(const std::string &);
        //matrix& operator=(const float);
        matrix& operator+=(const matrix &);
        matrix& operator-=(const matrix &);
        matrix& operator*=(const matrix &);
        //matrix& operator/=(const matrix &);
        const matrix& operator+(const matrix &) const;
        const matrix& operator-(const matrix &) const;
        const matrix& operator*(const matrix &) const;
        //const matrix& operator/(const matrix &) const;
        //matrix& operator()(int, int);
        //matrix& operator()(char,int);
        //matrix& operator()(int,char);
        bool operator==(const matrix &) const;
        bool operator!=(const matrix &) const;
};

/*
Things I want this to do:

matrix:
    operators:
        * multiplication (scalar and matrix)
        + addition (scalar and matrix)
        - subtraction
        / division
        () obtain elements, account for scenarios where you have ':' char
        ^ exponent
        == logic equal

    funtions:
        inverse
        determinate
        rref
        QR factorize
        cholesky square root
        row swap
        orthogonal matrix
        


-be able to return vectors such as matrix(:,1)

*/

#endif