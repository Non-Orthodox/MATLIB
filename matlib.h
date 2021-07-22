#ifndef H_MATLIB
#define H_MATLIB

//namespace Matlib?

class matrix
{
    private:
        int n,m = 1; //n in numer of rows, m is number of columns

    public:
    //Variable Members
        //Matrix element values
        float** elements;
        //Experimental, used to possibly modify the process of copying portions of matrices
        int offset[2] = {0,0};

    //Constructors
        matrix();
        matrix(int,int);

    //Destructor
        ~matrix();

    //Member Functions
        float at(int, int);
        matrix size();
        void resize(int, int);
        //matrix push_back(matrix m)
        //matrix T()
        //matrix inv()
        //eig()
        //std_print


    //Operator Overloading
        // matrix & operator=(const matrix &mat)
        // {
            
        //     for(int i = 0; i < n; i++)
        //     {
        //         for(int j = 0; j < m; j++)
        //         {

        //         }
        //     }
        // }

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
        * multiplication
        + addition
        - subtraction
        / division
        () obtain elements, account for scenarios where you have ':' char
        ^ exponent
        == logic equal
        transpose? (not sure if operator or function)

    funtions:
        determinate
        rref
        QR factorize
        cholesky square root
        row swap
        


-set size upon creation
-child class: identity matrix, vector
-be able to return vectors such as matrix(:,1)



*/
#endif