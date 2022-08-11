// Final Project Milestone 1 
// Date Module
// File	Date.cpp
// Version 1.0
// Author	Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name                                   Date                 SID
// Vasantharajan Sharmilann            2022/07/12	        142642180
/////////////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <ctime>
using namespace std;
#include "Date.h"
namespace sdds {
   bool Date::validate() {
      errCode(NO_ERROR);
      if (m_year < MIN_YEAR || m_year > m_CUR_YEAR + 1) {
         errCode(YEAR_ERROR);
      }
      else if (m_mon < 1 || m_mon > 12) {
         errCode(MON_ERROR);
      }
      else if (m_day < 1 || m_day > mdays()) {
         errCode(DAY_ERROR);
      }
      return !bad();
   }
   int Date::mdays()const {
      int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
      int mon = m_mon >= 1 && m_mon <= 12 ? m_mon : 13;
      mon--;
      return days[mon] + int((mon == 1) * ((m_year % 4 == 0) && (m_year % 100 != 0)) || (m_year % 400 == 0));
   }
   int Date::systemYear()const {
      time_t t = time(NULL);
      tm lt = *localtime(&t);
      return lt.tm_year + 1900;
   }
   void Date::setToToday() {
      time_t t = time(NULL);
      tm lt = *localtime(&t);
      m_day = lt.tm_mday;
      m_mon = lt.tm_mon + 1;
      m_year = lt.tm_year + 1900;
      errCode(NO_ERROR);
   }
   int Date::daysSince0001_1_1()const { // Rata Die day since 0001/01/01
      int ty = m_year;
      int tm = m_mon;
      if (tm < 3) {
         ty--;
         tm += 12;
      }
      return 365 * ty + ty / 4 - ty / 100 + ty / 400 + (153 * tm - 457) / 5 + m_day - 306;
   }
   Date::Date() :m_CUR_YEAR(systemYear()) {
      setToToday();
   }
   Date::Date(int year, int mon, int day) : m_CUR_YEAR(systemYear()) {
      m_year = year;
      m_mon = mon;
      m_day = day;
      validate();
   }
   const char* Date::dateStatus()const {
      return DATE_ERROR[errCode()];
   }
   int Date::currentYear()const {
      return m_CUR_YEAR;
   }
   bool Date::findChar(std::istream& is, char charr)
   {
       if (is.peek() == charr)
       {
           is.get();
           return true;
       }
       else
       {
           errCode(CIN_FAILED);
           is.setstate(ios::failbit);
           is.clear();
           is.ignore(80, '\n');
           return false;
       }
   }
   std::istream& Date::read(std::istream& is)
   {
       int year;
       int month;
       int day;

       is >> year;
       if (findChar(is, '/'))
       {
           is >> month;


           if (findChar(is, '/'))
           {
               is >> day;
           }
           else {
               return is;
           }
       }

       else
       {
           return is;
           
       }
       if (!is.fail())
       {
           m_year = year;
           m_mon = month;
           m_day = day;
           validate();
       }
       return is;
   }
   
   std::ostream& Date::write(std::ostream& os) const
   {
       if (!bad())
       {
           os << m_year << "/" << "0" << m_mon << "/" << m_day;
       }
       else {
           os << dateStatus();
       }
       return os;
   }
     
long int Date::operator-(Date i) const
{

    return (daysSince0001_1_1() - i.daysSince0001_1_1());
}
   Date::operator bool() const
   {
       return !bad();
   }
   bool Date::operator>(const Date& dat) const
   {
       if (this->m_year > dat.m_year)
       {
           return true;
       }
       else if (this->m_year < dat.m_year)
       {
           return false;
       }
       else
       {
           if (this->m_mon > dat.m_mon)
           {
               return true;
           }
           else if (this->m_mon < dat.m_mon)
           {
               return false;
           }
           else {
               if (this->m_day > dat.m_day)
               {
                   return true;
               }
               else if (this->m_day < dat.m_day)
               {
                   return false;
               }
               else {
                   return false;
               }
           }
       }
       return false;
   }
   
   bool Date::operator<(const Date& dat) const
   {
       if (this->m_year < dat.m_year)
       {
           return true;
       }
       else if (this->m_year > dat.m_year)
       {
           return false;
       }
       else {
           if (this->m_mon < dat.m_mon)
           {
               return true;
           }
           else if (this->m_mon > dat.m_mon)
           {
               return false;
           }
           else {
               if (this->m_day < dat.m_day)
               {
                   return true;
               }
               else if (this->m_day > dat.m_day)
               {
                   return false;
               }
           }
       }
       return false;
   }

   
   bool Date::operator==(const Date& dat) const
   {
       if (this->m_year == dat.m_year && this->m_mon == dat.m_mon && this->m_day == dat.m_day)
       {
           return true;
       }
       return false;
   }
   
   bool Date::operator!=(const Date& dat) const
   {
       return !(*this == dat);
   }
   bool Date::operator>=(const Date& dat) const
   {
       return (*this > dat) || (*this == dat);
   }
   bool Date::operator<=(const Date& dat) const
   {
       return (*this < dat) || (*this == dat);
   }
   void Date::errCode(int readErrorCode) {
      m_ErrorCode = readErrorCode;
   }
   int Date::errCode()const {
      return m_ErrorCode;
   }
   bool Date::bad()const {
      return m_ErrorCode != 0;
   }




   ostream& operator<<(ostream& os, const Date& RO) {
      return RO.write(os);
   }
   istream& operator>>(istream& is, Date& RO) {
      return RO.read(is);
   }

   


}