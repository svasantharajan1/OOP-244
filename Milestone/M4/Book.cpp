/*
Student Name: Vasantharajan Sharmilann
SID: 142642180
Milestone 4
File: Book.cpp

All the code done in this milestone is done purely by me, as i have only used resouces from previous lecture and notes.


*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include "Book.h"

using namespace std;
namespace sdds {
	Book::Book()
	{
		m_author = nullptr;
	}
	Book::Book(const Book& B) : Book()
	{
		operator=(B);
	}

	Book& Book::operator=(const Book& B)
	{
		if (this != &B) {
			Publication::operator=(B); //copy base class
			if (B.m_author && B.m_author[0] != '\0') {
				delete[] m_author;
				m_author = new char[strlen(B.m_author) + 1];
				strcpy(m_author, B.m_author);
			}
		}
		return *this;
	}

	char Book::type() const
	{
		return 'B';
	}

	std::ostream& Book::write(std::ostream& ostr) const
	{
		char* tmp_author{};
		Publication::write(ostr);
		if (conIO(ostr)) {
			ostr << " ";
			ostr.width(SDDS_AUTHOR_WIDTH);
			ostr.setf(ios::left);
			if (strlen(m_author) > SDDS_AUTHOR_WIDTH) {
				tmp_author = new char[SDDS_AUTHOR_WIDTH + 1];
				strncpy(tmp_author, m_author, SDDS_AUTHOR_WIDTH);
				tmp_author[SDDS_AUTHOR_WIDTH] = '\0';
				ostr << tmp_author << " |";
			}
			else {
				ostr << m_author << " |";
			}
			ostr.unsetf(ios::left);
		}
		else {
			ostr << "\t" << m_author;
		}
		delete[] tmp_author;
		tmp_author = nullptr;
		return ostr;
	}

	std::istream& Book::read(std::istream& istr)
	{
		char tmp_author[256]{};
		Publication::read(istr);
		delete[] m_author;
		if (conIO(istr)) {
			istr.ignore();
			cout << "Author: ";
			istr.getline(tmp_author, 256);
		}
		else {
			istr.get();
			istr.get(tmp_author, 256);
		}
		if (istr) {
			m_author = new char[strlen(tmp_author) + 1];
			strcpy(m_author, tmp_author);
		}
		return istr;
	}

	void Book::set(int membership_id)
	{
		Publication::set(membership_id);
		Publication::resetDate();
	}

	Book::operator bool() const
	{
		return ((m_author && m_author[0] != '\0') && Publication::operator bool());
	}

	Book::~Book()
	{
		delete[] m_author;
	}




}
