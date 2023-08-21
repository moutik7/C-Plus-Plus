//Name: Moutikkumar Patel
//Student id:147298202
//Email: mgpatel12@myseneca.ca
//section: 244NAA

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshopsand assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdio>

#include "drink.h"
#include "util.h"
using namespace std;

namespace sdds
{
    const int MAXDRINKS = 5;

    Drink machine[MAXDRINKS];

    FILE* fptr = NULL;

    void loadDrinks(struct Drink* machine)
    {
      
        for(int i=0;i<MAXDRINKS;i++)
        {
            fscanf(fptr, "%s %d %lf %d", machine[i].name, &machine[i].volume, &machine[i].price, &machine[i].quantity);
        }
        
    }

    
    void loadDrinksFromFile(const char* filename)
    {

        fptr = fopen(filename, "r");
        if (fptr != NULL)
        {
            loadDrinks(machine);
        }
        else
        {
            printf("Failed to open file\n");
        }
        fclose(fptr);
    }


    void drinkMenu()
    {
        cout << "-----------Available Drinks-----------" << endl;
        cout << left << setw(10) << "Drink" << setw(10) << "Volume";
        cout << setw(10) << "Price" << setw(10) << "Quantity" << endl;
        for (int i = 0; i < MAXDRINKS; ++i)
        {
            cout << i + 1 << ".";
            displayDrink(&machine[i]);
        }
    }

    void displayDrink(const Drink* drink)
    {
        cout << left << setw(10) << drink->name << setw(10) << drink->volume
            << setw(10) << drink->price << setw(10) << drink->quantity << endl;
    }

    int chooseDrink()
    {
        bool done = false;
        int sel = 0;
        cout << "Select a drink from the menu (1-" << MAXDRINKS << "): ";
        do
        {
            cin >> sel;
            clearBuffer();
            if (sel >= 1 && sel <= MAXDRINKS)
            {
                if (updateDrink(sel) == true)
                    done = true;
                else
                    cout << "Out of stock for that drink, try again: ";
            }
            else
                cout << "Selection was was invalid try again: ";
        } while (!done);
        return sel;
    }

    bool updateDrink(int sel)
    {
        bool res = false;
        if (machine[sel - 1].quantity > 0)
        {
            machine[sel - 1].quantity--;
            res = true;
        }
        return res;
    }

   
        

}