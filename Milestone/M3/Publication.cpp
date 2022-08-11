/*
Student Name: Vasantharajan Sharmilann
SID: 142642180
Milestone 3
File: Publication.cpp

All the code done in this milestone is done purely by me, as i have only used resouces from previous lecture and notes.

*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <cstring>
#include "Publication.h"
#include "Utils.h"


using namespace std;
namespace sdds {
	Publication::Publication() : m_date()
	{
		setEmpty();
	}
	Publication::Publication(const Publication& copy_P) : Publication()
	{
		operator=(copy_P);
	}
	void Publication::setEmpty()
	{

		m_title = nullptr;
		m_shelfId[0] = '\0';
		m_membership = 0;
		m_libRef = -1;
	}
	void Publication::setRef(int value)
	{
		m_libRef = value;
	}
	void Publication::set(int member_id)
	{
		if (member_id > 9999 && member_id < 100000) {
			m_membership = member_id;
		}
		else {
			m_membership = 0;
		}
	}

	void Publication::resetDate()
	{
		Date currDate;
		m_date = currDate;
	}

	char Publication::type()const
	{
		return 'P';
	}
	bool Publication::onLoan() const
	{
		return m_membership != 0;
	}
	Date Publication::checkoutDate() const
	{
		return m_date;
	}
	bool Publication::operator==(const char* title) const
	{
		return strstr(m_title, title);
	}
	Publication& Publication::operator=(const Publication& P)
	{
		if (this != &P) {
			if ((P.m_title && P.m_title[0] != '\0') &&
				(P.m_shelfId && P.m_shelfId[0] != '\0')) {
				delete[] m_title;
				m_title = new char[strlen(P.m_title) + 1];
				strcpy(m_title, P.m_title);
				strcpy(m_shelfId, P.m_shelfId);
				m_membership = P.m_membership;
				m_libRef = P.m_libRef;
				m_date = P.m_date;
			}
		}
		return *this;
	}
	Publication::operator const char* () const
	{
		return m_title;
	}
	int Publication::getRef() const
	{
		return m_libRef;
	}
	std::ostream& Publication::write(std::ostream& ostr) const
	{
		if (conIO(ostr)) {
			ostr << "| " << m_shelfId << " | ";
			ostr.width(SDDS_TITLE_WIDTH);
			ostr.fill('.');
			ostr.setf(ios::left);
			ostr << (const char*)*this << " | ";
			ostr.width(5);
			ostr.fill(' ');
			ostr.unsetf(ios::left);
			if (m_membership) {
				ostr << m_membership;
			}
			else {
				ostr << "N/A ";
			}
			ostr << " | "
				<< checkoutDate() << " |";
		}
		else {
			ostr << type() << "\t" << getRef() << "\t" << m_shelfId <<
				"\t" << (const char*)*this << "\t" << m_membership
				<< "\t" << checkoutDate();
		}
		return ostr;
	}
	std::istream& Publication::read(std::istream& istr)
	{
		char tmp_shelfId[SDDS_SHELF_ID_LEN + 1]{};
		char tmp_title[255 + 1]{};
		int tmp_libRef{};
		int tmp_membership{};
		Date tmp_date;
		setEmpty();
		if (conIO(istr)) { //for user input
			cout << "Shelf No: ";
			istr.getline(tmp_shelfId, SDDS_SHELF_ID_LEN + 1);
			cout << "Title: ";
			if (istr) istr.getline(tmp_title, 256);
			cout << "Date: ";
			if (istr) istr >> tmp_date;
		}
		else { //for FILE
			istr >> tmp_libRef;
			istr.get();
			istr.getline(tmp_shelfId, SDDS_SHELF_ID_LEN + 1, '\t');
			istr.getline(tmp_title, 256, '\t');
			istr >> tmp_membership;
			istr >> tmp_date;
		}

		if (!tmp_date) {
			istr.setstate(ios::failbit);
		}

		if (istr) {
			m_libRef = tmp_libRef;
			m_membership = tmp_membership;
			strcpy(m_shelfId, tmp_shelfId);
			m_title = new char[strlen(tmp_title) + 1];
			strcpy(m_title, tmp_title);
			m_date = tmp_date;
		}
		return istr;
	}
	bool Publication::conIO(std::ios& iostr) const
	{
		return (&iostr == &cin || &iostr == &cout);
	}
	Publication::~Publication()
	{
		delete[] m_title;
	}
	Publication::operator bool() const
	{
		return ((m_title && m_title[0] != '\0') ||
			(m_shelfId && m_shelfId[0] != '\0'));
	}

}




