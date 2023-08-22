
#ifndef SDDS_ACCOUNT_H
#define SDDS_ACCOUNT_H
#include "Bank.h"


namespace sdds
{

	const int MAXDAYS = 30;
	const double InterestRate = 0.285;
	const int NumberOfDaysInAYear = 365;


	class Account
	{
	private:
		int m_account_number;
		double m_balance;
		int m_daysSinceLastPayment;
		
		double returnIntrest() const;
	public:
		void configure(int m_account_namber, double m_balance, int m_daysSinceLastPayment);
		bool isAccountEmpty() const;
		bool hasIntrest() const;
		double display() const;
	};

}



#endif