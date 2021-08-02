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
        cfloat& operator+=(const cfloat &);
        cfloat& operator-=(const cfloat &);
        cfloat& operator*=(const cfloat &);
        cfloat& operator/=(const cfloat &);
        cfloat& operator^=(const int &);
        const cfloat operator+(const cfloat &) const;
        const cfloat operator-(const cfloat &) const;
        const cfloat operator*(const cfloat &) const;
        const cfloat operator/(const cfloat &) const;
        const cfloat operator^(const int &) const;
        bool operator==(const cfloat &) const;
        bool operator!=(const cfloat &) const;

};



#endif