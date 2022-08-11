#ifndef SDDS_DATE_H
#define SDDS_DATE_H
#include <iostream>
namespace sdds {

    const int NO_ERROR = 0;
    const int CIN_FAILED = 1;
    const int YEAR_ERROR = 2;
    const int MON_ERROR = 3;
    const int  DAY_ERROR = 4;
    extern bool sdds_test;
    extern int sdds_year;
    extern int sdds_mon;
    extern int sdds_day;
    const char DATE_ERROR[5][16] = {
       "No Error",
       "cin Failed",
       "Bad Year Value",
       "Bad Month Value",
       "Bad Day Value"
    };
    const int  MIN_YEAR = 2000;
    class Date
    {
        int D_day;
        int D_month;
        int D_year;
        int D_errorCode;
        int D_currentYear;
        int startDay ()const;
        bool validate();
        void errorCode(int errCode);
        int systemYear()const;
        bool error() const;
        int dayLeft()const;
        void today();
    public:
        Date();
        Date(int d, int m, int y);
        int errorCode()const;
        const char* dateSS()const;
        int ccYear()const;
        std::istream& read(std::istream& in = std::cin);
        std::ostream& write(std::ostream& out = std::cout)const;
        bool operator==(const Date& D)const;
        bool operator!=(const Date& D)const;
        bool operator>=(const Date& D)const;
        bool operator<=(const Date& D)const;
        bool operator>(const Date& D)const;
        bool operator<(const Date& D)const;
        operator bool()const;
        Date& operator=(const Date& D);
        friend int operator-(const Date& DR, const Date& DL);

    };
    std::ostream& operator<<(std::ostream& out, const Date& DD);
    std::istream& operator>>(std::istream& in, Date& DD);
}
#endif // !SDDS_DATE_H
