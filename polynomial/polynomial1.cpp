#include "polynomial1.h"
#include <iostream>
#include <string>
#include <ctype.h>
#include <string>
#include <algorithm>
#include <fstream>



using namespace std;
void swap(term& ,term& );
polynomial1::polynomial1()
{
    term zero(0,0);
    terms.push_back(zero);
}
//---------------------------------------------------
istream& operator>>(istream& in,polynomial1 &t) {
    string input = "",temp = "";
    char a;
    int j = 0;
    bool power = false;
    getline(cin,input);
    input.erase(remove(input.begin(),input.end(),' ') , input.end());
    input.append("\n");
    bool wrong_input = false;
    for(int i = 0; i < input.length(); ++i )
    {
        char x = input.at(i);
        if(x != 'x' && x != '^' && x != '+' && x != '-' && !isdigit(x) && x != '\n' && x != '.')
        {
            wrong_input = true;
        }
    }
    if(wrong_input)
    {
        throw -101;
    }
    do
    {
        for (int i = 0; i < input.length(); ++i,++j)
        {
            a = input.at(i);
            if (a == '^')
            {
                power = true;
            }
            if ((a == '-' || a == '+' || a =='\n') && i != 0 && !power)
            {
                term t_temp;
                t_temp << temp;
                t.terms.push_back(t_temp);
                temp = "";
                temp += a;
                continue;
            }
            temp += a;

            if ((temp.back() == '-' || temp.back() == '+' || isdigit(a)) && power)
            {
                power = false;
            }
        }
    } while(j < input.length());
   return in;
}
void operator>>(polynomial1 p,string &s )
{
    string temp;
    for(int i = 0;i < p.terms.size();i++,temp = "")
    {
        p.terms.at(i) >> temp;
        s += temp;
    }
}

ostream& operator<<(ostream& out,polynomial1 t) {

    for (int i = 0; i < t.terms.size(); i++) {
        if (i == 0)
        {
            cout << t.terms.at(i) << ' ';
            continue;
        }
        if (t.terms[i].coefficientget() > 0) {
            cout << '+' <<t.terms.at(i) << ' ';
        }
        if (t.terms[i].coefficientget() < 0) {
            cout << t.terms.at(i) << ' ';
        }
    }


    return out;
}
void operator<<(polynomial1&t ,string s) {
    string temp = "";
    char a;
    int j = 0;
    bool power = false;
    s.erase(remove(s.begin(),s.end(),' ') , s.end());
    s.erase(remove(s.begin(),s.end(),'\n') , s.end());
    s.append("\n");
    bool wrong_input = false;
    for(int i = 0; i < s.length(); ++i )
    {
        char x = s.at(i);
        if(x != 'x' && x != '^' && x != '+' && x != '-' && !isdigit(x) && x != '\n' && x != '.')
        {
            wrong_input = true;
        }
    }
    if(wrong_input)
    {
        throw -101;
    }
    do {
        for (int i = 0; i < s.length(); ++i,++j)
        {
            a = s.at(i);
            if (a == '^')
            {
                power = true;
            }
            if ((a == '-' || a == '+' || a =='\n') && i != 0 && !power)
            {
                term t_temp;
                t_temp << temp;
                t.terms.push_back(t_temp);
                temp = "";
                temp += a;
                continue;
            }
            temp += a;

            if ((temp.back() == '-' || temp.back() == '+' || isdigit(a)) && power)
            {
                power = false;
            }
        }
    } while(j < s.length());





}






//---------------------------------------------------

polynomial1 &polynomial1::operator=(const polynomial1 &t ) {
    terms.clear();
    *this += t;
    return *this;
}
polynomial1 &polynomial1::operator+=(const polynomial1 &t ) {
    terms.insert(terms.end(),t.terms.begin(),t.terms.end());
    compile();
    return *this;
}
polynomial1 &polynomial1::operator+=(const term &t ) {
    terms.push_back(t);
    compile();
    return *this;
}
polynomial1 &polynomial1::operator+=(const float &t ) {
    term temp(0,t);
    *this += temp;
    compile();
    return *this;
}

