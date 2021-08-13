#include "cdouble.h"
#include <cmath>
#include <iostream>
#include <string>

//Constructors
    cdouble::cdouble()
    {
        els[0] = 0;
        els[1] = 0;
    }

    cdouble::cdouble(double r)
    {
        els[0] = r;
        els[1] = 0;
    }

    cdouble::cdouble(double a, double b)
    {
        els[0] = a;
        els[1] = b;
    }

    cdouble::cdouble(const cdouble &cfl)
    {
        els[0] = cfl.els[0];
        els[1] = cfl.els[1];
    }


//Destructor
    cdouble::~cdouble(){}


//Operators

    //Assignment Operator
    cdouble& cdouble::operator=(const cdouble &cfl)
    {
        if(this == &cfl)
            return *this;
        
        this->els[0] = cfl.els[0];
        this->els[1] = cfl.els[1];
        return *this;
    }

    //Assigns cdouble based on a string. Format is "r i"
    cdouble& cdouble::operator=(const char* str)
    {
        int index = 0;
        std::string nums[2];
        int k = 0;
        while(str[index] != 0)
        {
            if(std::isdigit(str[index]) || (str[index] == '.')){
                nums[k].push_back(str[index]);
            } else{
                if(str[index] == ' '){
                    k++;
                }
            }
            index++;
        }

        this->els[0] = std::stof(nums[0]);
        this->els[1] = std::stof(nums[1]);

        return *this;
    }

    //Compound Assignment +=
    cdouble& cdouble::operator+=(const cdouble &cfl)
    {
        this->els[0] += cfl.els[0];
        this->els[1] += cfl.els[1];
        return *this;
    }
    cdouble& cdouble::operator+=(const double &db)
    {
        this->els[0] += db;
        return *this;
    }
    cdouble& cdouble::operator+=(const float &fl)
    {
        this->els[0] += (double)fl;
        return *this;
    }
    cdouble& cdouble::operator+=(const int &in)
    {
        this->els[0] += (double)in;
        return *this;
    }

    //Compound Assignment -=
    cdouble& cdouble::operator-=(const cdouble &cfl)
    {
        this->els[0] -= cfl.els[0];
        this->els[1] -= cfl.els[1];
        return *this;
    }
    cdouble& cdouble::operator-=(const double &db)
    {
        this->els[0] -= db;
        return *this;
    }
    cdouble& cdouble::operator-=(const float &fl)
    {
        this->els[0] -= (double)fl;
        return *this;
    }
    cdouble& cdouble::operator-=(const int &in)
    {
        this->els[0] -= (double)in;
        return *this;
    }

    //Compound Assignment *= with another cdouble
    cdouble& cdouble::operator*=(const cdouble &cfl)
    {
        double r = (this->els[0] * cfl.els[0]) - (this->els[1] * cfl.els[1]);
        this->els[1] = (this->els[0] * cfl.els[1]) + (this->els[1] * cfl.els[0]);
        this->els[0] = r;
        return *this;
    }
    cdouble& cdouble::operator*=(const double &db)
    {
        this->els[0] *= (double)db;
        this->els[1] *= (double)db;
        return *this;
    }
    cdouble& cdouble::operator*=(const float &fl)
    {
        this->els[0] *= (double)fl;
        this->els[1] *= (double)fl;
        return *this;
    }
    cdouble& cdouble::operator*=(const int &in)
    {
        this->els[0] *= (double)in;
        this->els[1] *= (double)in;
        return *this;
    }

    //Compound Assignment /=
    cdouble& cdouble::operator/=(const cdouble &cfl)
    {
        float r;
        r = ( (this->els[0] * cfl.els[0]) + (this->els[1] * cfl.els[1]) ) / ( (cfl.els[0] * cfl.els[0]) + (cfl.els[1] * cfl.els[1]) );
        this->els[1] = ( (this->els[1] * cfl.els[0]) - (this->els[0] * cfl.els[1]) ) / ( (cfl.els[0] * cfl.els[0]) + (cfl.els[1] * cfl.els[1]) );
        this->els[0] = r;
        return *this;
    }
    cdouble& cdouble::operator/=(const double &db)
    {
        this->els[0] /= db;
        this->els[1] /= db;
        return *this;
    }
    cdouble& cdouble::operator/=(const float &fl)
    {
        this->els[0] /= (double)fl;
        this->els[1] /= (double)fl;
        return *this;
    }
    cdouble& cdouble::operator/=(const int &in)
    {
        this->els[0] /= (double)in;
        this->els[1] /= (double)in;
        return *this;
    }

    //Compound Assignment ^=
    cdouble& cdouble::operator^=(const int &exp)
    {
        if(exp == 0){
            this->set(1,0);
            return *this;
        }

        int abs = exp;
        if(exp < 0){
            abs = -exp;
        }
        
        cdouble store(*this);
        cdouble result(1,0);

        while(abs > 0){
            if(abs%2){
                result *= store;
            }
            store *= store;
            abs = abs/2;
        }

        if(exp < 0){
            result = result.inv();
        }

        *this = result;
        return *this;
    }

    //Binary Arithmetic +
    const cdouble cdouble::operator+(const cdouble &cfl) const
    {
        cdouble* result = new cdouble;
        *result = *this;
        *result += cfl;
        return *result;
    }
    const cdouble cdouble::operator+(const double &db) const
    {
        cdouble* result = new cdouble(*this);
        *result += db;
        return *result;
    }
    const cdouble cdouble::operator+(const float &fl) const
    {
        cdouble* result = new cdouble(*this);
        *result += (double)fl;
        return *result;
    }
    const cdouble cdouble::operator+(const int &in) const
    {
        cdouble* result = new cdouble(*this);
        *result += (double)in;
        return *result;
    }
    const cdouble operator+(const double &db, const cdouble &cdl)
    {
        cdouble* result = new cdouble(cdl);
        *result += db;
        return *result;
    }
    const cdouble operator+(const float &fl, const cdouble &cdl)
    {
        cdouble* result = new cdouble(cdl);
        *result += (double)fl;
        return *result;
    }
    const cdouble operator+(const int &in, const cdouble &cdl)
    {
        cdouble* result = new cdouble(cdl);
        *result += (double)in;
        return *result;
    }

    //Binary Arithmetic -
    const cdouble cdouble::operator-(const cdouble &cfl) const
    {
        cdouble* result = new cdouble;
        *result = *this;
        *result -= cfl;
        return *result;
    }
    const cdouble cdouble::operator-(const double &db) const
    {
        cdouble* result = new cdouble(*this);
        *result -= db;
        return *result;
    }
    const cdouble cdouble::operator-(const float &fl) const
    {
        cdouble* result = new cdouble(*this);
        *result -= (double)fl;
        return *result;
    }
    const cdouble cdouble::operator-(const int &in) const
    {
        cdouble* result = new cdouble(*this);
        *result -= (double)in;
        return *result;
    }
    const cdouble operator-(const double &db, const cdouble &cdl)
    {
        cdouble* result = new cdouble(cdl);
        *result -= db;
        return *result;
    }
    const cdouble operator-(const float &fl, const cdouble &cdl)
    {
        cdouble* result = new cdouble(cdl);
        *result -= (double)fl;
        return *result;
    }
    const cdouble operator-(const int &in, const cdouble &cdl)
    {
        cdouble* result = new cdouble(cdl);
        *result -= (double)in;
        return *result;
    }

    //Binary Arithmetic *
    const cdouble cdouble::operator*(const cdouble &cfl) const
    {
        cdouble* result = new cdouble;
        *result = *this;
        *result *= cfl;
        return *result;
    }
    const cdouble cdouble::operator*(const double &db) const
    {
        cdouble* result = new cdouble(*this);
        *result *= db;
        return *result;
    }
    const cdouble cdouble::operator*(const float &fl) const
    {
        cdouble* result = new cdouble(*this);
        *result *= (double)fl;
        return *result;
    }
    const cdouble cdouble::operator*(const int &in) const
    {
        cdouble* result = new cdouble(*this);
        *result *= (double)in;
        return *result;
    }
    const cdouble operator*(const double &db, const cdouble &cdl)
    {
        cdouble* result = new cdouble(cdl);
        *result *= db;
        return *result;
    }
    const cdouble operator*(const float &fl, const cdouble &cdl)
    {
        cdouble* result = new cdouble(cdl);
        *result *= (double)fl;
        return *result;
    }
    const cdouble operator*(const int &in, const cdouble &cdl)
    {
        cdouble* result = new cdouble(cdl);
        *result *= (double)in;
        return *result;
    }

    //Binary Arithmetic /
    const cdouble cdouble::operator/(const cdouble &cfl) const
    {
        cdouble* result = new cdouble(*this);
        *result /= cfl;
        return *result;
    }
    const cdouble cdouble::operator/(const double &db) const
    {
        cdouble* result = new cdouble(*this);
        *result /= db;
        return *result;
    }
    const cdouble cdouble::operator/(const float &fl) const
    {
        cdouble* result = new cdouble(*this);
        *result /= (double)fl;
        return *result;
    }
    const cdouble cdouble::operator/(const int &in) const
    {
        cdouble* result = new cdouble(*this);
        *result /= (double)in;
        return *result;
    }
    const cdouble operator/(const double &db, const cdouble &cdl)
    {
        cdouble* result = new cdouble(cdl);
        *result = result->inv();
        *result *= db;
        return *result;
    }
    const cdouble operator/(const float &fl, const cdouble &cdl)
    {
        cdouble* result = new cdouble(cdl);
        *result = result->inv();
        *result *= (double)fl;
        return *result;
    }
    const cdouble operator/(const int &in, const cdouble &cdl)
    {
        cdouble* result = new cdouble(cdl);
        *result = result->inv();
        *result *= (double)in;
        return *result;
    }

    //Binary integer exponoentiation ^
    const cdouble cdouble::operator^(const int &exp) const
    {
        cdouble result = *this;
        result ^= exp;
        return result;
    }
    const cdouble operator^(const double &db, const cdouble &cdl)
    {
        cdouble* result = new cdouble;
        double amp = pow(db,cdl.els[0]);
        double phase = cdl.els[1] * log(db);

        result->els[0] = amp * cos(phase);
        result->els[1] = amp * sin(phase);
        return *result;
    }
    const cdouble operator^(const float &fl, const cdouble &cdl)
    {
        cdouble* result = new cdouble;
        double amp = pow((double)fl,cdl.els[0]);
        double phase = cdl.els[1] * log((double)fl);

        result->els[0] = amp * cos(phase);
        result->els[1] = amp * sin(phase);
        return *result;
    }
    const cdouble operator^(const int &in, const cdouble &cdl)
    {
        cdouble* result = new cdouble;
        double amp = pow((double)in,cdl.els[0]);
        double phase = cdl.els[1] * log((double)in);

        result->els[0] = amp * cos(phase);
        result->els[1] = amp * sin(phase);
        return *result;
    }

    //Unary operator - multiplies by -1
    cdouble& cdouble::operator-() const
    {
        cdouble* result = new cdouble(*this);
        result->els[0] *= -1;
        result->els[1] *= -1;
        return *result;
    }

    //Unary operator * produces complex conjugate
    cdouble& cdouble::operator*() const
    {
        cdouble* result = new cdouble(*this);
        result->els[1] *= -1;
        return *result;
    }

    //Logical Comparison ==
    bool cdouble::operator==(const cdouble &cfl) const
    {
        if(this->els[0] == cfl.els[0]){
            if(this->els[1] == cfl.els[1]){
                return true;
            }
        }
        return false;
    }

    //Logical Comparison !=
    bool cdouble::operator!=(const cdouble &cfl) const
    {
        return !(*this == cfl);
    }


