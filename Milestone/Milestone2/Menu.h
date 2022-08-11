/*
*************************************************************************************************************************
Milestone 2
File: Menu.h
Student Name: Vasantharajan Sharmilann
OOP 244
All the codes that you see in this file has been done my me and references to the OOP244 web page for referneces.
***************************************************************************************************************************
*/
#ifndef SDDS_MENU_H
#define SDDS_MENU_H
#include <iostream>
using namespace std;
namespace sdds {
	const int MAX_MENU_ITEMS = 20;
	class Menu;
	class MenuItem {
		char* m_menuItem{};
		MenuItem();
		MenuItem(const char* item);
		~MenuItem();
		operator bool() const;
		void display();
		friend Menu;

	};
	class Menu {
		char* m_menuTitle{};
		MenuItem* m_items[MAX_MENU_ITEMS];
		int m_noofmenu = 0;
	public:
		Menu();
		Menu(const char* title);
		~Menu();
		int run();
		char* operator[](int i) const;
		operator bool() const;
		int operator~();
		void display();
		ostream& write(ostream& os = cout)const;
		Menu& operator<<(const char* menuitemContent);
		operator unsigned int() const;
	};

	ostream& operator<<(ostream& os, const Menu& m);
}

#endif // !SDDS_MENU_H