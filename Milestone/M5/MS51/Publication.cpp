/*
Student Name: Vasantharajan Sharmilann
SID: 142642180
Milestone 5
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
	Publication::Publication() : Date14() {
		setEmpty();
	}
	Publication::Publication(const Publication& copy_P) : Publication() {
		operator=(copy_P);
	}
	void Publication::setEmpty() {
		
		P_title = nullptr;
		P_shelfID[0] = '\0';
		P_memb = 0;
		P_libRef = -1;
	}
	void Publication::setRef(int num) {
		P_libRef = num;
	}
	void Publication::set(int m_id) {
		if (m_id > 9999 && m_id < 100000) 
		{
			P_memb = m_id;
		}
		else {
			P_memb = 0;
		}
	}
	void Publication::resetDate() {
		Date currDate;
		Date14 = currDate;
	}

	char Publication::type()const {
		return 'P';
	}
	bool Publication::onLoan() const {
		return P_memb != 0;
	}
	Date Publication::checkoutDate() const {
		return Date14;
	}
	bool Publication::operator==(const char* title) const {
		return strstr(P_title, title);
	}
	Publication& Publication::operator=(const Publication& P) {
		if (this != &P) {
			if ((P.P_title && P.P_title[0] != '\0') &&
				(P.P_shelfID && P.P_shelfID[0] != '\0')) {
				delete[] P_title;
				P_title = new char[strlen(P.P_title) + 1];
				strcpy(P_title, P.P_title);
				strcpy(P_shelfID, P.P_shelfID);
				P_memb = P.P_memb;
				P_libRef = P.P_libRef;
				Date14 = P.Date14;
			}
		}
		return *this;
	}
	Publication::operator const char* () const {
		return P_title;
	}
	int Publication::getRef() const {
		return P_libRef;
	}
	ostream& Publication::write(ostream& out) const {
		char* temp{};
		if (conIO(out)) {
			out << "| " << P_shelfID << " | ";
			out.width(SDDS_TITLE_WIDTH);
			out.fill('.');
			out.setf(ios::left);
			if (strlen(P_title) > SDDS_TITLE_WIDTH) {
				temp = new char[SDDS_TITLE_WIDTH + 1];
				strncpy(temp, P_title, SDDS_TITLE_WIDTH);
				temp[SDDS_TITLE_WIDTH] = '\0';
				out << temp << " | ";
			}
			else {
				out << P_title << " | ";
			}
			out.width(5);
			out.fill(' ');
			out.unsetf(ios::left);
			if (P_memb) {
				out << P_memb;
			}
			else {
				out << "N/A ";
			}
			out  << " | "
				  << checkoutDate() << " |";
		}
		else {
			out << type() << "\t" << getRef() << "\t" << P_shelfID <<
				"\t" << (const char*)*this << "\t" << P_memb 
				<< "\t" << checkoutDate();
		}
		delete[] temp;
		temp = nullptr;
		return out;
	}
	istream& Publication::read(istream& in) {
		char tmp_shelfId[SDDS_SHELF_ID_LEN + 1]{};
		char temp[255 + 1]{};
		int tmp_libRef{};
		int tmp_membership{};
		Date tmp_date;
		setEmpty();
		if (conIO(in)) { 
			cout << "Shelf No: ";
			in.getline(tmp_shelfId, SDDS_SHELF_ID_LEN + 1);
			cout << "Title: ";
			if (in) 
			{
			in.getline(temp, 256);
			}
			cout << "Date: ";
			if (in)
			{ 
				in >> tmp_date;
			}

		}
		else { 
			in >> tmp_libRef;
			in.get();
			in.getline(tmp_shelfId, SDDS_SHELF_ID_LEN + 1, '\t');
			in.getline(temp, 256, '\t');
			in >> tmp_membership;
			in >> tmp_date;
		}

		if (!tmp_date) {
			in.setstate(ios::failbit);
		}

		if (in) {
			if (tmp_libRef) P_libRef = tmp_libRef;
		
			P_memb = tmp_membership;
			strcpy(P_shelfID, tmp_shelfId);
			P_title = new char[strlen(temp) + 1];
			strcpy(P_title, temp);
			Date14 = tmp_date;
		}
		return in;
	}
	bool Publication::conIO(std::ios& iostr) const {
		return (&iostr == &cin || &iostr == &cout);
	}
	Publication::~Publication() {
		delete[] P_title;
	}
	Publication::operator bool() const {
		return ((P_title && P_title[0] != '\0') ||
			(P_shelfID && P_shelfID[0] != '\0'));
	}

}





