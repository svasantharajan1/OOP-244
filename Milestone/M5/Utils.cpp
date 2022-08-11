/*
Student Name: Vasantharajan Sharmilann
SID: 142642180
Milestone 5
File: Utils.cpp

All the code done in this milestone is done purely by me, as i have only used resouces from previous lecture and notes.


*/

#include <iostream>
using namespace std;
#include "Utils.h"

using namespace std;
namespace sdds {
	int check(unsigned int min, unsigned int max)
	{
		unsigned int option{};
		bool okk{};
		while (!okk) {
			cin >> option;
			if (cin.fail() || !(option >= min && option <= max)) {
				okk = false;
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Invalid Selection, try again: ";
			}
			else {
				okk = true;
			}
		}
		cin.ignore(1000, '\n');
		return option;
	}

	int getInt()
	{
		int temp{};
		bool good{};
		do {
			cin >> temp;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Invalid number:";
			}
			else {
				good = true;
			}
		} while (!good);
		cin.ignore(1000, '\n');

		return temp;
	}


}