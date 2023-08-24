

#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
#include <iostream>

namespace sdds
{
    const int NoOfBookCases = 132;
    const int NoOfShelves = 7;
    const int MaxTitleLen = 40;
    const int MaxAuthorLen = 25;
    class Book
    {
        char* m_BookTitle{}; // sets m_name to nullptr before any constructor invocation 
        char* m_AuthorName{};
        int m_BookcaseNumber;
        int m_ShelfNumber;
        bool validPhone(const  char* BookTitle, const char* AuthorName, int BookcaseNumbe, int ShelfNumber)const;
        void setEmpty();
        void allocateAndCopy(const char* BookTitle, const char* AuthorName);
        void extractChar(std::istream& istr, char ch)const;
        void set(const char* BookTitle = nullptr, const char* AuthorName = nullptr, int BookcaseNumbe = 0, int ShelfNumber = 0);
    public:
        Book(const char* BookTitle = nullptr, const char* AuthorName = nullptr, int BookcaseNumbe = 0, int ShelfNumber = 0);
        Book(const Book& cnt);
        Book& operator=(const Book& cnt);
        ~Book();
        operator bool() const;
        std::ostream& write(std::ostream& ostr, bool onScreen = true)const;
        std::istream& read(std::istream& istr);
    };
    std::ostream& operator<<(std::ostream& ostr, const Book& cnt);
    std::istream& operator>>(std::istream& istr, Book& cnt);
}
#endif // !SDDS_CONTACT_H