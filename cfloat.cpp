#include "cfloat.h"
#include <cmath>
#include <iostream>
#include <string>

//Constructors
    cfloat::cfloat()
    {
        els[0] = 0;
        els[1] = 0;
    }

    cfloat::cfloat(bool pol)
    {
        p = pol;
        els[0] = 0;
        els[1] = 0;
    }

    cfloat::cfloat(float r)
    {
        els[0] = r;
        els[1] = 0;
    }

    cfloat::cfloat(float a, float b)
    {
        els[0] = a;
        els[1] = b;
    }

    cfloat::cfloat(float a, float b, bool pol)
    {
        els[0] = a;
        els[1] = b;
        p = pol;
    }

    cfloat::cfloat(const cfloat &cfl)
    {
        p = cfl.p;
        els[0] = cfl.els[0];
        els[1] = cfl.els[1];
    }


//Destructor
    cfloat::~cfloat(){}


//Operators

    //Assignment Operator
    cfloat& cfloat::operator=(const cfloat &cfl)
    {
        if(this == &cfl)
            return *this;
        
        this->p = cfl.p;
        this->els[0] = cfl.els[0];
        this->els[1] = cfl.els[1];
        return *this;
    }

    //Assigns cfloat based on a string. Format is "r i"
    cfloat& cfloat::operator=(const char* str)
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
    cfloat& cfloat::operator+=(const cfloat &cfl)
    {
        if(this->p)
        {
            cfloat temp(this->re(),this->im(),false);
            if(cfl.p){
                temp.els[0] += ( cfl.els[0] * (cos(cfl.els[1])) );
                temp.els[1] += ( cfl.els[0] * (sin(cfl.els[1])) );
            } else{
                temp.els[0] += cfl.els[0];
                temp.els[1] += cfl.els[1];
            }
            temp.polar();
            *this = temp;
        } else{
            if(cfl.p){
                this->els[0] += ( cfl.els[0] * (cos(cfl.els[1])) );
                this->els[1] += ( cfl.els[0] * (sin(cfl.els[1])) );
            } else{
                this->els[0] += cfl.els[0];
                this->els[1] += cfl.els[1];
            }
        }
        return *this;
    }
    cfloat& cfloat::operator+=(const float &fl)
    {
        if(p){
            cfloat* temp = new cfloat(*this);
            temp->rect();
            temp->els[0] += fl; 
            temp->polar();
            *this = *temp;
            delete temp;
        } else{
            this->els[0] += fl;
        }
        return *this;
    }
    cfloat& cfloat::operator+=(const double &db)
    {
        if(p){
            cfloat* temp = new cfloat(*this);
            temp->rect();
            temp->els[0] += (float)db; 
            temp->polar();
            *this = *temp;
            delete temp;
        } else{
            this->els[0] += (float)db;
        }
        return *this;
    }
    cfloat& cfloat::operator+=(const int &in)
    {
        if(p){
            cfloat* temp = new cfloat(*this);
            temp->rect();
            temp->els[0] += (float)in; 
            temp->polar();
            *this = *temp;
            delete temp;
        } else{
            this->els[0] += (float)in;
        }
        return *this;
    }

    //Compound Assignment -=
    cfloat& cfloat::operator-=(const cfloat &cfl)
    {
        if(this->p)
        {
            cfloat temp(this->re(),this->im(),false);
            if(cfl.p){
                temp.els[0] -= ( cfl.els[0] * (cos(cfl.els[1])) );
                temp.els[1] -= ( cfl.els[0] * (sin(cfl.els[1])) );
            } else{
                temp.els[0] -= cfl.els[0];
                temp.els[1] -= cfl.els[1];
            }
            temp.polar();
            *this = temp;
        } else{
            if(cfl.p){
                this->els[0] -= ( cfl.els[0] * (cos(cfl.els[1])) );
                this->els[1] -= ( cfl.els[0] * (sin(cfl.els[1])) );
            } else{
                this->els[0] -= cfl.els[0];
                this->els[1] -= cfl.els[1];
            }
        }
        return *this;
    }
    cfloat& cfloat::operator-=(const float &fl)
    {
        if(p){
            cfloat* temp = new cfloat(*this);
            temp->rect();
            temp->els[0] -= fl; 
            temp->polar();
            *this = *temp;
            delete temp;
        } else{
            this->els[0] -= fl;
        }
        return *this;
    }
    cfloat& cfloat::operator-=(const double &db)
    {
        if(p){
            cfloat* temp = new cfloat(*this);
            temp->rect();
            temp->els[0] -= (float)db; 
            temp->polar();
            *this = *temp;
            delete temp;
        } else{
            this->els[0] -= (float)db;
        }
        return *this;
    }
    cfloat& cfloat::operator-=(const int &in)
    {
        if(p){
            cfloat* temp = new cfloat(*this);
            temp->rect();
            temp->els[0] -= (float)in; 
            temp->polar();
            *this = *temp;
            delete temp;
        } else{
            this->els[0] -= (float)in;
        }
        return *this;
    }

    //Compound Assignment *= with another cfloat
    cfloat& cfloat::operator*=(const cfloat &cfl)
    {
        if(this->p)
        {
            if(cfl.p){
                this->els[0] *= cfl.els[0];
                this->els[1] += cfl.els[1];
            } else{
                this->els[0] *= (sqrt(cfl.els[0] * cfl.els[0])+(cfl.els[1] * cfl.els[1]));
                this->els[1] += (atan2(cfl.els[1],cfl.els[0]));
            }
        } else{
            if(cfl.p){
                cfloat temp(this->mag(),this->phase(),true);
                temp.els[0] *= cfl.els[0];
                temp.els[1] += cfl.els[1];
                temp.rect();
                *this = temp;
            } else{
                float r;
                r = (this->els[0] * cfl.els[0]) - (this->els[1] * cfl.els[1]);
                this->els[1] = (this->els[0] * cfl.els[1]) + (this->els[1] * cfl.els[0]);
                this->els[0] = r;
            }
        }
        return *this;
    }
    cfloat& cfloat::operator*=(const float &fl)
    {
        if(p){
            this->els[0] *= fl;
        }else {
            this->els[0] *= fl;
            this->els[1] *= fl;
        }
        return *this;
    }
    cfloat& cfloat::operator*=(const double &db)
    {
        if(p){
            this->els[0] *= (float)db;
        }else {
            this->els[0] *= (float)db;
            this->els[1] *= (float)db;
        }
        return *this;
    }
    cfloat& cfloat::operator*=(const int &in)
    {
        if(p){
            this->els[0] *= (float)in;
        }else {
            this->els[0] *= (float)in;
            this->els[1] *= (float)in;
        }
        return *this;
    }

    //Compound Assignment /=
    cfloat& cfloat::operator/=(const cfloat &cfl)
    {
        if(this->p)
        {
            if(cfl.p){
                this->els[0] /= cfl.els[0];
                this->els[1] -= cfl.els[1];
            } else{
                this->els[0] /= (sqrt(cfl.els[0] * cfl.els[0])+(cfl.els[1] * cfl.els[1]));
                this->els[1] -= (atan2(cfl.els[1],cfl.els[0]));
            }
        } else{
            if(cfl.p){
                cfloat temp(this->mag(),this->phase(),true);
                temp.els[0] /= cfl.els[0];
                temp.els[1] -= cfl.els[1];
                temp.rect();
                *this = temp;
            } else{
                float r;
                r = ( (this->els[0] * cfl.els[0]) + (this->els[1] * cfl.els[1]) ) / ( (cfl.els[0] * cfl.els[0]) + (cfl.els[1] * cfl.els[1]) );
                this->els[1] = ( (this->els[1] * cfl.els[0]) - (this->els[0] * cfl.els[1]) ) / ( (cfl.els[0] * cfl.els[0]) + (cfl.els[1] * cfl.els[1]) );
                this->els[0] = r;
            }
        }
        return *this;
    }
    cfloat& cfloat::operator/=(const float &fl)
    {
        *this *= (1/fl);
        return *this;
    }
    cfloat& cfloat::operator/=(const double &db)
    {
        *this *= (1/((float)db));
        return *this;
    }
    cfloat& cfloat::operator/=(const int &in)
    {
        *this *= (1/((float)in));
        return *this;
    }

    //Compound Assignment ^=
    cfloat& cfloat::operator^=(const int &exp)
    {
        if(exp == 0){
            this->set(1,0);
            return *this;
        }
        cfloat result = *this;
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
    const cfloat cfloat::operator+(const cfloat &cfl) const
    {
        cfloat* result = new cfloat;
        *result = *this;
        *result += cfl;
        return *result;
    }
    const cfloat cfloat::operator+(const float &fl) const
    {
        cfloat* result = new cfloat(*this);
        *result += fl;
        return *result;
    }
    const cfloat cfloat::operator+(const double &db) const
    {
        cfloat* result = new cfloat(*this);
        *result += (float)db;
        return *result;
    }
    const cfloat cfloat::operator+(const int &in) const
    {
        cfloat* result = new cfloat(*this);
        *result += (float)in;
        return *result;
    }

    //Binary Arithmetic -
    const cfloat cfloat::operator-(const cfloat &cfl) const
    {
        cfloat* result = new cfloat;
        *result = *this;
        *result -= cfl;
        return *result;
    }
    const cfloat cfloat::operator-(const float &fl) const
    {
        cfloat* result = new cfloat(*this);
        *result -= fl;
        return *result;
    }
    const cfloat cfloat::operator-(const double &db) const
    {
        cfloat* result = new cfloat(*this);
        *result -= (float) db;
        return *result;
    }
    const cfloat cfloat::operator-(const int &in) const
    {
        cfloat* result = new cfloat(*this);
        *result -= (float)in;
        return *result;
    }

    //Binary Arithmetic *
    const cfloat cfloat::operator*(const cfloat &cfl) const
    {
        cfloat* result = new cfloat;
        *result = *this;
        *result *= cfl;
        return *result;
    }
    const cfloat cfloat::operator*(const float &fl) const
    {
        cfloat* result = new cfloat(*this);
        *result *= fl;
        return *result;
    }
    const cfloat cfloat::operator*(const double &db) const
    {
        cfloat* result = new cfloat(*this);
        *result *= (float)db;
        return *result;
    }
    const cfloat cfloat::operator*(const int &in) const
    {
        cfloat* result = new cfloat(*this);
        *result *= (float)in;
        return *result;
    }

    //Binary Arithmetic /
    const cfloat cfloat::operator/(const cfloat &cfl) const
    {
        cfloat* result = new cfloat;
        *result = *this;
        *result /= cfl;
        return *result;
    }
    const cfloat cfloat::operator/(const float &fl) const
    {
        cfloat* result = new cfloat(*this);
        *result /= fl;
        return *result;
    }
    const cfloat cfloat::operator/(const double &db) const
    {
        cfloat* result = new cfloat(*this);
        *result /= (float)db;
        return *result;
    }
    const cfloat cfloat::operator/(const int &in) const
    {
        cfloat* result = new cfloat(*this);
        *result /= (float)in;
        return *result;
    }

    //Binary integer exponoentiation ^
    const cfloat cfloat::operator^(const int &exp) const
    {
        cfloat* result = new cfloat;
        *result = *this;
        *result ^= exp;
        return *result;
    }

    //Unary operator - reverses phasor (changes phase by pi/2)
    cfloat& cfloat::operator-() const
    {
        cfloat* result = new cfloat(*this);
        if(p){
            result->els[0] *= -1;
        } else{
            result->els[0] *= -1;
            result->els[1] *= -1;
        }
        return *result;
    }

    //Unary operator * produces complex conjugate
    cfloat& cfloat::operator*() const
    {
        cfloat* result = new cfloat(*this);
        result->els[1] *= -1;
        return *result;
    }

    //Logical Comparison ==
    bool cfloat::operator==(const cfloat &cfl) const
    {
        if(this->p == cfl.p){
            if(this->els[0] == cfl.els[0]){
                if(this->els[1] == cfl.els[1]){
                    return true;
                }
            }
        }
        return false;
    }

    //Logical Comparison !=
    bool cfloat::operator!=(const cfloat &cfl) const
    {
        return !(*this == cfl);
    }


//Member Functions

    //Returns real part
    float cfloat::re()
    {
        if(!p)
            return els[0];
        else
            return (els[0]*(cos(els[1])));
    }

    //Return imaginary part
    float cfloat::im()
    {
        if(!p)
            return els[1];
        else
            return (els[0]*(sin(els[1])));
    }

    //Returns magnitude
    float cfloat::mag()
    {
        if(p)
            return els[0];
        else
            return sqrt((els[0] * els[0])+(els[1] * els[1]));
    }

    //Returns phase on complex plane
    float cfloat::phase()
    {
        if(p)
            return els[1];
        else
            return atan2(els[1],els[0]);
    }

    //Returns the complex inverse
    cfloat cfloat::inv()
    {
        cfloat inverse;
        if(p){
            inverse.els[0] = (1 / els[0]);
            inverse.els[1] = (-1 * els[1]);
        } else{
            inverse.els[0] = (els[0])/((els[0] * els[0])+(els[1] * els[1]));
            inverse.els[1] = (-1 * els[1])/((els[0] * els[0])+(els[1] * els[1]));
        }
        return inverse;
    }

    //Changes to polar format, if not already in polar format
    void cfloat::polar()
    {
        if(!p){
            float m = this->mag();
            float ph = this->phase();
            els[0] = m;
            els[1] = ph;
            p = true;
        }
    }

    //Changes to rectangular format, if not already in rectangular format
    void cfloat::rect()
    {
        if(p){
            float a = this->re();
            float b = this->im();
            els[0] = a;
            els[1] = b;
            p = false;
        }
    }

    //Sets both elements of the complex number
    void cfloat::set(float a, float b)
    {
        this->els[0] = a;
        this->els[1] = b;
    }

    //Sets both elements of the complex number and its format (false if rectangular, true if polar)
    void cfloat::set(float a, float b, bool pol)
    {
        this->p = pol;
        this->els[0] = a;
        this->els[1] = b;
    }

    //Print the imaginary number to console using std::cout
    void cfloat::std_print()
    {
        if(!p){
            if(els[1] >= 0)
                std::cout << els[0] << "+" << els[1] << "i" << std::endl << std::endl;
            else
                std::cout << els[0] << els[1] << "i" << std::endl << std::endl;
        }
        else
            std::cout << els[0] << "*exp(" << els[1] << "i)" << std::endl << std::endl;
    }