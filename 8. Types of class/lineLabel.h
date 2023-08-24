

#ifndef SDDS_LINE_H
#define SDDS_LINE_H
#include <iostream>
#include "labelShape.h"
namespace sdds
{
	class lineLabel : public labelShape
	{
		int m_length;
	public:
		lineLabel();
		lineLabel(const char* label, int length);
		void drawShape(std::ostream& os) const;
		void readShape(std::istream& is);
	};

};
#endif