polynomial1 &polynomial1::operator-=(const polynomial1 &t ) {
    polynomial1 temp;
    temp = t;
    for (int i = 0; i < temp.terms_num() ; i++)
    {
        temp.terms.at(i).coefficientset(-temp.terms.at(i).coefficientget());
    }
    *this += temp;
    compile();
    return *this;
}
polynomial1 &polynomial1::operator-=(const term &t ) {
    term temp;
    temp = t;
    temp.coefficientset(-temp.coefficientget());
    *this += temp;
    compile();
    return *this;
}
polynomial1 &polynomial1::operator-=(const float &t ) {

    term temp(0,-t);
    terms.push_back(temp);
    compile();
    return *this;
}


polynomial1 polynomial1::operator +(const polynomial1 &t ) const {
    polynomial1 temp;
    temp += *this;
    temp += t;
    temp.compile();
    return temp;
}
polynomial1 polynomial1::operator +(const term &t ) const {
    polynomial1 temp;
    temp += t;
    return temp;
}
polynomial1 polynomial1::operator +(const float &t ) const {
    polynomial1 temp;
    temp += t;
    return temp;
}
polynomial1 operator+(const double &d,const polynomial1 &p)
{
    polynomial1 temp;
    temp = p;
    temp += d;
    return temp;
}
polynomial1 operator+(const term &t,const polynomial1 &p)
{
    polynomial1 temp;
    temp = p;
    temp += t;
    return temp;
}
polynomial1 polynomial1::operator++()
{
    polynomial1 p = *this;
    p += 1;
    return p;
}
polynomial1 polynomial1::operator++(int )
{
    polynomial1 p = *this;
    *this += 1;
    return p;
}




polynomial1 polynomial1::operator -(const polynomial1 &t ) const {
    polynomial1 temp;
    temp = *this;
    temp -= t;
    temp.compile();
    temp.order();
    return temp;
}
polynomial1 polynomial1::operator -(const term &t ) const {
    polynomial1 temp;
    temp -= t;
    temp.compile();
    temp.order();
    return temp;
}
polynomial1 polynomial1::operator -(const float &t ) const {
    polynomial1 temp;
    temp -= t;
    temp.compile();
    temp.order();
    return temp;
}
polynomial1 operator-(const double &d,const polynomial1 &p)
{
    polynomial1 temp;
    temp -= p;
    temp += d;
    temp.compile();
    temp.order();
    return temp;
}
polynomial1 operator-(const term &t,const polynomial1 &p)
{
    polynomial1 temp;
    temp -= p;
    temp += t;
    temp.compile();
    temp.order();
    return temp;
}
polynomial1 polynomial1::operator--()
{
    polynomial1 p = *this;
    p -= 1;
    return p;
}
polynomial1 polynomial1::operator--(int )
{
    polynomial1 p = *this;
    *this -= 1;
    return p;
}


polynomial1 polynomial1::operator *(const polynomial1 &p) const
{
    polynomial1 temp;
    for(int i = 0; i < terms.size(); i++)
    {
        for (int j = 0; j < p.terms.size(); j++)
        {
            term t = (terms.at(i) * p.terms.at(j));
            temp.terms.push_back(t);
        }
    }
    temp.compile();
    temp.order();

    return temp;
}
polynomial1 polynomial1::operator *(const term &t) const
{
    polynomial1 temp = *this;
    for(int i = 0; i < temp.terms.size(); i++)
    {
        temp.terms.at(i) *= t;
    }
    temp.compile();
    temp.order();
    return temp;
}
polynomial1 polynomial1::operator *(const float &f) const
{
    polynomial1 temp = *this;
    for(int i = 0; i < temp.terms.size(); i++)
    {
        temp.terms.at(i) = temp.terms.at(i) * f;
    }
    temp.compile();
    temp.order();

    return temp;
}
polynomial1 operator * (const term &t,const polynomial1 &p)
{
    polynomial1 temp = (p * t);
    return temp;
}
polynomial1 operator * (const float &f, const polynomial1 &p)
{
    polynomial1 temp = (p * f);
    return temp;
}

