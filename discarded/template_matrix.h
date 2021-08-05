#ifndef H_TMATRIX
#define H_TMATRIX

#include <string>

template<class Tp>
class matrix
{
    private:
        int n; //number of rows
        int m; //number of columns

        Tp** elements;

    public:
    //Constructors
        matrix();
        matrix(int,int);
        matrix(const matrix<Tp> &);

    //Destructor
        ~matrix();

    //Member Functions
        Tp at(int, int);
        int rows();
        int cols();
        void set(int, int, Tp);
        matrix size();

        int size(int);
        void resize(int, int);
        //void resize(int,int,T);
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
        // matrix<Tp>& operator=(const matrix<Tp> &);
        // //matrix& operator=(const std::string &);
        // //matrix& operator=(const T);
        // matrix& operator+=(const matrix &);
        // matrix& operator-=(const matrix &);

        // matrix& operator*=(const matrix &);
        // matrix& operator*=(const T &);
        // matrix& operator*=(const double &);
        // matrix& operator*=(const int &);
        
        // //matrix& operator/=(const matrix &);
        // const matrix& operator+(const matrix &) const;
        // const matrix& operator-(const matrix &) const;
        
        // const matrix& operator*(const matrix &) const;
        // const matrix& operator*(const float &) const;
        // const matrix& operator*(const double &) const;
        // const matrix& operator*(const int &) const;
        
        // //const matrix& operator/(const matrix &) const;
        // //const matrix& operator^(const int &) const;
        // matrix& operator-() const;
        // matrix& operator[](const int) const;
        // //matrix& operator()(int, int);
        // //matrix& operator()(char,int);
        // //matrix& operator()(int,char);
        // bool operator==(const matrix &) const;
        // bool operator!=(const matrix &) const;

        
};

template<class Tp> matrix<Tp>& eye(int);
template<class Tp> matrix<Tp>& ones(int,int);
template<class Tp> Tp vecNorm(matrix<Tp> &);
template<class Tp> matrix<Tp>& householder(matrix<Tp> &);

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