#ifndef SDDS_PUBLICATION_H
#define SDDS_PUBLICATION_H
#include <iostream>
#include "Lib.h"
#include "Date.h"
#include "Streamable.h"
namespace sdds {
	class Publication :
		public Streamable
		{
		char* p_title;
		char p_shelfId[SDDS_SHELF_ID_LEN + 1];
		int p_member;
		int p_libref;
		Date Date1;
		public:
			Publication();
			Publication(const Publication& pub);
			void empty();
			virtual void set(int mem_id);
			void setRef(int num);
			void resetDate();
			virtual char type() const;
			bool onLoan()const;
			Date checkoutDate()const;
			bool operator==(const char* title)const;
			Publication& operator=(const Publication& pp);
			operator const char* ()const;
			int getRef()const;
			std::ostream& write(std::ostream& out)const;
			std::istream& read(std::istream& in);
			bool conIO(std::ios& io)const;
			operator bool() const;
			virtual ~Publication();


	};
}
#endif // !SDDS_PUBLICATION_H
