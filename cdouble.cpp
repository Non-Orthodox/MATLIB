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
        cdouble result = *this;
        if(exp < 0){
            for(int i = 1; i < (-1*exp); i++){
                result *= *this; 
            }
            *this = result.inv();
        } else{
            for(int i = 1; i < exp; i++){
                 result *= *this; 
            }
            *this = result;
        }
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

    //Binary integer exponoentiation ^
    const cdouble cdouble::operator^(const int &exp) const
    {
        cdouble* result = new cdouble(*this);
        *result ^= exp;
        return *result;
    }

    //Unary operator - reverses phasor (changes phase by pi/2)
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
    double cdouble::re()
    {
        return els[0];
    }

    //Return imaginary part
    double cdouble::im()
    {
        return els[1];
    }

    //Returns magnitude
    double cdouble::mag()
    {
        return sqrt((els[0] * els[0])+(els[1] * els[1]));
    }

    //Returns phase on complex plane
    double cdouble::phase()
    {
        return atan2(els[1],els[0]);
    }

    //Returns the complex inverse
    cdouble cdouble::inv()
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

    //Print the imaginary number to console using std::cout
    void cdouble::std_print()
    {
        if(els[1] >= 0)
            std::cout << els[0] << "+" << els[1] << "i" << std::endl << std::endl;
        else
            std::cout << els[0] << els[1] << "i" << std::endl << std::endl;
    }