/*
*************************************************************************************************************************
Milestone 2
File: LibApp.h
Student Name: Vasantharajan Sharmilann
OOP 244
All the codes that you see in this file has been done my me and references to the OOP244 web page for referneces.
***************************************************************************************************************************
*/
#ifndef SDDS_LIB_APP_H
#define SDDS_LIB_APP_H
#include "Menu.h"
namespace sdds {
	class LibApp {
		bool m_changed = false;
		Menu m_mainMenu{ "Seneca Library Application" };
		Menu m_exitMenu{ "Changes have been made to the data, what would you like to do?" };
		bool confirm(const char* message);
		void load();
		void save();
		void search();
		void returnPub();
		void newPublication();
		void removePublication();
		void checkOutPub();
	public:
		LibApp();
		void run();
	};
}

#endif // !SSD_LIB_APP_H