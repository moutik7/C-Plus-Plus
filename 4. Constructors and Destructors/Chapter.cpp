
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

#include "Book.h"
#include "Chapter.h"
using namespace std;

namespace sdds
{


    
    
     Chapter ::   Chapter()
        {
            // create an invalid chapter
            this->isValid = false;
        }
     Chapter::Chapter(const char* chapter_name, int noOfPages)
        {
            // initially assume that everything is valid
            this->isValid = true;
            // check if chapter_name is valid
            int length = (chapter_name != nullptr ? strlen(chapter_name) : 0);
            if (length < 1 || length >= CHAPTER_NAME_LEN)       this->isValid = false;
            // check if noOfPages are correct
            if (noOfPages < 1 || noOfPages > 200)               this->isValid = false;
            // initialize the properties if valid
            if (this->isValid)
            {
                // copy the chapter_name
                strcpy(this->chapter_name, chapter_name);
                this->noOfPages = noOfPages;
            }
        }

        // returns true if the chapter is valid
        bool  Chapter::isValidChapter() const
        {
            return this->isValid;
        }

        // displays the details of a chapter
        void Chapter:: display() const
        {
            // check if chapter is valid
            if (isValid)
            {
                cout << left;
                cout.width(50);
                cout.fill('.');
                cout << this->chapter_name ;
                cout << right; 
                cout.width(4);
                cout.fill(' ');
                cout << this->noOfPages;
            }
            else
            {
                // display Invalid chapter
                cout << "Invalid Chapter";
            }
        }
    };