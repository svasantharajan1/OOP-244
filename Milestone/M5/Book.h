#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
#include "Publication.h"
#include <iostream>
namespace sdds {
	class Book :
		public Publication {
		char* m_aName;
	public:
		Book();
		Book(const Book& Book1);
		Book& operator=(const Book& Book1);
		~Book();
		virtual char type() const;
		virtual std::ostream& write(std::ostream& out)const;
		virtual std::istream& read(std::istream& in);
		virtual void set(int mem_ID);
		virtual operator bool()const;

	};
}


#endif //