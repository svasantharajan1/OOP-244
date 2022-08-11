/*
Student Name: Vasantharajan Sharmilann
SID: 142642180
Milestone 5
File: Menu.cpp

All the code done in this milestone is done purely by me, as i have only used resouces from previous lecture and notes.


*/
#define _CRT_SECURE_NO_WARNINGS
#include "Menu.h"
#include "Utils.h"
#include <iostream>
#include <string.h>
using namespace std;
namespace sdds {

	MenuItem::MenuItem() {
		MM_ITEM = nullptr;
	}
	MenuItem::MenuItem(const char* item1) {
		set(item1);
	}
	MenuItem::~MenuItem() {
		delete[] MM_ITEM;
	}
	MenuItem& MenuItem::set(const char* item1) 
	{
		if (item1 && item1[0] != '\0')
		 {
			MM_ITEM = new char[strlen(item1) + 1];
			strcpy(MM_ITEM, item1);
		}
		else 
		{
			MM_ITEM = nullptr;
		}
		return *this;
	}
	bool MenuItem::isEmpty()const 
	{
		return !(MM_ITEM && MM_ITEM[0] != '\n');
	}
	MenuItem::operator bool() const
	 {
		return !isEmpty();
	}
	MenuItem::operator const char* () const {
		return MM_ITEM;
	}
	ostream& MenuItem::displayMenuItem(ostream& out)const
	 {
		if (!isEmpty()) 
		{
			out << MM_ITEM;
		}
		return out;
	}

	MenuItem& MenuItem::operator=(const MenuItem& MM) 
	{
		return set((const char*)MM);
	}


	Menu::Menu() {
		m_title.MM_ITEM = nullptr;
	}
	Menu::Menu(const char* title) {
		if (title && title[0] != '\n')
		 {
			m_title.set(title);
		}
	}
	Menu::~Menu() {
		for (unsigned int i = 0; i < m_numOfItem; i++) 
		{
			delete m_menuItems[i];
		}
	}
	ostream& Menu::displayTitle(ostream& out)const 
	{
		if (m_title.MM_ITEM && m_title.MM_ITEM[0] != '\n')
		 {
			out << (const char*)m_title;
		}
		return out;
	}
	ostream& Menu::displayMenu(ostream& out)const 
	{
		if (m_title.MM_ITEM && m_title.MM_ITEM[0] != '\n')
		{
			displayTitle(out) << endl;
		}
		for (unsigned int i = 0; i < m_numOfItem; i++) 
		{
			out.width(2);
			out.setf(ios::right);
			out << i + 1 << "- ";
			m_menuItems[i]->displayMenuItem(out) << endl;
		}
		out << " 0- Exit" << endl << "> ";
		return out;
	}
	unsigned int Menu::run()const {
		displayMenu();
		return selectOption(0, m_numOfItem);
	}
	unsigned int Menu::operator~() const{
		return run();
	}
	Menu& Menu::operator<<(const char* menuItemitem1) 
	{
		if (m_numOfItem != MAX_MENU_ITEMS)
		 {
			m_menuItems[m_numOfItem] = new MenuItem;
			m_menuItems[m_numOfItem]->set(menuItemitem1);
			m_numOfItem++;
		}
		return *this;
	}
	Menu::operator int() const {
		return m_numOfItem;
	}
	Menu::operator unsigned int() const {
		return m_numOfItem;
	}
	Menu::operator bool() const {
		return m_numOfItem > 0;
	}
	const char* Menu::operator[](int index) const {
		return (const char*)*m_menuItems[index % m_numOfItem];
	}
	ostream& operator<<(ostream& out, const Menu& menu) {
		return menu.displayTitle(out);
	}

}