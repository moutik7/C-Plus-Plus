

#ifndef SDDS_LABELEDSHAPE_H
#define SDDS_LABELEDSHAPE_H
#include "baseShape.h"
namespace sdds
{
	class labelShape : public baseShape
	{
		char* m_label = nullptr;
	protected:
		const char* label() const;
	public:
		labelShape();
		labelShape(const char* label);
		~labelShape();
		labelShape(const labelShape&) = delete;
		void operator=(const labelShape&) = delete;
		void readShape(std::istream& is);

	};
};
#endif

