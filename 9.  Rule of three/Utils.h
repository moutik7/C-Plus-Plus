
#ifndef SDDS_UTILS_H__
#define SDDS_UTILS_H__
#include <iostream>
#include <fstream>
namespace sdds {
   int strLen(const char* str);
   void strCpy(char* des, const char* src);
   void strCat(char* des, const char* src);
   void delAlloCopy(char*& des, const char* src);
   char* dynRead(std::istream& istr, char delimeter = '\n');
}
#endif // !
