#include <iostream>
#include "Date.h"
#include "Lib.h"
#include "Streamable.h"

#ifndef SDDS_PUBLICATION_H
#define SDDS_PUBLICATION_H


namespace sdds {
	class Publication : public Streamable {
		char* m_title;
		char m_shelfId[SDDS_SHELF_ID_LEN + 1];
		int m_membership;
		int m_libRef;
		Date m_date;
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
		std::ostream& write(std::ostream& ostr) const;
		std::istream& read(std::istream& istr);
		bool conIO(std::ios& iostr)const;
		operator bool()const;
		virtual ~Publication();
	};












}
#endif //