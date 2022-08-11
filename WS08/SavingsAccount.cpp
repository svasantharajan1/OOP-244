/*
*****************************************************************************

Full Name  : Vasantharajan Sharmilann
FileName: SavingsAccount.cpp
Email      : svasantharajan1@myseneca.ca
Date of completion    : 23 July 2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#include <iomanip>
#include "SavingsAccount.h"
using namespace std;
namespace sdds {
	SavingsAccount::SavingsAccount(double balance, double interestRate) : Account(balance)
	{
		if (interestRate > 0) {
			this->iRate = interestRate;
		}
		else {
			this->iRate = 0.0;
		}
	}

	void SavingsAccount::monthEnd()
	{
		double interest = Account::balance() * iRate;
		Account::credit(interest);
	}

	void SavingsAccount::display(std::ostream& os) const
	{
		os << setprecision(2);
		os << fixed;
		os << "Account type: Savings" << endl;
		os << "Balance: $" << Account::balance() << endl;
		os << "Interest Rate (%): " << iRate * 100 << endl;
	}
}