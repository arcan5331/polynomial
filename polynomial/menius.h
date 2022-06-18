#ifndef MENIUS_H
#define MENIUS_H

#endif // MENIUS_H
#include "polynomial1.h"
#include <iostream>
#include <windows.h>
#include <limits>
using namespace std;

void mainmenue(polynomial1 &p);
void saveToFile(polynomial1 &p);
polynomial1 readFromFile();

void changMain(int &n,polynomial1 &p);

void polynimialMeniu(polynomial1 &p);


void compare(polynomial1 p1,polynomial1 p2);
void saveBinery(polynomial1 &p);
polynomial1 readBinery();
void changop(int n,polynomial1 &p);










void saveToFile(polynomial1 &p)
{
    ofstream file;
    string name;
    cout << "\n\t  Enter file name: \n"
            "\n\t  (exmple: File Name 1)  \n\t  ";
    getline(cin,name);
    name += ".txt";
    file.open(name, ios::out);
    if (!file.is_open())
    {
        throw "\n\t cant open file";
    }
    else
    {
        p.saveFile(file);
    }
    file.close();
    cin.clear();
    polynimialMeniu(p);
}
polynomial1 readFromFile()
{
    cin.ignore();
    ifstream file;
    string name;
    cout << "\tEnter file name: \n"
            "\t(File Name)\n\t";
    getline(cin,name);
    name += ".txt";
    file.open(name, ios::out);
    polynomial1 temp;
    term t;
    string line;
    while (getline(file, line))
    {
        t << line;
        temp += t;
    }
    temp.compile();
    return temp;
}
void saveBinery(polynomial1 &p)
{
    cout << "\n\tEnter file name: ";
    string name;
    getline(cin,name);
    p.bineryfwrite(name);
}
polynomial1 readBinery()
{
    cin.ignore();
    cout << "\n\tEnter file name: ";
    string name;
    getline(cin,name);
    polynomial1 temp;
    try
    {   temp.bineryfread(name);}
    catch(const char *a)
    {
        cout << "\t"<< a << endl;
        polynomial1 none;
        Sleep(1000);
        polynimialMeniu(none);
    }
    return temp;
}




