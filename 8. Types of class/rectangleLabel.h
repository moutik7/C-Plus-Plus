

#ifndef SDDS_RECTANGLE_H
#define SDDS_RECTANGLE_H
#include "labelShape.h"
namespace sdds
{
	class rectangleLabel : public labelShape
	{
		int m_width, m_spaces;
	public:
		rectangleLabel();
		rectangleLabel(const char* label, int width, int spaces);
		void drawShape(std::ostream& os) const;
		void readShape(std::istream& is);
	};

}
#endif
