/*
Student Name: Vasantharajan Sharmilann
SID: 142642180
Milestone 5
File: PublicationSelector.cpp

All the code done in this milestone is done purely by me, as i have only used resouces from previous lecture and notes.


*/

#define _CRT_SECURE_NO_WARNINGS
#include "PublicationSelector.h"
#include <iostream>
#include <cstring>
using namespace std;
namespace sdds {
	void PublicationSelector::display(int pg) const
	{
		cout << ps_title << endl << " Row  |LocID | Title                          |Mem ID | Date       | Author          |" << endl << "------+------+--------------------------------+-------+------------+-----------------|" << endl;
		for (int i = (pg - 1) * pSize; i < ps_total && i < pg * pSize; i++)
		{
			cout.width(4);
			cout.setf(ios::right);
			cout.fill(' ');
			cout << (i + 1);
			cout.unsetf(ios::right);
			cout << "- " << *m_pub[i] << endl;
		}
	}
	int PublicationSelector::select() const
	{
		bool good{};
		char line{};
		char Peek1{};
		int num{};
		int value{};
		if (ps_total > pSize)
		{
			if (ps_cpage > 1)
			{
				cout << "> P (Previous Page)" << endl;
			}
			if (ps_cpage * pSize < ps_total)
			{
				cout << "> N (Next page" << endl;
			}
		}
		cout << "> X (to Exit)" << endl << "> Row Number(selec publication)" << endl;
		cout << "> ";
		do {
			Peek1 = cin.peek();
			switch (Peek1)
			{
			case 'P':
			case'p':

				cin.ignore(1000, '\n');
				value = 2;
				if (ps_cpage > 1)
				{
					good = true;
				}
				else
				{
					good = false;
					break;
				}
			case 'N':
			case 'n':
				cin.ignore(1000, '\n');
				value = 1;
				if (ps_cpage * pSize < ps_total)
				{
					good = true;
				}
				else
				{
					good = false;
					break;
				}
			case 'X':
			case 'x':
				cin.ignore(1000, '\n');
				value = 0;
				good = true;
				break;
			default:
				cin >> num;
				line = cin.get();
				if (cin.fail() || line != '\n')
				{
					good = false;
					cin.clear();
					cin.ignore(1000, '\n');
				}
				else
				{
					good = num >= 1 && num <= ps_total;
					if (good)
					{
						value = m_pub[num - 1]->getRef();
					}
				}
				break;
			}

		} while (!good && cout << "Invalid selection, retry" << endl << "> ");
		return value;
	}
	PublicationSelector::~PublicationSelector()
	{
		delete[] m_pub;
	}
	PublicationSelector::PublicationSelector(const char* title, int psize)
	{
		strncpy(ps_title, title, 80);
		ps_title[80] = 0;
		m_pub = new const Publication * [ps_array = units];
	}
	
	PublicationSelector& PublicationSelector::operator<<(const Publication& pp)
	{
		return operator<<(&pp);
		// // O: insert return statement here
	}
	PublicationSelector& PublicationSelector::operator<<(const Publication* pp)
	{
		if (ps_total == ps_array)
		{
			const Publication** arrr = new const Publication * [ps_array += units];
			for (int i = 0; i < ps_total; i++)
			{
				arrr[i] = m_pub[i];
			}
			delete[] m_pub;
			m_pub = arrr;
		}
		m_pub[ps_total++] = pp;
		return *this;
		// // O: insert return statement here
	}
	void PublicationSelector::neww()
	{
		delete[] m_pub;
		m_pub = new const Publication * [20];
		ps_total = 0;
	}
	int PublicationSelector::run()
	{
		int value{};
		do {
			display(ps_cpage);
			value = select();
			if (value && value < 3)
			{
				if (value == 2)
				{
					value = -1;
				}
				ps_cpage += value;
			}
		} while (value && value < 3);
		return value;
	}
	void PublicationSelector::sort()
	{
		int a, b;
		const Publication* t{};
		for (a = 0; a < ps_total - 1; a++)
		{
			for (b = 0; b < ps_total - a - 1; b++)
			{
				if (m_pub[b]->checkoutDate() > m_pub[b + 1]->checkoutDate())
				{
					t = m_pub[b];
					m_pub[b] = m_pub[b + 1];
					m_pub[b + 1] = t;
				}
			}
		}
		for (a = 0; a < ps_total - 1; a++)
		{
			for (b = 0; b < ps_total - a - 1; b++)
			{
				if (strcmp((const char*)*m_pub[b], (const char*)*m_pub[b + 1]) > 0)
				{
					t = m_pub[b];
					m_pub[b] = m_pub[b + 1];
					m_pub[b + 1] = t;
				}
			}
		}
	}
	PublicationSelector::operator bool() const
	{
		return ps_total > 0;
	}
	
	
}