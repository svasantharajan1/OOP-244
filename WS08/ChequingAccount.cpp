/*
*****************************************************************************

Full Name  : Vasantharajan Sharmilann
FileName: ChequingAccount.cpp
Email      : svasantharajan1@myseneca.ca
Date of completion    : 23 July 2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#include <iomanip>
#include "ChequingAccount.h"
using namespace std;
namespace sdds {
    ChequingAccount::ChequingAccount(double balance, double transactionFee, double monthlyFee) : Account(balance)
    {
        if (transactionFee > 0) {
            this->transactionFee = transactionFee;
        }
        else this->transactionFee = 0.0;

        if (monthlyFee > 0) {
            this->monthlyFee = monthlyFee;
        }
        else this->monthlyFee = 0.0;
    }
    bool ChequingAccount::credit(double am)
    {
        bool ans = false;
        if (Account::credit(am)) {
            ans = Account::debit(transactionFee);
        }
        return ans;
    }
    bool ChequingAccount::debit(double am)
    {
        bool ans = false;
        if (Account::debit(am)) {
            ans = Account::debit(transactionFee);
        }
        return ans;
    }
    void ChequingAccount::monthEnd()
    {
        Account::debit(monthlyFee);
    }
    void ChequingAccount::display(ostream& out) const
    {
        out << setprecision(2);
        out << fixed;
        out << "Account type: Chequing" << endl;
        out << "Balance: $" << Account::balance() << endl;
        out << "Per Transaction Fee: " << transactionFee << endl;
        out << "Monthly Fee: " << monthlyFee << endl;
    }
}