/*
Student Name: Vasantharajan Sharmilann
SID: 142642180
Milestone 5
File: Book.cpp

All the code done in this milestone is done purely by me, as i have only used resouces from previous lecture and notes.
*/

#ifndef SDDS_STREAMABLE_H
#define SDDS_STREAMABLE_H
#include <iostream>

namespace sdds {
	class Streamable {
	public:
		virtual std::ostream& write(std::ostream& out) const = 0;
		virtual std::istream& read(std::istream& in) = 0;
		virtual bool conIO(std::ios& iostr) const = 0;
		virtual operator bool()const = 0;
		virtual ~Streamable() {};
	};
	std::ostream& operator<<(std::ostream& out, const Streamable& ss);
	std::istream& operator>>(std::istream& in, Streamable& ss);
}




#endif // !SDDS_STREAMABLE_H
