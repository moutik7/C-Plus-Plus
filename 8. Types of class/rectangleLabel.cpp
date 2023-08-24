


#define _CRT_SECURE_NO_WARNINGS 
#include <iomanip>
#include <cstring>
#include "rectangleLabel.h"
using namespace std;
namespace sdds
{
	rectangleLabel::rectangleLabel()
	{
		m_width = 0;
		m_spaces = 0;
	}


	rectangleLabel::rectangleLabel(const char* label, int width, int spaces) :labelShape(label)
	{
		m_width = width;
		m_spaces = spaces;
		if (width < int(strlen(label) + spaces + 2))
		{
			m_width = 0;
		}
	}

	void rectangleLabel::readShape(std::istream& is)
	{
		labelShape::readShape(is);
		is >> m_width;
		is.ignore();
		is >> m_spaces;
		is.ignore(1000, '\n');
	}

	void rectangleLabel::drawShape(std::ostream& os) const
	{
		if (m_width > 0 && m_spaces > 0)
		{
			os << '+';
			os.width(m_width - 2);
			os.fill('-');
			os << '-';
			os.fill(' ');
			os << '+' << endl;
			os << "|";
			os.width(m_spaces);
			os.fill(' ');
			os << ' ';
			os.width(m_width - m_spaces - 2);
			os.setf(ios::left);
			os << label() << "|" << endl;
			os << '+';
			os.width(m_width - 2);
			os.fill('-');
			os << '-';
			os.fill(' ');
			os << '+';

		}
	}
	
}