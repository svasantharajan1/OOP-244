/*
Student Name: Vasantharajan Sharmilann
SID: 142642180
Milestone 5
File: Book.cpp

All the code done in this milestone is done purely by me, as i have only used resouces from previous lecture and notes.
*/
#ifndef SDDS_MENU_H_
#define SDDS_MENU_H_
#include <iostream>
namespace sdds {
	const unsigned int MAX_MENU_ITEMS = 20;
	class Menu;
	class MenuItem {
		char* MM_ITEM{};
		friend class Menu;
		MenuItem();
		MenuItem(const char* item1);
		~MenuItem();
		MenuItem& set(const char* item1);
		bool isEmpty()const;
		operator bool() const;
		operator const char* ()const;
		std::ostream& displayMenuItem(std::ostream& out) const;
		MenuItem& operator=(const MenuItem& MM);
	};
	class Menu {
		MenuItem m_title{};
		MenuItem* m_menuItems[MAX_MENU_ITEMS]{};
		unsigned int m_numOfItem{};
	public:
		Menu();
		Menu(const char* title);
		~Menu();
		std::ostream& displayTitle(std::ostream& out)const;
		std::ostream& displayMenu(std::ostream& out = std::cout)const;
		unsigned int run() const;
		unsigned int operator~()const;
		Menu& operator<<(const char* menuItemContent);
		operator int()const;
		operator unsigned int()const;
		operator bool()const;
		const char* operator[](int index)const;
	};
	std::ostream& operator<<(std::ostream& out, const Menu& menu);

}


#endif // !SDDS_MENU_H


