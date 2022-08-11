/*
Student Name: Vasantharajan Sharmilann
SID: 142642180
Milestone 5
File: Date.cpp

All the code done in this milestone is done purely by me, as i have only used resouces from previous lecture and notes.


*/

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include<ctime>
#include "Utils.h"
#include "Date.h"
using namespace std;
namespace sdds {


	bool sdds_test = false;
	int sdds_year = 2022;
	int sdds_mon = 8;
	int sdds_day = 7;

	bool Date::validate()
	{
		errorCode(NO_ERROR);
		if (D_year < MIN_YEAR || D_year > D_currentYear + 1)
		{
			errorCode(YEAR_ERROR);
		}
		else if (D_month < 1 || D_month > 12)
		{
			errorCode(MON_ERROR);
		}
		else if (D_day < 1 || D_day > dayLeft())
		{
			errorCode(DAY_ERROR);
		}
		
		return !error();
	}
	int Date::dayLeft() const
	{
		int dd[] = { 31,28,31,30,31,30,31,31,30,31,31,31,-1 };
		int month = D_month >= 1 && D_month <= 12 ? D_month : 13;
		month--;
		return dd[month] + int((month == 1) * ((D_year % 4 == 0) & (D_year % 100 != 0)) || (D_year % 400 == 0));
		return 0;
	}
	int Date::systemYear() const
	{
		int yy = sdds_year;
		if (sdds_test)
		{
			time_t t = time(NULL);
			tm local = *localtime(&t);
			yy = local.tm_year + 1900;
		}
		return yy;
		return 0;
	}
	void Date::today()
	{
		if (sdds_test)
		{
			D_year = sdds_year;
			D_month = sdds_mon;
			D_day = sdds_day;


		}
		else
		{
			time_t t = time(NULL);
			tm local = *localtime(&t);
			D_year = local.tm_year + 1900;
			D_month = local.tm_mon + 1;
			D_day = local.tm_mday;
		}
		errorCode(NO_ERROR);
	}

	int Date::startDay() const
	{
		int startYear = D_year;
		int startMonth = D_month;
		if (startMonth < 3)
		{
			startYear--;
			startMonth += 12;
		}

		return 365 * startYear + startYear / 4 - startYear / 100 + startYear / 400 + (153 * startMonth - 457) / 5 + D_day - 306;;
	}

	Date::Date() :D_currentYear(systemYear())
	{
		today();
	}

	Date::Date(int y, int m, int d)
	{
		D_year = y;
		D_month = m;
		D_day = d;
		validate();
	}

	const char* Date::dateSS() const
	{
		return DATE_ERROR[errorCode()];
	}

	int Date::ccYear() const
	{
		return D_currentYear;
	}

	istream& Date::read(istream& in)
	{
		errorCode(NO_ERROR);
		in >> D_year;
		if (in.fail())
		{
			errorCode(CIN_FAILED);
		}
		else {
			in.get();
			in >> D_month;
			if (in.fail())
			{
				errorCode(CIN_FAILED);
			}
			else {
				in.get();
				in >> D_day;
				if (in.fail())
				{
					errorCode(CIN_FAILED);
				}
				validate();
			}
			
		}
		return in;
		// // O: insert return statement here
	}

	ostream& Date::write(ostream& out) const
	{
		if (error())
		{
			out << dateSS();
		}
		else
		{
			out << D_year;
			out << "/";
			out.fill('0');
			out.width(2);
			out << D_month;
			out << "/";
			out.fill('0');
			out.width(2);
			out << D_day;
			out.fill(' ');
		}
		return out;
		// // O: insert return statement here
	}

	bool Date::operator==(const Date& D) const
	{
		return startDay() == D.startDay();
	}

	bool Date::operator!=(const Date& D) const
	{
		return startDay() != D.startDay();
	}

	bool Date::operator>=(const Date& D) const
	{
		return startDay() >= D.startDay();
	}

	bool Date::operator<=(const Date& D) const
	{
		return startDay() <= D.startDay();
	}

	bool Date::operator>(const Date& D) const
	{
		return startDay() > D.startDay();
	}

	bool Date::operator<(const Date& D) const
	{
		return startDay() < D.startDay();
	}

	Date::operator bool() const
	{
		return !D_errorCode;
	}

	Date& Date::operator=(const Date& D)
	{
		if (this != &D)
		{
			D_year = D.D_year;
			D_month = D.D_month;
			D_day = D.D_day;
			D_currentYear = D.D_currentYear;
		}
		return *this;
		// // O: insert return statement here
	}

	void Date::errorCode(int errCode)
	{
		D_errorCode = errCode;
	}
	int Date::errorCode() const
	{
		return D_errorCode;
	}
	

	bool Date::error() const
	{
		return D_errorCode !=0;
	}

	ostream& operator<<(ostream& out, const Date& DD)
	{
		return DD.write(out);
		// // O: insert return statement here
	}

	istream& operator>>(istream& in, Date& DD)
	{
		return DD.read(in);
		// // O: insert return statement here
	}

	int operator-(const Date& DR, const Date& DL)
	{
		return DR.startDay() - DL.startDay();
	}

}