polynomial1 polynomial1::operator /(const polynomial1 &p) const
{
    term t;
    polynomial1 temp;
    for(int i = 0; i < terms.size(); i++)
    {
        for (int j = 0; j < p.terms.size(); j++)
        {
            t = (terms.at(i) / p.terms.at(j));
            temp.terms.push_back(t);
        }
    }

    for(int i = 0; i < temp.terms_num() ; i++)
    {
        if(temp.terms.at(i).coefficientget() > 99999999999999)
        {
            temp.terms.erase(temp.terms.begin() + i);
        }
    }
    temp.compile();
    temp.order();
    return temp;
}
polynomial1 polynomial1::operator /(const term &t) const
{
    polynomial1 temp = *this;
    polynomial1 pt;
    pt.terms.push_back(t);
    temp /= pt;
    temp.compile();
    temp.order();
    return temp;
}
polynomial1 polynomial1::operator /(const float &f) const
{
    polynomial1 temp = *this;
    polynomial1 pt;
    term t(0,f);
    pt.terms.push_back(t);
    temp /= pt;
    temp.compile();
    temp.order();
    return temp;
}
polynomial1 operator / (const term &t,const polynomial1 &p)
{
    polynomial1 temp;
    temp.terms.push_back(t);
    temp /= p;
    temp.compile();
    return temp;
}
polynomial1 operator/ (const float &f, const polynomial1 &p)
{
    polynomial1 temp = p;
    polynomial1 pt;
    term t(0,f);
    pt.terms.push_back(t);
    pt /= temp;
    pt.compile();
    return pt;
}



bool polynomial1::operator==(const polynomial1 &p) const
{
    bool isit = true;
    bool coun = true;

    for(int i = 0; i < terms.size() && coun ;i++)
    {
        bool tisequl = false;
        for (int j = 0; j < p.terms.size() && !tisequl ;j++)
        {
            if(terms.at(i) == p.terms.at(j))
            {
                tisequl = true;
            }
        }
        if(!tisequl)
        {
            isit = false;
            coun = false;
        }

    }

    return isit;
}
bool polynomial1::operator==(const term &t) const
{
    polynomial1 temp;
    temp += t;
    return temp == *this;
}
bool polynomial1::operator==(const float &f) const
{
    polynomial1 temp;
    temp += f;
    return temp == *this;
}
bool operator == (const term &t,const polynomial1 &p )
{
    polynomial1 temp;
    temp += t;
    return temp == p;
}
bool operator == (const float &f,const polynomial1 &p )
{
    polynomial1 temp;
    temp += f;
    return temp == p;
}

bool polynomial1::operator!=(const polynomial1 &p) const
{
    bool isit = true;
    bool coun = true;

    for(int i = 0; i < terms.size() && coun ;i++)
    {
        bool tisequl = false;
        for (int j = 0; j < p.terms.size() && !tisequl ;j++)
        {
            if(terms.at(i) == p.terms.at(j))
            {
                tisequl = true;
            }
        }
        if(!tisequl)
        {
            isit = false;
            coun = false;
        }

    }

    return !isit;
}
bool polynomial1::operator!=(const term &t) const
{
    polynomial1 temp;
    temp += t;
    return !(temp == *this);
}
bool polynomial1::operator!=(const float &f) const
{
    polynomial1 temp;
    temp += f;
    return !(temp == *this);
}
bool operator != (const term &t,const polynomial1 &p )
{
    polynomial1 temp;
    temp += t;
    return !(temp == p);
}
bool operator != (const float &f,const polynomial1 &p )
{
    polynomial1 temp;
    temp += f;
    return !(temp == p);
}

