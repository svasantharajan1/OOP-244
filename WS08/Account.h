/*
*****************************************************************************

Full Name  : Vasantharajan Sharmilann
FileName: Account.h
Email      : svasantharajan1@myseneca.ca
Date of completion    : 23 July 2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_ACCOUNT_H
#define SDDS_ACCOUNT_H
#include "iAccount.h"
namespace sdds {
	class Account : public iAccount {
		double ebalance;
	public:
		Account(double balance);
		bool credit(double am);
		bool debit(double am);
	protected:
		double balance() const;
	};
}
#endif // !SDDS_ACCOUNT_H