/*
*****************************************************************************

Full Name  : Vasantharajan Sharmilann
FileName: ChequingAccount.h
Email      : svasantharajan1@myseneca.ca
Date of completion    : 23 July 2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_CHEQUINGACCOUNT_H
#define SDDS_CHEQUINGACCOUNT_H
#include "Account.h"
namespace sdds {
	class ChequingAccount : public Account {
		double transactionFee;
		double monthlyFee;
	public:
		ChequingAccount(double, double, double);
		bool credit(double);
		bool debit(double);
		void monthEnd();
		void display(std::ostream&) const;
	};
}

#endif // !SDDS_CHEQUINGACCOUNT_H