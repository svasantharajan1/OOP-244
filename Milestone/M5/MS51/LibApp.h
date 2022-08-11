/*
Student Name: Vasantharajan Sharmilann
SID: 142642180
Milestone 5
File: Book.cpp

All the code done in this milestone is done purely by me, as i have only used resouces from previous lecture and notes.
*/
#ifndef SDDS_LIB_APP_H
#define SDDS_LIB_APP_H
#include "Publication.h"
#include "Menu.h"
namespace sdds {
	class LibApp {
		char P_name[256]{};
		Publication* P_p[SDDS_LIBRARY_CAPACITY]{};   
		int P_total{};    
		int P_last{};  
		Menu P_menu;
		bool m_changed;
		Menu P_mainMenu;
		Menu P_exitMenu;
		bool confirm(const char* message);
		void load();
		void save();
		int search(int searchMode);
		void returnPub();
		void newPublication();
		void removePublication();
		void checkOutPub();
	public:
		LibApp(const char* filename);
		void run();
		Publication* getPub(int libRef);
		virtual ~LibApp();
	};
}






#endif // !SDDS_LIB_APP_H