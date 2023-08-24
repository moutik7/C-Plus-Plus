
#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Book.h"
#include <iomanip>
#include <sstream>
using namespace std;
namespace sdds
{

    bool Book::validPhone(const  char* BookTitle, const char* AuthorName, int BookcaseNumbe, int ShelfNumber)const
    {
        return AuthorName != nullptr && AuthorName[0] != '\0' && BookTitle != nullptr && BookTitle[0] != '\0' && strlen(AuthorName) <= MaxAuthorLen && strlen(BookTitle) <= MaxTitleLen && BookcaseNumbe >= 1 && BookcaseNumbe <= NoOfBookCases && ShelfNumber <= NoOfShelves && ShelfNumber >= 1;
    }
    void Book::setEmpty()
    {
        m_BookTitle = nullptr;
        m_AuthorName = nullptr;
    }
    void Book::allocateAndCopy(const char* BookTitle, const char* AuthorName)
    {
        delete[] m_BookTitle;
        m_BookTitle = new char[strlen(BookTitle) + 1];
        strcpy(m_BookTitle, BookTitle);

        delete[] m_AuthorName;
        m_AuthorName = new char[strlen(AuthorName) + 1];
        strcpy(m_AuthorName, AuthorName);

    }
    void Book::extractChar(std::istream& istr, char ch)const
    {
        if (istr.peek() != ch)
        {
            istr.setstate(ios::failbit);
        }
        else
        {
            istr.get();
        }
    }

    void Book::set(const char* BookTitle, const char* AuthorName, int BookcaseNumber, int ShelfNumber)
    {

        if (validPhone(BookTitle, AuthorName, BookcaseNumber, ShelfNumber))
        {
            allocateAndCopy(BookTitle, AuthorName);
            m_BookcaseNumber = BookcaseNumber;
            m_ShelfNumber = ShelfNumber;
        }
        else
        {
            delete[] m_BookTitle;
            delete[] m_AuthorName;
            setEmpty();
        }
    }
    Book::Book(const char* BookTitle, const char* AuthorName, int BookcaseNumber, int ShelfNumber)
    {

        set(BookTitle, AuthorName, BookcaseNumber, ShelfNumber);
    }
    Book::Book(const Book& cnt)
    {

        if (cnt)
            set(cnt.m_BookTitle, cnt.m_AuthorName, cnt.m_BookcaseNumber, cnt.m_ShelfNumber);
    }
    Book& Book::operator=(const Book& cnt)
    {

        if (this != &cnt)
        {
            set(cnt.m_BookTitle, cnt.m_AuthorName, cnt.m_BookcaseNumber, cnt.m_ShelfNumber);
        }

        return *this;
    }
    Book::~Book()
    {
        delete[] m_BookTitle;
        delete[] m_AuthorName;
    }
    Book::operator bool() const
    {
        return m_BookTitle != nullptr && m_AuthorName != nullptr;
    }
    std::ostream& Book::write(std::ostream& ostr, bool onScreen) const
    {

        if (onScreen)
        {

            if (*this)
            {
                ostr.width(40);
                ostr.fill(' ');
                ostr.setf(ios::left);
                ostr << m_BookTitle;
                ostr.unsetf(ios::left);
                cout << "| ";

                ostr.width(25);
                ostr.fill(' ');
                ostr.setf(ios::left);
                ostr << m_AuthorName;
                ostr.unsetf(ios::left);
                cout << "| ";


                ostr << m_ShelfNumber << "/";
                ostr.width(3);
                ostr.fill('0');
                ostr << m_BookcaseNumber;


            }
            else
            {
                ostr << "Invalid Book Record ................... | ........................ | .....";
            }
        }
        else
        {
            if (*this)
            {
                ostr << m_BookTitle << "," << m_AuthorName << "," << m_ShelfNumber << "/" << m_BookcaseNumber;
            }
            else
            {
                ;
            }
        }
        return ostr;
    }
    std::istream& Book::read(std::istream& istr)
    {
        char BookTitle[100];
        char AuthorName[100];
        int BookcaseNumber = -1, ShelfNumber = -1;
        istr.get(BookTitle, 100, ',');
        extractChar(istr, ',');
        istr.get(AuthorName, 100, ',');
        extractChar(istr, ',');
        istr >> ShelfNumber;
        extractChar(istr, '/');
        istr >> BookcaseNumber;
        if (BookTitle[0] == '\n')
        {
            char BookTitle2[100];
            int j = 0;
            for (unsigned int i = 0; i < strlen(BookTitle); i++)
            {
                if (BookTitle[i] == '\n') continue;
                else BookTitle2[j++] = BookTitle[i];
            }
            BookTitle2[j] = '\0';
            strcpy(BookTitle, BookTitle2);
        }
        if (!istr.fail())
        {
            set(BookTitle, AuthorName, BookcaseNumber, ShelfNumber);

        }
        return istr;
    }
    std::ostream& operator<<(std::ostream& ostr, const Book& cnt)
    {
        cnt.write(ostr);
        return ostr;
    }
    std::istream& operator>>(std::istream& istr, Book& cnt)
    {
        return cnt.read(istr);
    }
}