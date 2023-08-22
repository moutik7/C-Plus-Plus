
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Chapter.h"
#include "Book.h"

using namespace std;
using namespace sdds;


namespace sdds
{
   Book :: Book(const char* book_name, int noOfChapters, const Chapter* chapters)
    {
        // initially assume that everything is valid
        this->isValid = true;
        this->book_name = nullptr;
        this->chapters = nullptr;
        this->noOfChapters = 0;
        int length = (book_name != nullptr ? strlen(book_name) : 0);
        // check if book_name is valid
        if (length < 1)             this->isValid = false;
        if (noOfChapters < 1)       this->isValid = false;
        // check if all chapters are valid
        for (int i = 0; i < noOfChapters; i++)
            if (!chapters[i].isValidChapter())
                this->isValid = false;
        // check if valid information is provided to create book
        if (this->isValid)
        {
            // create a string on heap for book_name
            this->book_name = new char[length + 1];
            //copy the elements
            strcpy(this->book_name, book_name);
            // allocate memory for chapters
            this->chapters = new Chapter[noOfChapters];
            // create copies of chapters
            for (int i = 0; i < noOfChapters; i++)
                this->chapters[this->noOfChapters++] = chapters[i];
        }
    }

   bool Book::isEmpty() const
   {
       // check if book is empty or invalid
       return (isValid || this->noOfChapters == 0);
   }

   // adds a chapter to the book only if chapter is valid
   Book& Book::addChapter(const char* chapter_name, int noOfPages)
   {
       // create a new chapter
       Chapter chapter(chapter_name, noOfPages);
       // check if chapter is valid
       if (chapter.isValidChapter())
       {
           // add the chapter to list of chapters
           // create a new list of chapters
           Chapter* chapters = new Chapter[this->noOfChapters + 1];
           // copy chapters to new array
           for (int i = 0; i < this->noOfChapters; i++)
               chapters[i] = this->chapters[i];
           // add the last chapter
           chapters[this->noOfChapters++] = chapter;
           // delete the old list of chapters
           delete this->chapters;
           // update the list of chapters
           this->chapters = chapters;
       }
       // return a reference to this object
       // you may wish to create a new object and returns its reference
       return *this;
   }


   // displays the book
   void Book::display() const
   {
       // check if book is valid3
       if (!isValid)
       {
           cout << "Invalid Book object";
           cout << std::endl;
       }
       else
       {
           cout << "Book Name: " << this->book_name << std::endl;
           cout << "No of Chapters: " << this->noOfChapters << std::endl;
           cout.width(50);
           cout << std::left;
           cout.fill(' ');
           cout << "Chapter name" << " ";
           cout << "Pages";
           cout << std::endl;
           for (int i = 0; i < noOfChapters; i++)
           {
               // display the ith chapter
               chapters[i].display();
               cout << std::endl;
           }
       }
   }

   // destructor
   Book :: ~Book()
   {
       // delete memory allocaed to book_name and chapters
      
       if (chapters != nullptr)    delete chapters;
   }

};