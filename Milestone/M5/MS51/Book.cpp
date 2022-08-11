/*
Student Name: Vasantharajan Sharmilann
SID: 142642180
Milestone 5
File: Book.cpp

All the code done in this milestone is done purely by me, as i have only used resouces from previous lecture and notes.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Book.h"
using namespace std;
namespace sdds {
	Book::Book() {
		a_name = nullptr;
	}
	Book::Book(const Book& Book1) : Book() {
		operator=(Book1);
	}
	Book& Book::operator=(const Book& Book1) {
		if (this != &Book1) {
			Publication::operator=(Book1); 
			if (Book1.a_name && Book1.a_name[0] != '\0') {
				delete[] a_name;
				a_name = new char[strlen(Book1.a_name) + 1];
				strcpy(a_name, Book1.a_name);
			}
		}
		return *this;
	}
	char Book::type() const {
		return 'B';
	}
	ostream& Book::write(ostream& out) const {
		char* author{};
		Publication::write(out);
		if (conIO(out)) {
			out << " ";
			out.width(SDDS_AUTHOR_WIDTH);
			out.setf(ios::left);
			if (strlen(a_name) > SDDS_AUTHOR_WIDTH) 
			{
				author = new char[SDDS_AUTHOR_WIDTH + 1];
				strncpy(author, a_name, SDDS_AUTHOR_WIDTH);
				author[SDDS_AUTHOR_WIDTH] = '\0';
				out << author << " |";
			}
			else {
				out << a_name << " |";
			}
			out.unsetf(ios::left);
		}
		else {
			out << "\t" << a_name;
		}
		delete[] author;
		author = nullptr;
		return out;
	}
	istream& Book::read(istream& in) {
		char author[256]{};
		Publication::read(in);
		delete[] a_name;
		if (conIO(in)) {
			in.ignore();
			cout << "Author: ";
			in.getline(author, 256);
		}
		else {
			in.get();
			in.get(author, 256);
		}
		if (in) {
			a_name = new char[strlen(author) + 1];
			strcpy(a_name, author);
		}
		return in;
	}
	void Book::set(int m_id) {
		Publication::set(m_id);
		Publication::resetDate();
	}
	Book::operator bool() const {
		return ((a_name && a_name[0] != '\0') && Publication::operator bool());
	}
	Book::~Book() {
		delete[] a_name;
	}
}

