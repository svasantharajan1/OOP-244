/*
Student Name: Vasantharajan Sharmilann
SID: 142642180
Milestone 4
File: Utils.cpp

All the code done in this milestone is done purely by me, as i have only used resouces from previous lecture and notes.


*/

#include <iostream>
using namespace std;
#include "Utils.h"

using namespace std;
namespace sdds {
	int selectOption(unsigned int min, unsigned int max)
	{
		unsigned int select{};
		bool done{};
		while (!done) {
			cin >> select;
			if (cin.fail() || !(select >= min && select <= max)) {
				done = false;
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Invalid Selection, try again: ";
			}
			else {
				done = true;
			}
		}
		cin.ignore(1000, '\n');
		return select;
	}

	void flushInput(std::istream& is)
	{
		//is.clear();
		//is.ignore(1000, '\n');
	}

	int getInt()
	{
		int tmp{};
		bool done{};
		do {
			cin >> tmp;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Invalid number:";
			}
			else {
				done = true;
			}
		} while (!done);
		cin.ignore(1000, '\n');

		return tmp;
	}


}