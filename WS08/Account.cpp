/*
*****************************************************************************

Full Name  : Vasantharajan Sharmilann
FileName: Account.cpp
Email      : svasantharajan1@myseneca.ca
Date of completion    : 23 July 2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#include "Account.h"
namespace sdds {
	Account::Account(double balance)
	{
		if (balance > 0) {
			ebalance = balance;
		}
		else {
			ebalance = 0.0;
		}
	}
	bool Account::credit(double am)
	{
		bool ans = false;
		if (am > 0) {
			ebalance += am;
			ans = true;
		}
		return ans;
	}
	bool Account::debit(double am)
	{
		bool ans = false;
		if (am> 0) {
			ebalance -= am;
			ans = true;
		}
		return ans;
	}
	double Account::balance() const
	{
		return ebalance;
	}
}