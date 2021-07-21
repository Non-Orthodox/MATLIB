//#ifdef H_MATLIB
//#define H_MATLIB

//namespace Matlib?

class matrix
{
    private:
        int n,m = 1; //n in numer of rows, m is number of columns

    public:
        float** elements;

        //Constructors
        matrix()
        {
            elements = new float* [1];
            elements[0] = new float [1];
            elements[0][0] = 0;
        }
        matrix(int height, int width)
        {
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

        //Destructor
        ~matrix()
        {
            for(int i = 0; i < n; i++)
            {
                delete [] elements[i];
            }
            delete [] elements;
        }

        //Member Functions
        matrix size()
        {
            matrix siz(1,2);
            siz.elements[0][0] = n;
            siz.elements[0][1] = m;
            return(siz);
        }
        //void resize(int n, int m)
        //matrix Transpose()


        //Operator Overloading


};

matrix rref(matrix*);


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
