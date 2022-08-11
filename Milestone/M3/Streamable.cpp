/*
Student Name: Vasantharajan Sharmilann
SID: 142642180
Milestone 3
File: Streamable.cpp

All the code done in this milestone is done purely by me, as i have only used resouces from previous lecture and notes.

*/
#include <iostream>
#include "Streamable.h"

using namespace std;
namespace sdds {

	std::ostream& operator<<(std::ostream& ostr, const Streamable& stream)
	{
		if (stream) stream.write(ostr);
		return ostr;
	}
	std::istream& operator>>(std::istream& istr, Streamable& stream)
	{
		return stream.read(istr);
	}

}