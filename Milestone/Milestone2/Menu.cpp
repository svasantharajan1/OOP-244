/*
*************************************************************************************************************************
Milestone 2
File: Menu.cpp
Student Name: Vasantharajan Sharmilann
OOP 244
All the codes that you see in this file has been done my me and references to the OOP244 web page for referneces.
***************************************************************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Menu.h"
using namespace std;
namespace sdds {

	MenuItem::MenuItem()
	{
		m_menuItem = nullptr;
	}

	MenuItem::MenuItem(const char* item)
	{
		delete[] m_menuItem;
		m_menuItem = new char[strlen(item) + 1];
		strcpy(m_menuItem, item);

	}

	MenuItem::~MenuItem()
	{
		delete[] m_menuItem;
	}

	MenuItem::operator bool() const
	{
		if (m_menuItem != nullptr)
		{
			return true;
		}
		else
		{
			return false;
		}

	}

	void MenuItem::display()
	{
		cout << m_menuItem;
	}

	Menu::Menu()
	{
		m_menuTitle = nullptr;
		m_noofmenu = 0;
	}

	Menu::Menu(const char* title)
	{
		delete[] m_menuTitle;
		m_menuTitle = new char[strlen(title) + 1];
		strcpy(m_menuTitle, title);
	}

	Menu::~Menu()
	{
		delete[] m_menuTitle;
		for (int i = 0; i < m_noofmenu; i++)
		{
			delete m_items[i];
		}
	}

	void Menu::display()
	{
		if (m_menuTitle != nullptr)
		{
			cout << m_menuTitle <<  endl;

			for (int i = 0; i < m_noofmenu; i++)
			{
				cout << " " << i + 1 << "- " << m_items[i]->m_menuItem << endl;
			}
		}
		cout << " 0- Exit" << endl;
	}

	int Menu::run()
	{
		display();
		char oo;
		cout << "> ";
		cin >> oo;
		int o = oo - '0';
		while (o < 0 || o > m_noofmenu)
		{
			cin.clear();
			cin.ignore(80, '\n');
			cout << " Invalid Selection, try again: ";
			cin >> oo;
			o = oo - '0';
		}
		return o;
	}


	Menu::operator bool() const
	{
		if (m_menuTitle == nullptr)
		{
			return false;
		}
		else {
			return true;
		}
	}

	int Menu::operator~()
	{
		display();
		char o;
		cin >> o;
		int oo = o - '0';
		while (oo < 0 || oo > m_noofmenu)
		{

			cin.clear();
			cin.ignore(80, '\n');
			cout << "Invalid Selection, try again: ";
			cin >> oo;
			oo = o - '0';



		}
		return oo;
	}

	Menu& Menu::operator<<(const char* menuitemContent)
	{
		m_items[m_noofmenu++] = new MenuItem(menuitemContent);
		return *this;
		// // O: insert return statement here
	}

	ostream& Menu::write(ostream& os) const
	{
		if (m_menuTitle != nullptr)
		{
			os << m_menuTitle;
		}
		return os;


		// // O: insert return statement here
	}
	ostream& operator<<(ostream& os, const Menu& m)
	{

		return m.write(os);
		// // O: insert return statement here
	}

	Menu::operator unsigned int() const
	{
		return m_noofmenu;
	}

	char* Menu::operator[](int i) const
	{
		return m_items[i]->m_menuItem;
	}

}