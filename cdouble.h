#ifndef H_CDOUBLE
#define H_CDOUBLE

class cdouble
{
    private:
        double els[2];

    public:
        //Constructors
        cdouble();
        cdouble(double);
        cdouble(double,double);
        cdouble(const cdouble &);


        //Destructors
        ~cdouble();


        //Member Functions
        double re();
        double im();
        double mag();
        double phase();
        cdouble inv();
        void set(double,double);
        void std_print();


        //Operator Overloading
        cdouble& operator=(const cdouble &);
        cdouble& operator=(const char*);

        cdouble& operator+=(const cdouble &);
        cdouble& operator+=(const double &);
        cdouble& operator+=(const float &);
        cdouble& operator+=(const int &);

        cdouble& operator-=(const cdouble &);
        cdouble& operator-=(const double &);
        cdouble& operator-=(const float &);
        cdouble& operator-=(const int &);

        cdouble& operator*=(const cdouble &);
        cdouble& operator*=(const double &);
        cdouble& operator*=(const float &);
        cdouble& operator*=(const int &);

        cdouble& operator/=(const cdouble &);
        cdouble& operator/=(const double &);
        cdouble& operator/=(const float &);
        cdouble& operator/=(const int &);

        cdouble& operator^=(const int &);

        const cdouble operator+(const cdouble &) const;
        const cdouble operator+(const double &) const;
        const cdouble operator+(const float &) const;
        const cdouble operator+(const int &) const;

        const cdouble operator-(const cdouble &) const;
        const cdouble operator-(const double &) const;
        const cdouble operator-(const float &) const;
        const cdouble operator-(const int &) const;

        const cdouble operator*(const cdouble &) const;
        const cdouble operator*(const double &) const;
        const cdouble operator*(const float &) const;
        const cdouble operator*(const int &) const;

        const cdouble operator/(const cdouble &) const;
        const cdouble operator/(const double &) const;
        const cdouble operator/(const float &) const;
        const cdouble operator/(const int &) const;

        const cdouble operator^(const int &) const;

        cdouble& operator-() const;

        cdouble& operator*() const;

        bool operator==(const cdouble &) const;

        bool operator!=(const cdouble &) const;

};

#endif

//make s2f function