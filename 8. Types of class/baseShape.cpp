

#define _CRT_SECURE_NO_WARNINGS 
#include "baseShape.h"
namespace sdds
{

	std::ostream& operator<<(std::ostream& os, const baseShape& s)
	{
		s.drawShape(os);
		return os;
	}

	std::istream& operator>>(std::istream& is, baseShape& s)
	{
		s.readShape(is);
		return is;
	}
}