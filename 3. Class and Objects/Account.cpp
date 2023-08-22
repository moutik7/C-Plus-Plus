
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <cstring>
#include "Bank.h"
#include "Account.h"

using namespace std;

namespace sdds
{
	void Account:: configure(int accountNumber, double accountBalance, int daysSinceLastPayment) // this method is used for configuring the account where 
	{
		if (accountNumber > 0 && accountBalance > 0 && daysSinceLastPayment > 0)
		{     
			m_account_number = accountNumber;
			m_balance = accountBalance;
			m_daysSinceLastPayment = daysSinceLastPayment;
		}
		else
		{
			m_account_number = 1;
			m_balance = 1;
			m_daysSinceLastPayment = 1;       
		}
	}

	bool Account::isAccountEmpty() const // this method check if account empty or not
	{    
		bool invalid = false;
		if (m_account_number <= 0 && m_balance <= 0 && m_daysSinceLastPayment <= 0)
		{
			invalid = true;
		}
		return invalid;
	}

	

	bool Account::hasIntrest() const // this boolean method will return true if there is interest on account
	{           
		bool yesno = false;
		if (m_daysSinceLastPayment > MAXDAYS)
		{
			yesno = true;
		}
		return yesno;
	}

	double Account::display() const
	{           
		double in = 0;
		if (!isAccountEmpty())
		{
			cout.width(10);
			cout.fill(' ');
			cout << m_account_number;
			cout.unsetf(ios::left);
			cout.width(12);
			cout.fill(' ');
			cout.setf(ios::right);
			cout.precision(2);
			cout << m_balance;
			cout.unsetf(ios::right);
			cout << "  ";
			cout.width(4);
			cout.fill(' ');
			cout.setf(ios::left);
			cout << m_daysSinceLastPayment;
			cout.unsetf(ios::left);
			if (hasIntrest())
			{                      //if it has intrest ,display it
				in = returnIntrest();
				cout.width(8);
				cout.fill(' ');
				cout.setf(ios::right);
				cout.precision(2);
				cout << in;
			}
			cout.unsetf(ios::right);
			cout << endl;
		}
		return in;
	}

	double Account::returnIntrest() const // this method will return interest 
	{
		double intrest = 0;
		if (hasIntrest()) // here it is checked wherther it has ineterst if it has value will be send other wise 0 will be send.
		{                      
			intrest = m_daysSinceLastPayment * (InterestRate / NumberOfDaysInAYear) * m_balance;
		}
		return intrest;
	}
}