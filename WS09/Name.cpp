/*
**********************************************************************************************
Workshop 09 Part 1
Student Name: Vasantharajan Sharmilann
File: Name.cpp


I have completed all the coding by myself I have used our notes and lecture tips in this lab

**********************************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include "Name.h"
using namespace std;
namespace sdds {


Name::Name()
{
	m_valueN = nullptr;
}

Name::Name(const char* name)
{
	if (name != nullptr)
	{
		m_valueN = new char[strlen(name) + 1];
		strcpy(m_valueN, name);
	}
	else {
		m_valueN = nullptr;
	}
}

Name::~Name()
{
	delete[] m_valueN;
	m_valueN = nullptr;


}

Name::Name(const Name& name)
{

	m_valueN = new char[strlen(name.m_valueN) + 1];
	strcpy(m_valueN, name.m_valueN);
}

Name& Name::operator=(const Name& name)
{
	if (m_valueN) {
		delete[] m_valueN;
		m_valueN = nullptr;
	}
	m_valueN = new char[strlen(name.m_valueN) + 1];
	strcpy(m_valueN, name.m_valueN);
	return *this;
	// // O: insert return statement here
}

Name::operator const char* () const
{
	return m_valueN;
}

Name::operator bool() const
{
	return (m_valueN != nullptr);
}

ostream& Name::display(ostream& ostr) const
{
	if (m_valueN != nullptr)
	{
		ostr << m_valueN;
	}
	return ostr;
	// // O: insert return statement here
}

istream& Name::read(istream& istr)
{

	char read1[1024];
	istr.getline(read1, 1024, ' ');
	if (m_valueN)
	{
		delete[] m_valueN;
		m_valueN = nullptr;
	}

	if (istr)
	{
		m_valueN = new char[strlen(read1) + 1];
		strcpy(m_valueN, read1);
	}
	return istr;

	// // O: insert return statement here
}








ostream& operator<<(ostream& out, const Name& name)
{
	name.display(out);
	return out;
	// // O: insert return statement here
}

istream& operator>>(istream& in, Name& name)
{

	name.read(in);
	return in;
	// // O: insert return statement here
}

}