bool polynomial1::operator>(const polynomial1 &p) const
{
    bool isit = false, coun = true;
    polynomial1 temp = *this;
    for(int i = 0; i < temp.terms.size() && coun ;i++)
    {
        for (int j = 0; j < p.terms.size() && coun ;j++)
        {
            if (temp.terms.at(i) > p.terms.at(j))
            {
                isit = true;
                coun = false;
            }
        }
    }
    return isit;
}
bool polynomial1::operator>(const term &t) const
{
    bool isit = false;
    bool count = true;
    for(int i = 0; i < terms.size() && count ;i++)
    {
        if(terms.at(i) > t)
        {
            isit = true;
            count = false;
        }
    }
    return isit;
}
bool polynomial1::operator>(const float &f) const
{
    term temp(0,f);
    return *this > temp;
}
bool operator > (const term &t,const polynomial1 &p )
{
    bool isit = false;
    polynomial1 temp = p;
    for(int i = 0; i < temp.terms.size() && !isit; i++)
    {
        if(t > temp.terms.at(i))
        {
            isit = true;
        }
    }
    return isit;
}
bool operator > (const float &f,const polynomial1 &p )
{
    bool isit = false;
    term t(0,f);
    if(t > p)
    {
        isit = true;
    }
    return isit;

}

bool polynomial1::operator < (const polynomial1 &p) const
{
    bool isit = false, coun = true;
    polynomial1 temp = *this;
    for(int i = 0; i < temp.terms.size() && coun ;i++)
    {
        for (int j = 0; j < p.terms.size() && coun ;j++)
        {
            if (temp.terms.at(i) < p.terms.at(j))
            {
                isit = true;
                coun = false;
            }
        }
    }
    return isit;
}
bool polynomial1::operator < (const term &t) const
{
    bool isit = false;
    bool count = true;
    for(int i = 0; i < terms.size() && count ;i++)
    {
        if(terms.at(i) < t)
        {
            isit = true;
            count = false;
        }
    }
    return isit;
}
bool polynomial1::operator < (const float &f) const
{
    term temp(0,f);
    return *this < temp;
}
bool operator < (const term &t,const polynomial1 &p )
{
    bool isit = false;
    polynomial1 temp = p;
    for(int i = 0; i < temp.terms.size() && !isit; i++)
    {
        if(t < temp.terms.at(i))
        {
            isit = true;
        }
    }
    return isit;
}
bool operator < (const float &f,const polynomial1 &p )
{
    bool isit = false;
    term t(0,f);
    if(t < p)
    {
        isit = true;
    }
    return isit;

}

bool polynomial1::operator >= (const polynomial1 &p) const
{
    return (*this > p || *this == p);
}
bool polynomial1::operator >= (const term &t) const
{
    return (*this > t || *this == t);
}
bool polynomial1::operator >= (const float &f) const
{
    return (*this > f || *this == f);
}
bool operator >= (const term &t,const polynomial1 &p )
{
    return (t > p || t == p);
}
bool operator >= (const float &f,const polynomial1 &p )
{
    return (f > p || f == p);
}

bool polynomial1::operator <= (const polynomial1 &p) const
{
    return (*this < p || *this == p);
}
bool polynomial1::operator <= (const term &t) const
{
    return (*this < t || *this == t);
}
bool polynomial1::operator <= (const float &f) const
{
    return (*this < f || *this == f);
}
bool operator <= (const term &t,const polynomial1 &p )
{
    return (t < p || t == p);
}
bool operator <= (const float &f,const polynomial1 &p )
{
    return (f < p || f == p);
}