//Member Functions

    //Returns real part
    double cdouble::re() const
    {
        return els[0];
    }

    //Return imaginary part
    double cdouble::im() const
    {
        return els[1];
    }

    //Returns magnitude
    double cdouble::mag() const
    { 
        return sqrt((els[0] * els[0])+(els[1] * els[1]));
    }

    //Returns phase on complex plane
    double cdouble::phase() const
    {
        return atan2(els[1],els[0]);
    }

    //Returns the complex inverse
    cdouble cdouble::inv() const
    {
        cdouble inverse;
        double factor = (1)/((els[0] * els[0])+(els[1] * els[1]));
        inverse.els[0] *= factor;
        inverse.els[1] *= -factor;
        return inverse;
    }

    //Sets both elements of the complex number
    void cdouble::set(double a, double b)
    {
        this->els[0] = a;
        this->els[1] = b;
    }

    //Print the complex number to console in rectangular form
    void cdouble::rect_print() const
    {
        if(els[1] >= 0)
            std::cout << els[0] << "+" << els[1] << "i" << std::endl << std::endl;
        else
            std::cout << els[0] << els[1] << "i" << std::endl << std::endl;
    }

    //Print the complex number to console in polar form
    void cdouble::polar_print() const
    {
        std::cout << this->mag() << " * exp(" << this->phase() << "i)" << std::endl << std::endl;
    }