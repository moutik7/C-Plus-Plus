
#include<iostream>
#include"Contact.h"
#include "Utils.h"
using namespace std;

namespace sdds
{
	Contact::Contact()
	{
	}
	void Contact::set(const Contact& copyFrom)
	{
		delAlloCopy(m_address, copyFrom.m_address);
		delAlloCopy(m_city, copyFrom.m_city);
		strCpy(m_province, copyFrom.m_province);
		strCpy(m_postalCode, copyFrom.m_postalCode);
	}
	
	Contact::Contact(const Contact& copyFrom):Person(copyFrom)
	{
		set(copyFrom);

	}
	Contact& Contact::operator=(const Contact& RightOperand)
	{
		Person::operator=(RightOperand);
		set(RightOperand);
		return *this;

	}
	Contact:: ~Contact()
	{
		~*this;
	}
	std::istream& Contact::read(std::istream& istr)
	{
		~*this;
	Person::read(istr);
		m_address = dynRead(istr, ',');
		m_city= dynRead(istr, ',');
		istr.getline(m_province, 3, ',');
		istr.getline(m_postalCode, 7, '\n');
		if (istr.fail()) ~*this;
		return istr;
	 }
	std::ostream& Contact::write(std::ostream& ostr)const
	{
		if (*this)
		{
			Person::write(ostr);
			ostr << endl << m_address << endl;
			ostr << m_city << " " << m_province << endl;

			int i;
			for (i = 0; i < 3; i++) ostr << m_postalCode[i];
			ostr << " ";
			for (i = 3; i < 6; i++) ostr << m_postalCode[i];
			ostr << endl;

		}
		return ostr;
	 }


	void Contact::operator~()
	{
		Person::operator~();
		delete[] m_address;
		delete[] m_city;
		m_address = m_city = nullptr;
	 }


	Contact::operator bool()const
	{
		return Person::operator bool() && m_address && m_address[0] && m_city && m_city[0];
	}
}