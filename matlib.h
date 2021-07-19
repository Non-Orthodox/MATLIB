
class matrix
{
    private:
        int n,m = 1; //matrix is n by m

    public:
        float elements[];

        //Constructors
        matrix()
        {
            //initialize to be scalar zero
        }
        matrix(int height, int width)
        {
            this->n = height;
            this->m = width;
            //initialize array elements to be zero
        }
        matrix(float* elements)
        {
            //initialize with 2d array as input and get the dimensions that way
        }

        //Destructor
        ~matrix()
        {
            //delete new things
        }

        //Member Functions
        //void resize(int n, int m)
        //matrix size()
        //matrix Transpose()
        //

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