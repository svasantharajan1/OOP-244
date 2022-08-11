/*
*****************************************************************************

Full Name  : Vasantharajan Sharmilann
FileName: SavingsAccount.h
Email      : svasantharajan1@myseneca.ca
Date of completion    : 23 July 2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SDDS_SAVINGSACCOUNT_H
#define SDDS_SAVINGSACCOUNT_H
#include "Account.h"
namespace sdds {
	class SavingsAccount :public Account {
		double iRate;
	public:
		SavingsAccount(double balance, double interestRate);
		void monthEnd();
		void display(std::ostream&) const;
	};
}
#endif // !SDDS_SAVINGSACCOUNT_H