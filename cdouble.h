#ifndef H_CDOUBLE
#define H_CDOUBLE

class cdouble
{
    private:
        double els[2];

    public:
        //Constructors
        cdouble();
        explicit cdouble(double);
        cdouble(double,double);
        cdouble(const cdouble &);


        //Destructors
        ~cdouble();


        //Member Functions
        double re() const;
        double im() const;
        double mag() const;
        double phase() const;
        cdouble inv() const;
        void set(double,double);
        void rect_print() const;
        void polar_print() const;


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
        friend const cdouble operator+(const double &, const cdouble &);
        friend const cdouble operator+(const float &, const cdouble &);
        friend const cdouble operator+(const int &, const cdouble &);

        const cdouble operator-(const cdouble &) const;
        const cdouble operator-(const double &) const;
        const cdouble operator-(const float &) const;
        const cdouble operator-(const int &) const;
        friend const cdouble operator-(const double &, const cdouble &);
        friend const cdouble operator-(const float &, const cdouble &);
        friend const cdouble operator-(const int &, const cdouble &);

        const cdouble operator*(const cdouble &) const;
        const cdouble operator*(const double &) const;
        const cdouble operator*(const float &) const;
        const cdouble operator*(const int &) const;
        friend const cdouble operator*(const double &, const cdouble &);
        friend const cdouble operator*(const float &, const cdouble &);
        friend const cdouble operator*(const int &, const cdouble &);

        const cdouble operator/(const cdouble &) const;
        const cdouble operator/(const double &) const;
        const cdouble operator/(const float &) const;
        const cdouble operator/(const int &) const;
        friend const cdouble operator/(const double &, const cdouble &);
        friend const cdouble operator/(const float &, const cdouble &);
        friend const cdouble operator/(const int &, const cdouble &);

        const cdouble operator^(const int &) const;
        friend const cdouble operator^(const double &, const cdouble &);
        friend const cdouble operator^(const float &, const cdouble &);
        friend const cdouble operator^(const int &, const cdouble &);

        cdouble& operator-() const;

        cdouble& operator*() const;

        bool operator==(const cdouble &) const;

        bool operator!=(const cdouble &) const;

};

#endif

//make s2f function