/*
Student Name: Vasantharajan Sharmilann
SID: 142642180
Milestone 5
File: Streamable.cpp

All the code done in this milestone is done purely by me, as i have only used resouces from previous lecture and notes.


*/

#include <iostream>
#include "Streamable.h"

using namespace std;
namespace sdds {

	ostream& operator<<(ostream& out, const Streamable& ss)
	{
		if (ss)
		{
			ss.write(out);
		}
		return out;
	}
	istream& operator>>(istream& in, Streamable& ss)
	{
		return ss.read(in);
	}

}