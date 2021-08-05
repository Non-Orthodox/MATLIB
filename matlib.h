#ifndef H_MATLIB
#define H_MATLIB

#include <string>

//namespace Matlib?

class matrix
{
    private:
        int n; //number of rows
        int m; //number of columns

        double** elements;

    public:
    //Constructors
        matrix();
        matrix(int,int);
        matrix(const matrix &);

    //Destructor
        ~matrix();


    //Operator Overloading
        matrix& operator=(const matrix &);
        //matrix& operator=(const std::string &);
        //matrix& operator=(const double);

        matrix& operator+=(const matrix &);
        matrix& operator+=(const double &);
        matrix& operator+=(const float &);
        matrix& operator+=(const int &);
        
        matrix& operator-=(const matrix &);
        matrix& operator-=(const double &);
        matrix& operator-=(const float &);
        matrix& operator-=(const int &);

        matrix& operator*=(const matrix &);
        matrix& operator*=(const double &);
        matrix& operator*=(const float &);
        matrix& operator*=(const int &);
        
        //matrix& operator/=(const matrix &);
        
        const matrix& operator+(const matrix &) const;
        
        const matrix& operator-(const matrix &) const;
        
        const matrix& operator*(const matrix &) const;
        const matrix& operator*(const double &) const;
        const matrix& operator*(const float &) const;
        const matrix& operator*(const int &) const;
        
        //const matrix& operator/(const matrix &) const;
        
        //const matrix& operator^(const int &) const;
        
        matrix& operator-() const;
        matrix& operator[](const int) const;
        
        //matrix& operator()(int, int);
        //matrix& operator()(char,int);
        //matrix& operator()(int,char);
        
        bool operator==(const matrix &) const;
        bool operator!=(const matrix &) const;


    //Member Functions
        double at(int, int);
        int rows();
        int cols();
        void set(int, int, double);
        matrix size();
        int size(int);
        void resize(int, int);
        //void resize(int,int,double); //double is default value for new elements
        matrix T();
        void setT();
        //void zeros();
        //void ones();
        void std_print();
        //vector-wise addition
        //matrix push_back(matrix m)
        //matrix inv()
        //eig()


    //Friend Functions
    friend matrix& eye(int);
    friend matrix& ones(int,int);
    friend double vecNorm(matrix &);
    friend matrix& householder(matrix &);
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