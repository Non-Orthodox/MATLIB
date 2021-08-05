# MATLIB
Matrix math library, the way that I want it.

## MATRICES
Produce matrices with the class matrix. Currently, the matrix elements are floats; however, this will likely change to a template. The variable members of this class consist of the elements themselves and the two numbers representing the size of the matrix.

## Complex Numbers
Produce complex numbers with the class cdouble.

### Member Functions
re()                returns real portion
im()                returns imaginary portion
mag()               returns polar magnitude
phase()             returns polar phase
inv()               returns complex inverse
set(double,double)  sets real and imaginary portions, respectively
rect_print()        prints complex number to console in rectangular form
polar_print()       prints complex number to console in polar form

### Operators
compound: += -= *= /= ^= 
(^= only does integer powers at the moment)

binary: + - * / ^
(^ only does integer powers at the moment)

logical: == != 
