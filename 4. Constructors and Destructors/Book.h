

#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
// imports
#include <iostream>
#include <cstring>
#include "Chapter.h"
using namespace sdds;

namespace sdds
{
    class Book
    {
        const char* title;
        int numOfChapters;
        Chapter* chapters;
    public:
        ~Book();
        Book(const char*, int, Chapter*);
        bool isEmpty() const;
        Book& addChapter(const char*, int);
        void display() const;
        bool isValid() const;
    };
};

#endif