//Name:Moutikkumar Patel
//Seneca ID:147298202
//Email: mgpatel12@myseneca.ca


#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <cstring>


#include "Fighter.h"

using namespace std;

namespace sdds
{
	void fighter(char* name)
	{
		cout << "Enter Fighter Name: ";
		cin >> name;

	}

	void fighter(int& power)
	{
		cout << "Enter Fighter Power: ";
		cin >> power;
	}
	void display(const Fighter& myFighter)
	{
		cout << "Name: " << myFighter.name;
		cout << ", Power: " << myFighter.power<<endl;


	}
	void display(const Competition& mycompetition)
	{
		for (int i = 0;i < mycompetition.numfighters;i++)
		{
			display(mycompetition.fighters[i]);

		}
	}
	void addFighter(Competition& myCompetition)
	{
		int i;
		Fighter* temp = new Fighter[myCompetition.numfighters + 1];
		for ( i = 0; i < myCompetition.numfighters ; i++)
		{
			temp[i] = myCompetition.fighters[i];
		}
		cout << "Information of the new fighter:" << endl;
		fighter(temp[myCompetition.numfighters].name);
		fighter(temp[myCompetition.numfighters].power);


		delete[] myCompetition.fighters;
		myCompetition.fighters = temp;
		myCompetition.numfighters++;

		
	}
	void removeFighter(Competition& mycompetition, const Fighter& loserFighter)
	{
		Fighter* temp = new Fighter[mycompetition.numfighters - 1];
		int i = 0,j=0;
		int foundIndex = findFighter(mycompetition, loserFighter);
		
		
			for ( i = 0; i < mycompetition.numfighters; i++)
			{
				if  (i != foundIndex)
				{
					temp[j] = mycompetition.fighters[i];
					j++;
				}
			}
			/*while (i<mycompetition.numfighters)
			{
				if (i != foundIndex)
				{
					temp[i++] = mycompetition.fighters[i];
					
				}
				i++;
			}*/
			mycompetition.numfighters--;
			delete[] mycompetition.fighters;
			mycompetition.fighters = temp;
		
	}
	
	int findFighter(const Competition& mycompetition, const Fighter& theFighter)
	{
		int found = -1,i;
		for (i=0;i<mycompetition.numfighters && found==-1;i++)
		{
			if (!(strcmp(mycompetition.fighters[i].name, theFighter.name)))
			{
				found = i;
			}
		}
		return found;
	}

	void fight(Competition& mycompetition, Fighter& f1, Fighter& f2)
	{
		cout << "    " << f1.name << " will fight " << f2.name << "..." << endl;
		cout << "    The winner => ";
		if (fight(f1, f2))
		{
			display(f1);
			removeFighter(mycompetition, f2);
		}
		else
		{
			display(f2);
			removeFighter(mycompetition, f1);
		}
	}
	

bool fight(const Fighter& f1, const Fighter& f2)
{
	return f1.power > f2.power;

}
}