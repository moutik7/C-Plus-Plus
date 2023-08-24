

#include <iostream>
#include "Bus.h"
using namespace std;

namespace sdds
{

    void Bus::setOutOfService()
    {
        b_numSeats = -1;
        b_numPassengers = -1;
    }

    void Bus::drawBus(ostream& ostr, int seats, int psng) const
    {
        int i, p;
        ostr.fill('_');
        ostr.width((seats / 2) * 3 + 4);
        ostr << "_";
        ostr << endl << "| ";
        for (i = 0, p = -1; i < (seats / 2); i++, ostr << "[" << ((p += 2) < psng ? '2' : ((p == psng) ? '1' : ' ')) << "]");
        ostr << "|_\\_" << endl;
        ostr << "| ";
        ostr.fill(' ');
        ostr.width(((seats / 2) * 3 - 14) / 2);
        ostr << " " << "Seneca College";
        ostr.width(((seats / 2) * 3 - 14) / 2 + (seats % 4 != 0));
        ostr << " " << "    )" << endl;
        ostr << "`---OO";
        ostr.fill('-');
        ostr.width((seats / 2) * 3 - 5);
        ostr << "-" << "O---'" << endl;
    }


    Bus::Bus(int numSeats, int numPassengers)
    {
        if ((numSeats % 2 == 0) && numSeats >= 10 && numSeats <= 40 && numPassengers >= 0 && numPassengers <= numSeats)
        {
            b_numSeats = numSeats;
            b_numPassengers = numPassengers;
        }
        else
        {
            setOutOfService();
        }
    }

    ostream& Bus::display(std::ostream& ostr) const
    {
        if (*this)
        {
            drawBus(ostr, b_numSeats, b_numPassengers);
            cout << "Total Fare Price: ";
            cout.setf(ios::fixed);
            cout.setf(ios::right);
            cout.precision(2);
            cout << b_numPassengers * ticketPrice;
            cout.unsetf(ios::right);
            cout << endl;
        }
        else
        {
            ostr << "Out of service!" << endl;
        }
        return ostr;
    }

    istream& Bus::read(std::istream& istr)
    {
        istr >> b_numSeats;
        istr.ignore();
        istr >> b_numPassengers;
        if (!((b_numSeats % 2 == 0) && b_numSeats >= 10 && b_numSeats <= 40 && b_numPassengers >= 0 && b_numPassengers <= b_numSeats))
        {
            setOutOfService();
        }
        return istr;
    }


    Bus::operator bool() const
    {
        return b_numSeats > 0;
    }

    Bus::operator int() const
    {
        if (*this)
            return b_numPassengers;
        else
            return -1;
    }

    Bus::operator double() const
    {
        if (*this)
            return b_numPassengers * ticketPrice;
        else
            return -1.0;
    }


    bool Bus::operator--()
    {
        bool res = false;
        if (*this && b_numPassengers > 0)
        {
            b_numPassengers--;
            res = true;
        }
        return res;
    }

    bool Bus::operator--(int)
    {
        return operator--();
    }

    bool Bus::operator++()
    {
        bool res = false;
        if (*this && b_numPassengers < b_numSeats)
        {
            b_numPassengers++;
            res = true;
        }
        return res;
    }

    bool Bus::operator++(int)
    {
        return operator++();
    }


    Bus& Bus::operator=(int value)
    {
        b_numPassengers = value;
        if (b_numPassengers > b_numSeats) setOutOfService();
        return *this;
    }

    Bus& Bus::operator+=(int value)
    {
        if (*this) b_numPassengers += value;
        if (b_numPassengers > b_numSeats) setOutOfService();
        return *this;
    }

    Bus& Bus::operator+=(Bus& right)
    {
        if (*this && right.b_numSeats > 0)
        {
            b_numPassengers += right.b_numPassengers;
            if (b_numPassengers > b_numSeats)
            {
                right.b_numPassengers = b_numPassengers - b_numSeats;
                b_numPassengers = b_numSeats;
            }
            else
                right.b_numPassengers = 0;
        }
        return *this;
    }


    bool Bus::operator==(const Bus& right) const
    {
        bool res = false;
        if (*this && right.b_numSeats > 0 && b_numPassengers == right.b_numPassengers)
            res = true;
        return res;
    }



    int operator+(int left, const Bus& right)
    {
        if (right) left += int(right);
        return left;
    }

    ostream& operator<<(ostream& ostr, const Bus& right)
    {
        return right.display(ostr);
    }

    istream& operator>>(istream& istr, Bus& right)
    {
        return right.read(istr);
    }

}