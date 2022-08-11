#ifndef SDDS_STREAMABLE_H
#define SDDS_STREAMABLE_H

#include <iostream>

namespace sdds {
	class Streamable {
	public:
		virtual std::ostream& write(std::ostream& ostr) const = 0;
		virtual std::istream& read(std::istream& istr) = 0;
		virtual bool conIO(std::ios& iostr) const = 0;
		virtual operator bool()const = 0;
		virtual ~Streamable() {};
	};
	std::ostream& operator<<(std::ostream& out, const Streamable& ss);
	std::istream& operator>>(std::istream& in, Streamable& ss);
}




#endif // !SDDS_STREAMABLE_H