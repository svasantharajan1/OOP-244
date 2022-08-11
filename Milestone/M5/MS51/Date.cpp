/*
Student Name: Vasantharajan Sharmilann
SID: 142642180
Milestone 5
File: Date.cpp

All the code done in this milestone is done purely by me, as i have only used resouces from previous lecture and notes.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <ctime>
#include "Date.h"
#include "Utils.h"
using namespace std;
namespace sdds {
    bool sdds_test = false;
    int sdds_year = 2022;
    int sdds_mon = 8;
    int sdds_day = 7;
    
   bool Date::validate() {
      errCode(NO_ERROR);
      if (D_YEAR < MIN_YEAR || D_YEAR > D_CURRENTYEAR + 1) {
         errCode(YEAR_ERROR);
      }
      else if (D_MONTH< 1 || D_MONTH> 12) {
         errCode(MON_ERROR);
      }
      else if (D_DAY < 1 || D_DAY > daysLeft()) {
         errCode(DAY_ERROR);
      }
      return !invalid();
   }
   int Date::daysLeft()const {
      int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
      int mon = D_MONTH>= 1 && D_MONTH<= 12 ? D_MONTH: 13;
      mon--;
      return days[mon] + int((mon == 1) * ((D_YEAR % 4 == 0) && (D_YEAR % 100 != 0)) || (D_YEAR % 400 == 0));
   }
   int Date::systemYear()const {
       int theYear = sdds_year;
       if (!sdds_test) {
           time_t t = time(NULL);
           tm lt = *localtime(&t);
           theYear = lt.tm_year + 1900;
       }
       return theYear;
   }
   void Date::Today() {
       if (sdds_test) {
           D_DAY = sdds_day;
           D_MONTH= sdds_mon;
           D_YEAR = sdds_year;
       }
       else {
           time_t t = time(NULL);
           tm lt = *localtime(&t);
           D_DAY = lt.tm_mday;
           D_MONTH= lt.tm_mon+ 1;
           D_YEAR = lt.tm_year+ 1900;
       }
       errCode(NO_ERROR);
   }
   int Date::start()const { 
      int ty = D_YEAR;
      int tm = D_MONTH;
      if (tm < 3) {
         ty--;
         tm += 12;
      }
      return 365 * ty + ty / 4 - ty / 100 + ty / 400 + (153 * tm - 457) / 5 + D_DAY - 306;
   }
   Date::Date() :D_CURRENTYEAR(systemYear())
{
      Today();
   }
   Date::Date(int year, int mon, int day) : D_CURRENTYEAR(systemYear()) {
      D_YEAR = year;
      D_MONTH= mon;
      D_DAY = day;
      validate();
   }
   const char* Date::dateSS()const {
      return DATE_ERROR[errCode()];
   }
   int Date::currentYear()const {
      return D_CURRENTYEAR;
   }
   std::istream& Date::read(std::istream& in) {
       errCode(NO_ERROR);
       in >> D_YEAR;
       if (in.fail()) 
       {
           errCode(CIN_FAILED);
       }
       else 
       {
           in.get(); 
           in >> D_MONTH;
           if (in.fail()) 
           {
               errCode(CIN_FAILED);
           }
           else 
           {
               in.get();  
               in >> D_DAY;
               if (in.fail())
                {
                   errCode(CIN_FAILED);
               }
               validate();
           }
       }
       return in;
   }
   std::ostream& Date::write(std::ostream& out) const {
       if (invalid())
        {
           out << dateSS();
       }
       else
        {
           out << D_YEAR << "/";
           out.fill('0');
           out.width(2);
           out << D_MONTH<< "/";
           out.fill('0');
           out.width(2);
           out << D_DAY;
           out.fill(' ');
       }
       return out;
   }
   bool Date::operator==(const Date& DD) const {
       return start() == DD.start();
   }
   bool Date::operator!=(const Date& DD) const {
       return start() != DD.start();
   }
   bool Date::operator>=(const Date& DD) const {
       return start() >= DD.start();
   }
   bool Date::operator<=(const Date& DD) const {
       return start() <= DD.start();
   }
   bool Date::operator>(const Date& DD) const {
       return start() > DD.start();
   }
   bool Date::operator<(const Date& DD) const {
       return start() < DD.start();
   }
   Date::operator bool() const {
       return !D_ERROR;
   }
   Date& Date::operator=(const Date& date) {
       if (this != &date) {
           D_YEAR = date.D_YEAR;
           D_MONTH= date.D_MONTH;
           D_DAY = date.D_DAY;
           D_CURRENTYEAR = date.D_CURRENTYEAR;
       }
       return *this;
   }
   void Date::errCode(int Code) {
      D_ERROR = Code;
   }
   int Date::errCode()const {
      return D_ERROR;
   }
   bool Date::invalid()const {
      return D_ERROR != 0;
   }
   ostream& operator<<(ostream& out, const Date& Date11) {
      return Date11.write(out);
   }
   istream& operator>>(istream& in, Date& Date11) {
      return Date11.read(in);
   }

   int operator-(const Date& date1, const Date& date2) {
       return date1.start() - date2.start();
   }

   


}
