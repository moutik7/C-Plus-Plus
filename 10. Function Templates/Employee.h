#include <iostream>
#include "ReadWrite.h"

#ifndef SDDS_EMPLOYEE_H_
#define SDDS_EMPLOYEE_H_

namespace sdds 
{
   class Employee : public ReadWrite 
   {
      int m_empno;
      int m_office;
      char m_name[41];
      double m_salary;
   public:
      Employee();
      Employee(int stno, const char* name, double salary, int office);
      void set(int stno, const char* name, double salary, int office);
      std::ostream& display(std::ostream& os)const;
      std::istream& read(std::istream& is);
      bool operator==(int office)const;
   };
}
#endif // !SDDS_EMPLOYEE_H_