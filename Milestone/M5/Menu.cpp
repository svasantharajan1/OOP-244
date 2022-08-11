/*
Student Name: Vasantharajan Sharmilann
SID: 142642180
Milestone 5
File: Menu.cpp

All the code done in this milestone is done purely by me, as i have only used resouces from previous lecture and notes.


*/

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
#include "Menu.h"
#include "Utils.h"
using namespace std;
namespace sdds {
	MenuItem::MenuItem()
	{
		m_items = nullptr;
	}
	MenuItem::MenuItem(const char* item)
	{
		setMenu(item);
	}
	MenuItem::~MenuItem()
	{
		delete[] m_items;
	}
	MenuItem& MenuItem::setMenu(const char* item)
	{
		if (item && item[0] != '\0')
		{
			m_items = new char[strlen(item) + 1];
			strcpy(m_items, item);
		}
		else
		{
			m_items = nullptr;
		}
		return *this;
	}
	bool MenuItem::isempty() const
	{
		return !(m_items && m_items[0] != '\n');
	}
	MenuItem::operator bool() const
	{
		return !isempty();
	}
	MenuItem::operator const char* ()const
	{
		return m_items;
	}

	ostream& MenuItem::display(ostream& out)const
	{
		if (!isempty())
		{
			out << m_items;
		}
		return out;
	}

	MenuItem& MenuItem::operator=(const MenuItem& mMenu)
	{
		return setMenu((const char*)mMenu);
		// // O: insert return statement here
	}


	Menu::Menu()
	{
		m_title.m_items = nullptr;
	}

	Menu::Menu(const char* title)
	{
		if (title && title[0] != '\n')
		{
			m_title.setMenu(title);
		}
	}

	Menu::~Menu()
	{
		for (unsigned int i = 0; i < m_total; i++)
		{
			delete m_item[i];
		}
	}

	ostream& Menu::displayT(ostream& out) const
	{
		if (m_title.m_items && m_title.m_items[0] != '\n')
		{
			out << (const char*)m_title;
		}
		return out;
		// // O: insert return statement here
	}

	ostream& Menu::displayM(ostream& out) const
	{
		if (m_title.m_items && m_title.m_items[0] != '\n')
		{
			displayT(out) << endl;
		}
		for (unsigned int i = 0; i < m_total; i++)
		{
			out.width(2);
			out.setf(ios::right);
			out << i + 1 << "- ";
			m_item[i]->display(out) << endl;
		
		}
		out << " 0- Exit" << endl;
		out << "> ";
		return out;
		// // O: insert return statement here
	}

	unsigned int Menu::run() const
	{
		displayM();
		return check(0,m_total);
	}

	unsigned int Menu::operator~() const
	{
		return run();
	}

	Menu& Menu::operator<<(const char* menuItem)
	{
		if (m_total != MAX_MENU_ITEMS)
		{
			m_item[m_total] = new MenuItem;
			m_item[m_total]->setMenu(menuItem);
			m_total++;
		}
		return *this;
		// // O: insert return statement here
	}

	Menu::operator int() const
	{
		return m_total;
	}

	Menu::operator unsigned int() const
	{
		return m_total;
	}

	Menu::operator bool() const
	{
		return m_total > 0;
	}

	const char* Menu::operator[](int in) const
	{
		return (const char*) m_item[in % m_total];
	}

	ostream& operator<<(ostream& out, const Menu& MM)
	{
		return MM.displayT(out);
		// // O: insert return statement here
	}

}