double polynomial1::operator()(const float &f ) const
{
    polynomial1 temp = *this;
    temp.compile();
    temp.order();
    for (int i = 0; i < temp.terms.size() ; i++)
    {
        term a(0,temp.terms.at(i)(f));
        temp.terms.at(i) = a;
        temp.compile();
        temp.order();
    }
    double ret = 0;
    for (int i = 0; i < temp.terms_num();i++)
    {
        if(temp.terms.at(i).exponentget() == 0)
        {
            ret += temp.terms.at(i).coefficientget();
        }
    }
    return ret;
}
polynomial1 polynomial1::operator~() const
{
    polynomial1 temp = *this;
    for (int i = 0; i < temp.terms_num();i++)
    {
        temp.terms.at(i) = ~temp.terms.at(i);
        temp.compile();
        temp.order();
    }
    return temp;
}




polynomial1 &polynomial1::compile() {
    term zero(0,0);
    order();

    for(int i = 0;i < terms_num() - 1;i++ )
    {
        for (int j = i + 1; j < terms_num(); j++)
        {
            if(terms.at(i).exponentget() == terms.at(j).exponentget() && terms.at(i) != zero) {
                terms.at(i) += terms.at(j);
                terms.at(j) = zero;
            }
        }
    }
    order();
    return *this;
}
void polynomial1::order() {
    term zero(0,0);
    for(int i = 0;i < terms_num() - 1;i++ )
    {
        for (int j = i + 1; j < terms_num(); j++)
        {
            if (terms.at(i).exponentget() < terms.at(j).exponentget())
            {
                swap(terms.at(i), terms.at(j));
            }
            else if (terms.at(i).exponentget() == terms.at(j).exponentget())
            {
                if(terms.at(i).coefficientget() < terms.at(j).coefficientget())
                {
                    swap(terms.at(i), terms.at(j));
                }
            }
        }
    }
    while (terms.back() == zero) {
       terms.pop_back();
    }
}
void polynomial1::bineryfread(string str)
{
    str += ".dat";
    ifstream bineryRfile(str, ios::out | ios::binary);
    if(!bineryRfile.is_open()) {
       throw "Cannot open file!";
    }
    string temp;
    size_t size;
    bineryRfile.read(reinterpret_cast<char *>(&size), sizeof(size));
    temp.resize(size);
    bineryRfile.read(&temp[0], size);
    *this << temp;
}



void polynomial1::bineryfwrite(string str)
{
    str += ".dat";
    ofstream bineryWfile(str, ios::out | ios::binary );
    if(!bineryWfile) {
       throw "Cannot open file!";
    }
    string temp;
    string * x;
    *this >> temp;
    size_t size = temp.size();
    bineryWfile.write(reinterpret_cast<const char *>(&size),sizeof (size));
    bineryWfile.write(&temp[0],size);

}


void polynomial1::saveFile(ofstream &of)
{
    compile();
    order();
    if(of.is_open())
    {
        string temp;
        for(int i = 0; i < terms.size(); i++)
        {
            terms.at(i) >> temp;
        }
        of << temp;
    }
    else
    {
        throw "fils isn't open!";
    }
}

    int polynomial1::degree()
    {
        compile();
        int temp;
        for (int i = 0;i < terms.size();i++)
        {
            if(terms.at(i).exponentget() != 0)
            {
                temp += terms.at(i).exponentget();
            }
        }
        return temp;
    }

    polynomial1 &polynomial1::operator*=(const polynomial1 &p )
    {
        *this = (*this * p);
        return *this;
    }
    polynomial1 &polynomial1::operator*=(const term &t )
    {
        *this = (*this * t);
        return *this;
    }
    polynomial1 &polynomial1::operator*=(const float &f )
    {
        *this = (*this * f);
        return *this;
    }

    polynomial1 &polynomial1::operator/=(const polynomial1 &p )
    {
        *this = (*this / p);
        return *this;
    }
    polynomial1 &polynomial1::operator/=(const term &t )
    {
        *this = (*this / t);
        return *this;
    }
    polynomial1 &polynomial1::operator/=(const float &f )
    {
        *this = (*this / f);
        return *this;
    }






















void swap(term &t1,term &t2) {
    term temp = t1;
    t1 = t2;
    t2 = temp;
}
