//Name: Moutikkumar Patel
//Id: 147298202
//Email: mgpatel12@myseneca.ca
//subject: OOP244 NAA

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include<cstring>

using namespace std;

#include "Guests.h"
namespace sdds
{
    void read(char* str, int len)
    {
        if (cin.peek() == '\n') cin.ignore(); // checks the incomming character, if it is newline, it will remove it
        cin.getline(str, len);
    }
    void read(PhoneNumber& thePhoneNumber)
    {
        cout << "Enter Phone Number [area] [number]: ";
        cin >> thePhoneNumber.m_areacode;
        cin >> thePhoneNumber.m_number;
    }

    bool read(Guest& theGuest)
    {
        cout << "Guest name: ";
        cin.ignore();
        cin.getline(theGuest.m_name, 21);

        if (strlen(theGuest.m_name)!= 0)
        {
            read(theGuest.m_phno);
            return true;
        }
        
        else
        {
            return false;
        }
    }

    void print(const PhoneNumber& thePhoneNumber)
    {
        cout << "(" << thePhoneNumber.m_areacode << ") " << thePhoneNumber.m_number << endl;
    }
    void print(const Guest& theGuest)
    {
        cout << theGuest.m_name << ", ";
        print(theGuest.m_phno);
    }
    void print(const GuestList& theGuestList)
    {
        for (int i = 0; i < theGuestList.m_noOfGuests; i++)

        {
            cout << (i + 1) << "- ";
            print(theGuestList.m_gst[i]);
        }
    }

    void addGuest(GuestList& theGuestList, const Guest& aGuest)
    {
        // theGuestList.m_gst->m_name == aGuest.m_name;
        Guest* d_gst = theGuestList.m_gst;
        theGuestList.m_gst = new  Guest[theGuestList.m_noOfGuests + 1];
        
        for (int i = 0; i < theGuestList.m_noOfGuests; i++)
        {
            theGuestList.m_gst[i] = d_gst[i];
        }
        theGuestList.m_gst[theGuestList.m_noOfGuests] = aGuest;
        theGuestList.m_noOfGuests++;
        delete[] d_gst;
    }

    }





