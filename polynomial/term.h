#ifndef TERM_H
#define TERM_H
#include <iostream>
using namespace std;

class term
{
public:
    term();
    ~term();

    term(int , float);

    term operator+(const term & ) const ;               // addition
    term operator+(const float & ) const ;              // addition
    friend term operator+(const double &,const term &); // addition
    term operator++();
    term operator++(int);

    term operator-(const term & ) const ;               // subtraction
    term operator-(const float & ) const ;              // subtraction
    friend term operator-(const double &,const term &); // subtraction
    term operator--();
    term operator--(int);


    term operator*(const term & ) const ;               // multiplication
    term operator*(const float & ) const ;              // multiplication
    friend term operator*(const double &,const term &); // multiplication

    term operator/(const term & ) const ;               //division
    term operator/(const float & ) const ;              //division
    friend term operator/(const double &,const term &); // division

    term operator~() const ;
    term &operator=(const term & ); // assignment
    double operator()(const float & ) const;

    term &operator+=(const term & );
    term &operator-=(const term & );
    term &operator*=(const term & );
    term &operator/=(const term & );


    bool operator==(const term & ) const;
    bool operator==(const float & ) const;
    friend bool operator==(const double &,const term &);

    bool operator!=(const term & ) const;
    bool operator!=(const float & ) const;
    friend bool operator!=(const double &,const term &);

    bool operator>(const term & ) const;
    bool operator>(const float & ) const;
    friend bool operator>(const double &,const term &);

    bool operator<(const term & ) const;
    bool operator<(const float & ) const;
    friend bool operator<(const double &,const term &);

    bool operator>=(const term & ) const;
    bool operator>=(const float & ) const;

    bool operator<=(const term & ) const;
    bool operator<=(const float & ) const;

    void exponentset(int ex) {exponent = ex;}
    void coefficientset(float co) {coefficient = co;}
    int exponentget() {return exponent;}
    float coefficientget() {return coefficient;}


    friend istream& operator>>(istream&,term&);
    friend ostream& operator<<(ostream&,term);
    term &operator <<(string & );
    void operator >>(string & );

private:
    int exponent;
    float coefficient;

};

#endif // TERM_H
