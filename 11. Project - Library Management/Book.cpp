

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<iomanip>
#include <string>
#include <cstring>

#include"Book.h"

using namespace std;

namespace sdds {
	Book::Book() : Publication() {
		m_authorname = nullptr;
	}

	void Book::set(const char* authorname) {
		if (m_authorname != nullptr)
			delete[] m_authorname;
		m_authorname = nullptr;

		if (authorname != nullptr && authorname[0] != '\0') {
			m_authorname = new char[strlen(authorname) + 1];

			strcpy(m_authorname, authorname);
		}
	}

	// RULE OF THREE
	Book::Book(const Book& bk) : Publication(bk) {
		if (bk.operator bool()) {
			this->set(bk.m_authorname);
		}
	}

	Book& Book::operator=(const Book& bk) {
		if (this != &bk) {
			Publication::operator=(bk);
			this->set(bk.m_authorname);
		}

		return (*this);
	}

	Book::~Book() {
		delete[] m_authorname;
	}

	char Book::type()const {
		return 'B';
	}

	std::ostream& Book::write(std::ostream& os) const {
		/*
	First, it will invoke the write of its Base class.
	If the incoming argument is a console IO object.
		writes a single space
		writes the author's name in SDDS_AUTHOR_WIDTH spaces. If the author's name is longer than the SDDS_AUTHOR_WIDTH value, it will cut it short and writes exactly SDDS_AUTHOR_WIDTH characters. Note that this should not modify the author's name.
		writes " |"
	If the incoming argument is not a console IO object
		writes a tab character '\t'
		writes the author's name
	returns the incoming ostream.
		*/

		Publication::write(os);
		if (m_authorname != nullptr && m_authorname[0] != '\0') {
			char temp[SDDS_AUTHOR_WIDTH + 1] = {};

			if (Publication::conIO(os)) {
				os << " ";

				if (strlen(m_authorname) > SDDS_AUTHOR_WIDTH) {

					for (int i = 0; i < SDDS_AUTHOR_WIDTH; i++) {
						temp[i] = m_authorname[i];
					}

					temp[SDDS_AUTHOR_WIDTH] = '\0';

					os << setw(SDDS_AUTHOR_WIDTH) << temp;
				}
				else {
					os << setw(SDDS_AUTHOR_WIDTH) << m_authorname;
				}

				os << " |";
			}
			else {
				os << '\t' << m_authorname;
			}
		}


		return os;
	}

	std::istream& Book::read(std::istream& istr) {
		/*
		Read the author name in local variables before setting the attribute to any value. (to make it easier lets assume the author's name can not be more than 256 characters)

	First, invoke the read of the Base class.
	Free the memory held for the author's name
	If the incoming argument is a console IO object
		ignore one character (skip the '\n')
		prompt "Author: "
		read the author's name
	If the incoming argument is not a console IO object
		ignore the tab character
		read the author's name

Then if the incoming istream object is not in a fail state, dynamically hold the author's name in the char pointer attribute of the book class.

At the end return the incoming istream object.
		*/

		Publication::read(istr);

		char* authorname = nullptr;
		authorname = new char[256];

		delete[] m_authorname;

		if (Publication::conIO(istr)) {
			istr.ignore(1, '\n');
			cout << "Author: ";
			istr.getline(authorname, 256, '\n');
		}
		else {
			istr.ignore(1, '\t');
			istr.get(authorname, 256, '\n');
		}

		if (authorname[0] == '\0')
			istr.setstate(ios::failbit);

		if (istr.good()) {
			m_authorname = new char[strlen(authorname) + 1];
			strcpy(m_authorname, authorname);
		}

		delete[] authorname;
		return istr;
	}

	void Book::set(int member_id) {
		Publication::set(member_id);
		Publication::resetDate();
	}

	Book::operator bool()const {
		return m_authorname != nullptr && m_authorname[0] != '\0'
			&& Publication::operator bool();
	}

	// HELPER
	ostream& operator<<(ostream& os, const Book& obj) {
		obj.write(os);
		return os;
	}

	istream& operator>>(istream& is, Book& obj) {
		obj.read(is);
		return is;
	}
}

