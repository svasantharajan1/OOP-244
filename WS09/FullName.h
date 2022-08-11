#ifndef SDDS_FULLNAME_H
#define SDDS_FULLNAME_H
#include <iostream>
#include "Name.h"
namespace sdds {
	class FullName :
		public Name {
		char* m_value;
	public:
		FullName();
		FullName(const char* name, const char* lastName);
		~FullName();
		FullName(const FullName& fn);
		FullName& operator=(const FullName& fn);
		operator const char* () const;
		virtual operator bool() const;
		virtual std::ostream& display(std::ostream& ostr = std::cout)const;
		virtual std::istream& read(std::istream& istr = std::cin);

	};
}



#endif // 