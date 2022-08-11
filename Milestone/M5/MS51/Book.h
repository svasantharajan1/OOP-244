/*
Student Name: Vasantharajan Sharmilann
SID: 142642180
Milestone 5
File: Book.cpp

All the code done in this milestone is done purely by me, as i have only used resouces from previous lecture and notes.
*/
#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
#include <iostream>
#include "Publication.h"
namespace sdds {
	class Book : public Publication {
		char* a_name;
	public:
		Book();
		Book(const Book& Book1);
		Book& operator=(const Book& Book1);
		virtual char type() const;
		virtual std::ostream& write(std::ostream& out)const;
		virtual std::istream& read(std::istream& in);
		virtual void set(int m_id);
		virtual operator bool()const;
		~Book();
	};
}





#endif // !SDDS_BOOK_H
