/*
Student Name: Vasantharajan Sharmilann
SID: 142642180
Milestone 5
File: Publication.cpp

All the code done in this milestone is done purely by me, as i have only used resouces from previous lecture and notes.


*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Publication.h"
#include <cstring>
#include <fstream>
#include "Utils.h"
using namespace std;
namespace sdds {

	Publication::Publication() :Date1()
	{
		empty();
	}

	Publication::Publication(const Publication& pub) :Publication()
	{
		operator=(pub);
	}

	void Publication::empty()
	{
		p_title = nullptr;
		p_shelfId[0] = '\0';
		p_member = 0;
		p_libref = -1;
	}
	void Publication::setRef(int num)
	{
		p_libref = num;
	}

	void Publication::set(int mem_id)
	{
		if (mem_id > 9999 && mem_id < 100000)
		{
			p_member = mem_id;
		}
		else
		{
			p_member = 0;
		}
	}

	

	void Publication::resetDate()
	{
		Date today;
		Date1 = today;
	}

	char Publication::type() const
	{
		return 'P';
	}

	bool Publication::onLoan() const
	{
		return p_member !=0;
	}

	Date Publication::checkoutDate() const
	{
		return Date1;
	}

	bool Publication::operator==(const char* title) const
	{
		return strstr(p_title, title);
	}

	Publication& Publication::operator=(const Publication& pp)
	{
		if (this!= &pp)
		{
			if ((pp.p_title && pp.p_title[0] != '\0') && (pp.p_shelfId && pp.p_shelfId[0] != '\0'))
			{
				delete[] p_title;
				p_title = new char[strlen(pp.p_title) + 1];
				strcpy(p_title, pp.p_title);
				strcpy(p_shelfId, pp.p_shelfId);
				p_member = pp.p_member;
				p_libref = pp.p_libref;
				Date1 = pp.Date1;
			}
		}
		return *this;
		// // O: insert return statement here
	}

	Publication::operator const char* () const
	{
		return p_title;
	}
	int Publication::getRef()const
	{
		return p_libref;
	}
	ostream& Publication::write(ostream& out)const
	{
		char* temp{};
		if (conIO(out))
		{
			out << "| " << p_shelfId << " | ";
			out.width(SDDS_TITLE_WIDTH);
			out.fill('.');
			out.setf(ios::left);
			if (strlen(p_title) > SDDS_TITLE_WIDTH)
			{
				temp = new char[SDDS_TITLE_WIDTH + 1];
				strncpy(temp, p_title, SDDS_TITLE_WIDTH);
				temp[SDDS_TITLE_WIDTH] = '\0';
				out << temp << " | ";
			}
			else {
				out << p_title << " | ";
			}
			out.width(5);
			out.fill(' ');
			out.unsetf(ios::left);
			if (p_member)
			{
				out << p_member;
			}
			else
			{
				out << "N/A ";
			}
			out << " | " << checkoutDate() << " |";
		}
		else
		{
			out << type() << "\t" << getRef() << "\t" << p_shelfId << "\t" << (const char*)*this << "\t" << p_member << "\t" << checkoutDate();
		}
		delete[] temp;
		temp = nullptr;
		return out;
	}

	istream& Publication::read(istream& in)
	{
		char tempID[SDDS_SHELF_ID_LEN + 1]{};
		char tempT[256]{};
		int tempLib{};
		int tempMem{};
		Date tempDate;
		empty();
		if (conIO(in))
		{
			cout << "Shelf No: ";
			in.getline(tempID, SDDS_SHELF_ID_LEN + 1);
			cout << "Title: ";
			if (in)
			{
				in.getline(tempT, 256);
				

			}
			cout << "Date: ";
			if (in)
			{
				in >> tempDate;
			}
		}
		else
		{
			in >> tempLib;
			in.get();
			in.getline(tempID, SDDS_SHELF_ID_LEN + 1, '\t');
			in.getline(tempT, 256, '\t');
			in >> tempMem;
			in >> tempDate;
		}

		if (!tempDate)
		{
			in.setstate(ios::failbit);
		}
		if (in)
		{
			if (tempLib) p_libref = tempLib;
			p_member = tempMem;
			strcpy(p_shelfId, tempID);
			p_title = new char[strlen(tempT) + 1];
			strcpy(p_title, tempT);
			Date1 = tempDate;
		}
		return in;
	}

	bool Publication::conIO(ios& io)const
	{
		return (&io == &cin || &io == &cout);
	}
	Publication::~Publication()
	{
		delete[] p_title;
	}
	Publication::operator bool() const
	{
		return ((p_title && p_title[0] != '\0') || (p_shelfId && p_shelfId[0] != '\0'));
	}

}