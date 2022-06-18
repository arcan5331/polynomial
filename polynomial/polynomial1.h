#ifndef POLYNOMIAL1_H
#define POLYNOMIAL1_H
#include <iostream>
#include <fstream>
#include <vector>
#include "term.h"
#include<fstream>

using namespace std;

class polynomial1
{
public:
    polynomial1();

    friend istream& operator>>(istream&,polynomial1&);
    friend ostream& operator<<(ostream&,polynomial1 );
    friend void operator<<(polynomial1&,string );
    friend void operator>>(polynomial1 ,string& );


    polynomial1 &operator=(const polynomial1 & ) ;




    polynomial1 &operator+=(const polynomial1 & ) ;
    polynomial1 &operator+=(const term & ) ;
    polynomial1 &operator+=(const float & ) ;

    polynomial1 &operator-=(const polynomial1 & ) ;
    polynomial1 &operator-=(const term & ) ;
    polynomial1 &operator-=(const float & ) ;

    polynomial1 &operator*=(const polynomial1 & ) ;
    polynomial1 &operator*=(const term & ) ;
    polynomial1 &operator*=(const float & ) ;

    polynomial1 &operator/=(const polynomial1 & ) ;
    polynomial1 &operator/=(const term & ) ;
    polynomial1 &operator/=(const float & ) ;



    polynomial1 operator+(const polynomial1 & ) const ;
    polynomial1 operator+(const term & ) const ;
    polynomial1 operator+(const float & ) const ;
    friend polynomial1 operator+(const double &,const polynomial1 &);
    friend polynomial1 operator+(const term &,const polynomial1 &);
    polynomial1 operator++();
    polynomial1 operator++(int);


    polynomial1 operator -(const polynomial1 & ) const ;
    polynomial1 operator -(const term & ) const ;
    polynomial1 operator-(const float & ) const ;
    friend polynomial1 operator-(const double &,const polynomial1 &);
    friend polynomial1 operator-(const term &,const polynomial1 &);
    polynomial1 operator--();
    polynomial1 operator--(int);


    polynomial1 operator *(const polynomial1 &) const ;
    polynomial1 operator *(const term &) const ;
    polynomial1 operator *(const float &) const ;
    friend polynomial1 operator * (const term &,const polynomial1 &);
    friend polynomial1 operator * (const float &,const polynomial1 &);

    polynomial1 operator /(const polynomial1 &) const ;
    polynomial1 operator /(const term &) const ;
    polynomial1 operator /(const float &) const ;
    friend polynomial1 operator / (const term &,const polynomial1 &);
    friend polynomial1 operator / (const float &,const polynomial1 &);



    bool operator == (const polynomial1 & ) const;
    bool operator == (const term & ) const;
    bool operator == (const float & ) const;
    friend  bool operator == (const term &,const polynomial1 & ) ;
    friend  bool operator == (const float &,const polynomial1 & ) ;

    bool operator != (const polynomial1 & ) const;
    bool operator != (const term & ) const;
    bool operator != (const float & ) const;
    friend  bool operator != (const term &,const polynomial1 & ) ;
    friend  bool operator != (const float &,const polynomial1 & ) ;

    bool operator > (const polynomial1 & ) const;
    bool operator > (const term & ) const;
    bool operator > (const float & ) const;
    friend  bool operator > (const term &,const polynomial1 & ) ;
    friend  bool operator > (const float &,const polynomial1 & ) ;

    bool operator < (const polynomial1 & ) const;
    bool operator < (const term & ) const;
    bool operator < (const float & ) const;
    friend  bool operator < (const term &,const polynomial1 & ) ;
    friend  bool operator < (const float &,const polynomial1 & ) ;

    bool operator >= (const polynomial1 & ) const;
    bool operator >= (const term & ) const;
    bool operator >= (const float & ) const;
    friend  bool operator >= (const term &,const polynomial1 & ) ;
    friend  bool operator >= (const float &,const polynomial1 & ) ;

    bool operator <= (const polynomial1 & ) const;
    bool operator <= (const term & ) const;
    bool operator <= (const float & ) const;
    friend  bool operator <= (const term &,const polynomial1 & ) ;
    friend  bool operator <= (const float &,const polynomial1 & ) ;

    double operator ()(const float & ) const;
    polynomial1 operator~() const;



    void bineryfwrite(string );
    void bineryfread(string );

    void saveFile(ofstream &);


    int degree();
    polynomial1 &compile();
    void order();


    int terms_num() {return terms.size();}

private:
    vector<term> terms;
};

#endif // POLYNOMIAL1_H
