

#ifndef SDDS_CHAPTER_H
#define SDDS_CHAPTER_H

#include <iostream>
#include <cstring>

namespace sdds
{
   
#define CHAPTER_NAME_LEN 51


   class Chapter
    {
    private:
        char chapter_name[CHAPTER_NAME_LEN];
        int noOfPages;
        bool isValid;

    public:
        Chapter();
        Chapter(const char* chapter_name, int noOfPages);
        bool isValidChapter() const;
        void display() const;
    };
};

#endif