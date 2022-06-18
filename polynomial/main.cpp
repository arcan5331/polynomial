#include <windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include "polynomial1.cpp"
#include "term.cpp"
#include "menius.h"




using namespace std;



int main() {


    do
    {
        try {
            polynomial1 poly;
            mainmenue(poly);
        }
        catch (const char *a)
        {
            cout << "\n\t" << a << "\n";
        }
    } while(1);
}


