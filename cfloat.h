#ifndef H_CFLOAT
#define H_CFLOAT

class cfloat
{
    private:
        float els[2];
        bool p = false; //determines if polar format or not

    public:
        //Constructors
        cfloat();
        cfloat(bool);
        cfloat(float);
        cfloat(float,float);
        cfloat(float,float,bool);
        cfloat(const cfloat &);


        //Destructors
        ~cfloat();


        //Member Functions
        float re();
        float im();
        float mag();
        float phase();
        cfloat inv();
        void polar();
        void rect();
        void set(float,float);
        void set(float,float,bool);
        void std_print();


        //Operator Overloading
        cfloat& operator=(const cfloat &);
        cfloat& operator=(const char*);

        cfloat& operator+=(const cfloat &);
        cfloat& operator+=(const float &);
        cfloat& operator+=(const double &);
        cfloat& operator+=(const int &);

        cfloat& operator-=(const cfloat &);
        cfloat& operator-=(const float &);
        cfloat& operator-=(const double &);
        cfloat& operator-=(const int &);

        cfloat& operator*=(const cfloat &);
        cfloat& operator*=(const float &);
        cfloat& operator*=(const double &);
        cfloat& operator*=(const int &);

        cfloat& operator/=(const cfloat &);
        cfloat& operator/=(const float &);
        cfloat& operator/=(const double &);
        cfloat& operator/=(const int &);

        cfloat& operator^=(const int &);

        const cfloat operator+(const cfloat &) const;
        const cfloat operator+(const float &) const;
        const cfloat operator+(const double &) const;
        const cfloat operator+(const int &) const;

        const cfloat operator-(const cfloat &) const;
        const cfloat operator-(const float &) const;
        const cfloat operator-(const double &) const;
        const cfloat operator-(const int &) const;

        const cfloat operator*(const cfloat &) const;
        const cfloat operator*(const float &) const;
        const cfloat operator*(const double &) const;
        const cfloat operator*(const int &) const;

        const cfloat operator/(const cfloat &) const;
        const cfloat operator/(const float &) const;
        const cfloat operator/(const double &) const;
        const cfloat operator/(const int &) const;

        const cfloat operator^(const int &) const;

        cfloat& operator-() const;

        cfloat& operator*() const;

        bool operator==(const cfloat &) const;

        bool operator!=(const cfloat &) const;

};

#endif

//make s2f function