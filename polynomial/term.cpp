#include "term.h"
#include <iostream>
#include <math.h>
#include <algorithm>
#include <sstream>

using namespace std;
void wrong_Input();

term::term()
{
    exponent = 0;
    coefficient = 1;
}
term::~term()
{

}
term::term(int e,float c)
{
    exponent = e;
    coefficient = c;
}
//---------------------------------------------------
ostream& operator<<(ostream& out,term t) {
    /* 1x^2
     *
     *
     *
     *
     */
    if (t.exponent == 1)
    {
        if(t.coefficient != 1)
        {
            out << t.coefficient << "x";
        }
        else
        {
            out << "x";
        }
    }
    else if (t.exponent == 0)
    {
        out << t.coefficient;
    }
    else
    {
        if (t.coefficient != 1)
        {
            out << t.coefficient << "x^" << t.exponent;
        }
        else
        {
            out << "x^" << t.exponent;
        }
    }
    return out;
}


istream& operator >>(istream& in,term &t) {
    bool power = false,there_was_x = false;
    char a;

    string tempcoefficient = "",tempexponent = "";
    do
    {
    in.get(a);
    if (a == 'x')
    {
        there_was_x = true;
    }
    if (!power) {
        if (a != 'x' && a != '\n' && a != '^') {
            tempcoefficient += a;
        }
        if (a == '^') {
            power = true;
        }
    } else {
        if(a != '\n' && a != 'x')
        {
            tempexponent += a;
        }
    }

    } while (a != '\n');
    if (there_was_x && tempexponent.empty())
    {
        tempexponent +='1';
    }
    if(tempexponent.length() == 1)
    {
        if (tempexponent.at(0) == '+')
        {
            tempexponent.replace(0,1,"1");
        }
        else if (tempexponent.at(0) == '-')
        {
            tempexponent.replace(0,1,"-1");
        }
    }
    if(tempcoefficient.length() == 1)
    {
        if (tempcoefficient.at(0) == '+')
        {
            string x = "1";
            tempcoefficient.replace(0,1,x);
        }
        else if (tempcoefficient.at(0) == '-')
        {
            string x = "-";
            tempcoefficient.replace(0,1,x);
            tempcoefficient += '1';
        }
    }
    if (!tempexponent.empty())
    {
        t.exponentset(stoi(tempexponent));
    }
    if (!tempcoefficient.empty())
    {
        t.coefficientset(stof(tempcoefficient));

    }

    return  in;
}



term &term::operator <<(string &s) {
    bool power = false,there_was_x = false;
    char a;
    int i = 0;
    s.erase(remove(s.begin(),s.end(),' ') , s.end());
    string tempcoefficient = "",tempexponent = "";
    s.append("\n");
    do
    {
    a = s.at(i);
    if (a == 'x')
    {
        there_was_x = true;
    }
    if (!power) {
        if (a != 'x' && a != '\n' && a != '^') {
            tempcoefficient += a;
        }
        if (a == '^') {
            power = true;
        }
    } else {
        if(a != '\n' && a != 'x')
        {
            tempexponent += a;
        }
    }
    ++i;
    } while (a != '\n');
    if (there_was_x && tempexponent.empty())
    {
        tempexponent +='1';
    }
    if(tempexponent.length() == 1)
    {
        if (tempexponent.at(0) == '+')
        {
            tempexponent.replace(0,1,"1");
        }
        else if (tempexponent.at(0) == '-')
        {
            tempexponent.replace(0,1,"-1");
        }
    }
    if(tempcoefficient.length() == 1)
    {
        if (tempcoefficient.at(0) == '+')
        {
            string x = "1";
            tempcoefficient.replace(0,1,x);
        }
        else if (tempcoefficient.at(0) == '-')
        {
            string x = "-";
            tempcoefficient.replace(0,1,x);
            tempcoefficient += '1';
        }
    }
    if (!tempexponent.empty())
    {
        exponentset(stoi(tempexponent));
    }
    if (!tempcoefficient.empty())
    {
        coefficientset(stof(tempcoefficient));

    }
    return *this;
}
//----------------------------------------------------
term term::operator+(const term &t ) const {
    float temp;
    if (exponent != t.exponent)
    {
        throw -11;
    }
    temp = coefficient + t.coefficient;
    term sum(exponent,temp);
    return sum;
}
term term::operator+(const float &n ) const {
    float temp;
    if (exponent != 0)
    {
        throw -12;
    }
    temp = coefficient + n;
    term sum(exponent,temp);
    return sum;
}
term operator+(const double &n,const term &t) {
    float temp;
    const int exp = t.exponent;
    const float ceo = t.coefficient;
    if (exp != 0)
    {
        throw -13;
    }
    temp=n+ceo;
    term sum(exp,temp);
    return sum;
}
term term::operator++()
{
    *this = (*this + 1);
    return *this;
}
term term::operator++(int )
{
    term p = *this;
    *this = (*this + 1);
    return p;
}

term term::operator-(const term &t ) const {
    float temp;
    if (exponent != t.exponent)
    {
        throw -21;
    }
    temp = coefficient - t.coefficient;
    term sub(exponent,temp);
    return sub;
}
term term::operator-(const float &n ) const {
    float temp;
    if (exponent != 0)
    {
        throw -22;
    }
    temp = coefficient - n;
    term sub(exponent,temp);
    return sub;
}
term operator-(const double &n,const term &t) {
    float temp;
    const int exp = t.exponent;
    const float ceo = t.coefficient;
    if (exp != 0)
    {
        throw -23;
    }
    temp = n - ceo;
    term sub(exp,temp);
    return sub;
}
term term::operator--()
{
    *this = (*this - 1);
    return *this;
}
term term::operator--(int )
{
    term p = *this;
    *this = (*this - 1);
    return p;
}

