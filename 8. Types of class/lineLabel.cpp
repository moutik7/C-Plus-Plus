

#define _CRT_SECURE_NO_WARNINGS 
#include <iomanip>
#include "lineLabel.h"
using namespace std;
namespace sdds
{
	lineLabel::lineLabel()
	{
		m_length = 0;
	}

	lineLabel::lineLabel(const char* label, int length) :labelShape(label)
	{
		m_length = length;
	}

	void lineLabel::readShape(std::istream& is)
	{
		labelShape::readShape(is);
		is >> m_length;
		is.ignore(1000, '\n');
	}
	void lineLabel::drawShape(std::ostream& os) const
	{
		if (m_length > 0 && label())
		{
			os << label() << endl;
			os << setw(m_length) << setfill('=') << '=';
			os << setfill(' ');
		}
	}

	
}