#ifndef SDDS_Dumper_H
#define SDDS_Dumper_H
#include <iostream>
#include "VehicleBasic.h"

namespace sdds
{
	class Dumper : public VehicleBasic
	{
		double m_cargo;
		double m_capacity;

	public:
		Dumper(const char* plate, int year, double capacity, const char* address);


		bool unloadCargo();
		bool loaddCargo(double cargo);

		std::istream& read(std::istream& in);
		std::ostream& write(std::ostream& out) const;
	};

	std::istream& operator>>(std::istream& in, Dumper& c);
	std::ostream& operator<<(std::ostream& out, const Dumper& c);
}
#endif