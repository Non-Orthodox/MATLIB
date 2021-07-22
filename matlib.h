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
        matrix()
        {
            elements = new float* [1];
            elements[0] = new float [1];
            elements[0][0] = 0;
        }
        matrix(int height, int width)
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
        //Returns element (r,c) as a float
        float at(int r, int c)
        {
            return(elements[r][c]);
        }
        
        //Returns size of matrix, as a 1x2 matrix representing [n m]
        matrix size()
        {
            matrix siz(1,2);
            siz.elements[0][0] = n;
            siz.elements[0][1] = m;
            return(siz);
        }

        //Resizes the matrix. All indices which are not removed retain their elements. New elements are set to be 0. 
        void resize(int rows, int cols)
        {
            matrix temp(rows,cols);
            
            //Copy all relevant elements to new matrix 
            for(int i = 0; (i < n) && (i < rows); i++)
            {
                for(int j = 0; (j < m) && (j < cols); j++)
                {
                    temp.elements[i][j] = elements[i][j];
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

            elements = temp.elements;
            for(int l = 0; l < n; l++)
            {
                elements[l] = temp.elements[l];
            }
        }

        //matrix push_back(matrix m)
        //matrix T()
        //matrix inv()
        //eig()
        //print elements


    //Operator Overloading
        matrix & operator=(const matrix &mat)
        {
            
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < m; j++)
                {

                }
            }
        }

        matrix & operator()(int a, int b)
        {
            if((a>=0)&&(b>=0)&&(a<n)&&(b<m))
            {

            }
        }

};

//submatrix class used to assign portions of matrices
class submatrix
{

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
#endif