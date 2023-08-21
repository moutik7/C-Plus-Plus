//Name: Moutikkumar Patel
//Student id:147298202
//Email: mgpatel12@myseneca.ca
//section: 244NAA


#ifndef SDDS_drink_H_
#define SDDS_drink_H_

using namespace std;


namespace sdds
{

    struct Drink
    {
        char name[10];
        int volume;
        double price;
        int quantity;
    };
    void loadDrinks(struct Drink* machine);
    
    void drinkMenu();
    void displayDrink(const Drink* drink);
    int chooseDrink();
    bool updateDrink(int sel);
    void loadDrinksFromFile(const char* filename);



}




#endif 