void mainmenue(polynomial1 &p)
{
    system("cls");
    int input = 0;

    cout << endl;
    cout << "\tMain Menu\n" <<endl;
    cout << "\t1- New Polynimial\n" ;
    cout << "\t2- Load from text file\n" ;
    cout << "\t3- Load from binery file\n" ;
    cout << "\t4- Quit" << endl;
    while (( cout << "\tEnter a number ")
           && (!( cin >> input) || input < 1 || input > 4)) {
       cout << "\tThat's not a number between 1 and 4. \n";
       cin.clear();
       cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    changMain(input,p);
}
void changMain(int &n,polynomial1 &p)
{
    switch (n) {
    case 1:
        polynimialMeniu(p);
        break;
    case 2:
        p = readFromFile();
        polynimialMeniu(p);
        break;
    case 3:
        p = readBinery();
        polynimialMeniu(p);
        break;
    case 4:
        cout << "\n\t Are u sure? (Y/N)\n\t";
        char sure;
        cin.get(sure);
        cin.ignore(256,'\n');
        if(sure == 'Y' || sure == 'y')
        {
            abort();
        }
        else
        {
            mainmenue(p);
        }
        break;
    }
}





void polynimialMeniu(polynomial1 &p)
{
    p.compile();
    cin.clear();
    string str;
    int input;
    bool isdig = true;
    system("cls");
    cout << "\n\n\tPolynomial Meniu\n";
    if(p.terms_num() == 0)
    {
        cout << "\tCurrent Polynomial = 0\n";
    }
    else
    {
        cout << "\tCurrent Polynomial = "<< p <<"\n";
    }
    cout << "\t  1- Add\n" <<
            "\t  2- Subtract\n" <<
            "\t  3- Multiply\n" <<
            "\t  4- Derivarive\n" <<
            "\t  5- Find degree\n" <<
            "\t  6- Fine Value for specefic x\n" <<
            "\t  7- campare\n" <<
            "\t  8- Save to a text file\n" <<
            "\t  9- Save to a binary file\n" <<
            "\t 10- Back to Main Menu\n\t";
    while (( cout << " Enter a number ")
           && (!( cin >> input) || input < 1 || input > 10)) {
       cout << "\tThat's not a number between 1 and 10. \n";
       cin.clear();
       cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(256,'\n');
    cin.clear();
    changop(input,p);
}
void changop(int n,polynomial1 &p)
{
    system("cls");
    polynomial1 temp;
    polynomial1 dont;
    switch (n) {
    case 1:
        cout << "\n\t  Enter what u want to Add: \n\t  ";
        do
        {
            try {
                cin >> temp;
                break;
            }
            catch (int a)
            {
                cout << "\n\t Bad Entry. Enter a POLYNoMIAL : ";
            }
        } while(1);
        try
        {
        p += temp;
        }
        catch(int a)
        {
            cout << "Error number: " << a;
            polynimialMeniu(p);
        }

        polynimialMeniu(p);
        break;
    case 2:
        cout << "\n\t  Enter what u want to Subtract: \n\t  ";
        do
        {
            try {
                cin >> temp;
                break;
            }
            catch (int a)
            {
                cout << "\n\t Bad Entry. Enter a POLYNoMIAL : ";
            }
        } while(1);

        try
        {
        p -= temp;
        }
        catch(int a)
        {
            cout << "Error number: " << a;
            polynimialMeniu(p);
        }

        polynimialMeniu(p);
        break;
    case 3:
        cout << "\n\t  Enter what u want to Multiply: \n\t  ";
        do
        {
            try {
                cin >> temp;
                break;
            }
            catch (int a)
            {
                cout << "\n\t Bad Entry. Enter a POLYNoMIAL : ";
            }
        } while(1);

        try
        {
        p *= temp;

        }
        catch(int a)
        {
            cout << "Error number: " << a;
            polynimialMeniu(p);
        }
        polynimialMeniu(p);
        break;
    case 4:
        cout << "\n\t  Enter what u want to Subtract: \n\t  ";
        do
        {
            try {
                cin >> temp;
                break;
            }
            catch (int a)
            {
                cout << "\n\t Bad Entry. Enter a POLYNoMIAL : ";
            }
        } while(1);

        try
        {
        p.compile();
        p /= temp;

        }
        catch(int a)
        {
            cout << "Error number: " << a;
            polynimialMeniu(p);
        }
        polynimialMeniu(p);
        break;
    case 5:
        cout << "\n\t  Degree is: " << p.degree();
        cout << "\n\n\t  Enter to continue.";
        cin.ignore(256,'\n');
        polynimialMeniu(p);

        break;
    case 6:
        float x;
        while (( cout << "\tEnter a number ")
               && !( cin >> x)) {
           cout << "\n\tThat's not a number. \n";
           cin.clear();
           cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cout << "\n\t polynomial " << p <<" for x = " << x << " is: " << p(x);
        cin.ignore(256,'\n');
        cin.ignore(256,'\n');
        polynimialMeniu(p);
        break;
    case 7:
        cout << "\n\t  Enter Second Polynomiyal : \n\t  ";
        cin >> temp;
        compare(p,temp);
        polynimialMeniu(p);
        break;
    case 8:
        saveToFile(p);
        polynimialMeniu(p);
        break;
    case 9:
        saveBinery(p);
        polynimialMeniu(p);
        break;
    case 10:
        polynomial1 te;
        p = te;
        mainmenue(p);
        break;
    }
}

void compare(polynomial1 p1,polynomial1 p2)
{
    p1.compile();
    p2.compile();
    cout << "\n\t  Currtent Polynomial = " << p1 << endl;
    cout << "\t  Other Polynomial = " << p2 << endl;
    cout << "\n\t  Comparing Currtent Polynomial and Other Polynomial\n";
    string big = "False",bigequl = "False",smal = "False",smalequl = "False",equl = "False";
    if(p1 > p2)
    {
        big = "True";
    }
    if(p1 >= p2)
    {
        bigequl = "True";
    }
    if(p1 < p2)
    {
        smal = "True";
    }
    if(p1 <= p2)
    {
        smalequl = "True";
    }
    if(p1 == p2)
    {
        equl = "True";
    }
    cout << "\t Currtent Polynomial > Other Polynomial: " << big << endl;
    cout << "\t Currtent Polynomial >= Other Polynomial: " << bigequl << endl;
    cout << "\t Currtent Polynomial < Other Polynomial: " << smal << endl;
    cout << "\t Currtent Polynomial <= Other Polynomial: " << smalequl << endl;
    cout << "\t Currtent Polynomial == Other Polynomial: " << equl << endl;
    cout << "\t Enter ant Char to Countineu." << endl <<"\t ";
    char a;
    cin.get(a);
    cin.ignore(256,'\n');
    system("cls");
}
