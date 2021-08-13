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
        explicit matrix(int); //explicit prevents allowed type mismatch
        matrix(int,int);
        matrix(const matrix &);
        matrix(matrix &&);

    //Destructor
        ~matrix();


    //Operator Overloading
        matrix& operator=(const matrix &);
        matrix& operator=(matrix &&);
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
        
        matrix& operator/=(const matrix &);
        matrix& operator/=(const double &);
        matrix& operator/=(const float &);
        matrix& operator/=(const int &);
        
        const matrix operator+(const matrix &) const;
        const matrix operator+(const double &) const;
        const matrix operator+(const float &) const;
        const matrix operator+(const int &) const;
        friend const matrix operator+(const double &, const matrix &);
        friend const matrix operator+(const float &, const matrix &);
        friend const matrix operator+(const int &, const matrix &);

        const matrix operator-(const matrix &) const;
        const matrix operator-(const double &) const;
        const matrix operator-(const float &) const;
        const matrix operator-(const int &) const;
        friend const matrix operator-(const double &, const matrix &);
        friend const matrix operator-(const float &, const matrix &);
        friend const matrix operator-(const int &, const matrix &);
        
        const matrix operator*(const matrix &) const;
        const matrix operator*(const double &) const;
        const matrix operator*(const float &) const;
        const matrix operator*(const int &) const;
        friend const matrix operator*(const double &, const matrix &);
        friend const matrix operator*(const float &, const matrix &);
        friend const matrix operator*(const int &, const matrix &);
        
        const matrix operator/(const matrix &) const;
        const matrix operator/(const double &) const;
        const matrix operator/(const float &) const;
        const matrix operator/(const int &) const;
        
        const matrix& operator^(const int &) const;
        
        matrix& operator-() const;
        matrix& operator[](const int) const;
        
        //matrix& operator()(int, int);
        //matrix& operator()(char,int);
        //matrix& operator()(int,char);
        
        bool operator==(const matrix &) const;
        bool operator!=(const matrix &) const;


    //Member Functions
        double at(int, int) const;
        int rows() const;
        int cols() const;
        void set(int, int, double);
        matrix size();
        void resize(int, int);
        //void resize(int,int,double); //double is default value for new elements
        matrix& T() const;
        void setT();
        //void zeros();
        //void ones();
        void std_print() const;
        void rswap(int,int);
        void radd(int,int,double);
        void rscale(int, double);
        matrix& inv() const;
        //vector-wise addition
        //matrix push_back(matrix m)
        //matrix inv()
        //eig()


    //Friend Functions
    friend matrix& eye(int);
    friend matrix& ones(int,int);
    friend double vecNorm(matrix &);
    friend matrix& householder(matrix &);
    friend matrix& chipFront(matrix &);
    friend matrix& pushFront(matrix &);
    friend matrix& QR(matrix &);
};

matrix& eye(int);
matrix& ones(int,int);
matrix& zeros(int, int);
matrix& zeros(int);
double vecNorm(matrix &);
matrix& householder(matrix &);
matrix& chipFront(matrix &);
matrix& pushFront(matrix &);
matrix& QR(matrix &);


/*
Things I want this to do:

matrix:
    operators:
        / division
        () obtain elements, account for scenarios where you have ':' char
        ^ exponent

    funtions:
        inverse
        determinate
        rref
        cholesky square root
        row swap
        orthogonal matrix
        


-be able to return vectors such as matrix(:,1)

*/

#endif