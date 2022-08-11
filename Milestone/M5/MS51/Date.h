// Final Project Milestone 3
// Date Module
// File  Date.h
// Version 1.0
// Author   Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////
#ifndef SDDS_DATE_H__
#define SDDS_DATE_H__
#include <iostream>
namespace sdds {
   extern bool sdds_test;
   extern int sdds_year;
   extern int sdds_mon;
   extern int sdds_day;
   const int NO_ERROR = 0;
   const int CIN_FAILED = 1;
   const int YEAR_ERROR = 2;
   const int MON_ERROR = 3;
   const int  DAY_ERROR = 4;
   const char DATE_ERROR[5][16] = {
      "No Error",
      "cin Failed",
      "Bad Year Value",
      "Bad Month Value",
      "Bad Day Value"
   };
   const int  MIN_YEAR = 2000;
   class Date {
   private:
      int D_YEAR;
      int D_MONTH;
      int D_DAY;
      int D_CURRENTYEAR;
      int D_ERROR;
      bool validate();                            
      void errCode(int);        
      int systemYear()const;      
      bool invalid()const;         
      int daysLeft()const;         
      void Today();
      int start()const;       
   public:
      Date();
      Date(int y, int m, int d); 
      int errCode()const;        
      const char* dateSS()const; 
      int currentYear()const;        
      std::istream& read(std::istream& in = std::cin);
      std::ostream& write(std::ostream& out = std::cout)const;
      bool operator==(const Date& DD)const;
      bool operator!=(const Date& DD)const;
      bool operator>=(const Date& DD)const;
      bool operator<=(const Date& DD)const;
      bool operator>(const Date& DD)const;
      bool operator<(const Date& DD)const;
      operator bool() const;
      Date& operator=(const Date& date);
      friend int operator-(const Date& DateLEFT, const Date& DateRIGHT);
   };

   std::ostream& operator<<(std::ostream& out, const Date& Date11);
   std::istream& operator>>(std::istream& in, Date& Date11);

   
}
#endif