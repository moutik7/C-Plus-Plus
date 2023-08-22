
#ifndef SDDS_BANK_H
#define SDDS_BANK_H
#include "Account.h"

namespace sdds
{
	class Bank
	{
		char m_name[31];
		Account* m_accounts;
		int m_sizeOfAccountsArray;
		int m_addedAccounts;
		
		bool isEmpty()const;
		void header(const char* title)const;
	public:
		void  initialize(const  char* bank_name, int noOfAccounts);
		bool  addAccount(int account_number, double balance, int daysSinceLastPayment);
		void  display(bool intrestOnly = false) const;
		void clear();

	};



}



#endif

