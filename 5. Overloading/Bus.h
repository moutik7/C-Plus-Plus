


#ifndef SDDS_BUS_H
#define SDDS_BUS_H
#include <iostream>
using namespace std;

namespace sdds
{

    const double ticketPrice = 125.34;

    class Bus
    {

        int b_numSeats;
        int b_numPassengers;
        void setOutOfService();
        void drawBus(ostream& ostr, int seats, int psng) const;

    public:
        Bus(int numSeats = 20, int numPassengers = 0);

        ostream& display(std::ostream& ostr) const;
        istream& read(std::istream& istr);

        operator bool() const;
        operator int() const;
        operator double() const;

        bool operator--();
        bool operator--(int);
        bool operator++();
        bool operator++(int);

        Bus& operator=(int value);
        Bus& operator+=(int value);
        Bus& operator+=(Bus& right);

        bool operator==(const Bus& right) const;

    };

    int operator+(int left, const Bus& right);
    ostream& operator<<(ostream& ostr, const Bus& right);
    istream& operator>>(istream& istr, Bus& right);


}
#endif