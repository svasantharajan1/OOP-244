/*
Student Name: Vasantharajan Sharmilann
SID: 142642180
Milestone 5
File: Book.cpp

All the code done in this milestone is done purely by me, as i have only used resouces from previous lecture and notes.


*/

#define _CRT_SECURE_NO_WARNINGS
#include "Book.h"
#include<cstring>
#include <iostream>
using namespace std;
namespace sdds {



	Book::Book()
	{
		m_aName = nullptr;
	}

	Book::Book(const Book& Book1):Book()
	{
		operator=(Book1);
	}
	Book& Book::operator=(const Book& Book1)
	{
		if (this != &Book1)
		{
			Publication::operator=(Book1);
			if (Book1.m_aName && Book1.m_aName[0] != '\0')
			{
				delete[] m_aName;
				m_aName = new char[strlen(Book1.m_aName) + 1];
				strcpy(m_aName, Book1.m_aName);
			}

		}
		return *this;
		// // O: insert return statement here
	}
	char Book::type() const
	{
		return 'B';
	}
	ostream& Book::write(ostream& out) const
	{
		char* authorT{};
		Publication::write(out);
		if (conIO(out))
		{
			out << " ";
			out.width(SDDS_AUTHOR_WIDTH);
			out.setf(ios::left);
			if (strlen(m_aName) > SDDS_AUTHOR_WIDTH)
			{
				authorT = new char[SDDS_AUTHOR_WIDTH + 1];
				strncpy(authorT, m_aName, SDDS_AUTHOR_WIDTH);
				authorT[SDDS_AUTHOR_WIDTH] = '\0';
				out << authorT << " |";
			}
			else {
				out << m_aName << " |";
			}
			out.unsetf(ios::left);
		}
		else
		{
			out << "\t" << m_aName;
		}
		delete[] authorT;
		authorT = nullptr;
		return out;
		// // O: insert return statement here
	}
	istream& Book::read(istream& in)
	{
		char authorT[256]{};
		Publication::read(in);
		delete[] m_aName;
		if (conIO(in))
		{
			in.ignore();
			cout << "Author: ";
			in.getline(authorT, 256);
		}
		else {
			in.get();
			in.get(authorT, 256);
		}
		if (in)
		{
			m_aName = new char[strlen(authorT) + 1];
			strcpy(m_aName, authorT);
		}
		return in;
		// // O: insert return statement here
	}
	void Book::set(int mem_ID)
	{
		Publication::set(mem_ID);
		Publication::resetDate();
	}
	Book::operator bool() const
	{
		return ((m_aName && m_aName[0] != '\0') && Publication::operator bool());
	}
	Book::~Book()
	{
		delete[] m_aName;
	}
}