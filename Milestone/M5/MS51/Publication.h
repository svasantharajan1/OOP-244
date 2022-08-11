/*
Student Name: Vasantharajan Sharmilann
SID: 142642180
Milestone 5
File: Book.cpp

All the code done in this milestone is done purely by me, as i have only used resouces from previous lecture and notes.
*/
#include <iostream>
#include "Date.h"
#include "Lib.h"
#include "Streamable.h"

#ifndef SDDS_PUBLICATION_H
#define SDDS_PUBLICATION_H


namespace sdds {
	class Publication : public Streamable {
		char* P_title;
		char P_shelfID[SDDS_SHELF_ID_LEN + 1];
		int P_memb;
		int P_libRef;
		Date Date14;
	public:
		Publication();
		Publication(const Publication& copy_P);
		void setEmpty();
		virtual void set(int member_id);
		void setRef(int value);
		void resetDate();
		virtual char type() const;
		bool onLoan()const;
		Date checkoutDate()const;
		bool operator==(const char* title) const;
		Publication& operator=(const Publication& P);  
		operator const char* () const;
		int getRef()const;
		std::ostream& write(std::ostream& out) const;
		std::istream& read(std::istream& in);
		bool conIO(std::ios& iostr)const;
		operator bool()const;
		virtual ~Publication();
	};
}
#endif // !SDDS_PUBLICATION_H