term term::operator*(const term &t ) const {
    float temp;
    int temk;
    temp = coefficient * t.coefficient;
    temk = exponent + t.exponent;
    term mult(temk,temp);
    return mult;
}
term term::operator*(const float &n ) const {
    term mult(0,n);
    mult *= *this;
    return mult;
}
term operator*(const double &n,const term &t) {
    float temp;
    const int exp = t.exponent;
    const float ceo = t.coefficient;
    temp = n * ceo;
    term sum(exp,temp);
    return sum;
}

term term::operator/(const term &t ) const {
    float temp;
    int temk;
    temp = (coefficient / t.coefficient);
    temk = exponent - t.exponent;
    term div(temk,temp);
    return div;
}
term term::operator/(const float &n ) const {
    term mult(0,n);
    mult /= *this;
    return mult;
}
term operator/(const double &n,const term &t) {
    float temp;
    const int exp = (-t.exponent);
    const float ceo = t.coefficient;
    temp = (n / ceo);
    term div(exp,temp);
    return div;
}

//----------------------------------------------------
term &term::operator =(const term &t) {
    exponent = t.exponent;
    coefficient = t.coefficient;
    return *this;
}

//----------------------------------------------------
term &term::operator +=(const term &t) {
    *this = *this + t;
    return *this;
}

term &term::operator-=( const term &t ){
    *this = *this - t;
    return *this;
}

term &term::operator*=( const term &t )
{
    *this = *this * t;
    return *this;
}

term &term::operator/=( const term &t ){
    *this = *this / t;
    return *this;
}
//----------------------------------------------------
bool term::operator==(const term &t ) const {
    bool isit = false;
    if (exponent == t.exponent && coefficient == t.exponent)
    {
        isit = true;
    }
        return isit;
}
bool term::operator==(const float &n ) const {
    bool isit = false;
    if (exponent == 0 && coefficient == n)
    {
        isit = true;
    }
        return isit;
}
bool operator==(const double &n,const term &t) {
    bool isit = false;
    const int exp = t.exponent;
    const float ceo = t.coefficient;
    if ( exp == 0 && ceo == n)
    {
        isit=true;
    }
    return isit;
}

bool term::operator!=(const term &t ) const {
    return !(*this == t);
}
bool term::operator!=(const float &n ) const {
    return !(*this == n);
}
bool operator!=(const double &n,const term &t) {
    return !(n==t);
}

bool term::operator>(const term &t ) const {
    bool isit = false;
    if(exponent > t.exponent)
    {
        isit = true;
    }
    else if (exponent == t.exponent)
    {
        if(coefficient > t.coefficient)
            isit = true;
    }
    return isit;
}
bool term::operator>(const float &n ) const {
    bool isit = false;
    if(exponent > 0)
    {
        isit = true;
    }
    else if (exponent == 0)
    {
        if(coefficient > n)
        {
            isit = true;
        }
    }

    return isit;
}
bool operator>(const double &n,const term &t) {
    bool isit = false;
    const int exp = t.exponent;
    const float ceo = t.coefficient;
    if(exp < 0)
    {
        isit = true;
    }
    if (exp == 0)
    {
        if (n > ceo)
        {
            isit = true;
        }
    }
    return isit;
}

bool term::operator<(const term &t ) const {
    bool isit = false;
    if(exponent < t.exponent)
    {
        isit = true;
    }
    else if (exponent == t.exponent)
    {
        if(coefficient < t.coefficient)
        {
            isit = true;
        }
    }

    return isit;
}
bool term::operator<(const float &n ) const {
    bool isit = false;
    if(exponent < 0){
        isit = true;
    }
    else if (exponent == 0)
    {
        if(coefficient < n)
            isit = true;
    }

    return isit;
}
bool operator<(const double &n,const term &t) {
    bool isit = false;
    const int exp = t.exponent;
    const float ceo = t.coefficient;
    if(exp > 0)
    {
        isit = true;
    }
    if (exp == 0)
    {
        if (n < ceo)
        {
            isit = true;
        }
    }
    return isit;
}

bool term::operator>=(const term &t ) const {
    bool isit = false;
    if(*this > t || *this == t)
    {
        isit = true;
    }
    return isit;
}
bool term::operator>=(const float &t ) const {
    bool isit = false;
    if(*this > t || *this == t)
    {
        isit = true;
    }
    return isit;
}
bool operator>=(const double &n,const term &t) {
    bool isit = false;
    if(n > t || n == t)
    {
        isit = true;
    }
    return isit;
}

bool term::operator<=(const term &t ) const {
    bool isit = false;
    if(*this < t || *this == t)
    {
        isit = true;
    }
    return isit;
}
bool term::operator<=(const float &t ) const {
    bool isit = false;
    if(*this > t || *this == t)
    {
        isit = true;
    }
    return isit;
}
bool operator<=(const double &n,const term &t) {
    bool isit = false;
    if(n < t || n == t)
    {
        isit = true;
    }
    return isit;
}
//----------------------------------------------------

term term::operator~() const {
    if (exponent == 0)
    {
        term x(0,0);
        return x;
    }
    int exp = exponent - 1;
    float coe = coefficient * exponent;
    term temp(exp,coe);
    return temp;
}

double term::operator ()(const float &x) const{
    double final = pow(x,exponent);
    final *= coefficient;
    return final;
}



void term::operator >>(string &s )
{
    ostringstream ceo,exp;
    if(coefficient > 0)
    {
        s += '+';
    }

    ceo << coefficient;
    exp << exponent;
    s += ceo.str();
    s += 'x';
    s += '^';
    s += exp.str();
    s += '\n';
}





//----------------------------------------------------
void wrong_Input() {
   cout << "invalid parameters!\n";
}




















