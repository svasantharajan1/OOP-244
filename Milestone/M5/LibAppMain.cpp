/*
Student Name: Vasantharajan Sharmilann
SID: 142642180
Milestone 5
File: LibAppMain.cpp

All the code done in this milestone is done purely by me, as i have only used resouces from previous lecture and notes.


*/

#include "LibApp.h"
#include "Date.h"
int main()
{
	sdds::sdds_day = 8;
	sdds::sdds_mon = 7;
	sdds::sdds_year = 2022;
	sdds::sdds_test = true;
	sdds::LibApp theApp("LibRecsSmall.txt");
	theApp.run();
	return 0;
}