//Name: Moutikkumar Patel
//Student id:147298202
//Email: mgpatel12@myseneca.ca
//section: 244NAA


#include <iostream>

#include "util.h"
using namespace std;

namespace sdds
{

    bool confirm()
    {
        char choice = cin.get();
        clearBuffer();
        return choice == 'Y';
    }

    void clearBuffer()
    {
        while (cin.get() != '\n');
    }
}