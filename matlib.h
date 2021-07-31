#ifndef H_MATLIB
#define H_MATLIB

//namespace Matlib?

class matrix
{
    private:
        int n; //number of rows
        int m; //number of columns

    public:
    //Variable Members
        //Matrix element values
        float** elements;

    //Constructors
        matrix();
        matrix(int,int);
        matrix(const matrix &);

    //Destructor
        ~matrix();

    //Member Functions
        float at(int, int);
        matrix size();
        void resize(int, int);
        matrix T();
        void setT();
        void std_print();
        //vector-wise addition
        //matrix push_back(matrix m)
        //matrix inv()
        //eig()


    //Operator Overloading
        matrix& operator=(const matrix &);
        matrix& operator+=(const matrix &);
        matrix& operator-=(const matrix &);
        const matrix& operator+(const matrix &)  const;
        const matrix& operator-(const matrix &)  const;

        // matrix & operator()(int a, int b)
        // {
        //     if((a>=0)&&(b>=0)&&(a<n)&&(b<m))
        //     {

        //     }
        // }

};

//matrix rref(matrix*);


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
        


-be able to return vectors such as matrix(:,1)

*/

#endif