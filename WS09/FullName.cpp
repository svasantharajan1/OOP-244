/*
**********************************************************************************************
Workshop 09 Part 1
Student Name: Vasantharajan Sharmilann
File: FullName.cpp


I have completed all the coding by myself I have used our notes and lecture tips in this lab

**********************************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#include "Name.h"
#include "FullName.h"
#include <cstring>
using namespace std;
namespace sdds {





	FullName::FullName()
	{
		m_value = nullptr;
	}

	FullName::FullName(const char* name, const char* lastName):Name(name)
	{
		if (lastName)
		{
			m_value = new char[strlen(name) + 1];
			strcpy(m_value, name);
		}
		else
		{
			m_value = nullptr;
		}
	}

	FullName::~FullName()
	{
		delete[] m_value;
		m_value = nullptr;
	}

	FullName::FullName(const FullName& fn) :Name(fn)
	{
		m_value = new char[strlen(fn.m_value) + 1];
		strcpy(m_value, fn.m_value);
	}

	FullName& FullName::operator=(const FullName& fn)
	{
		Name::operator=(fn);
		if (m_value)
		{
			delete[] m_value;
			m_value = nullptr;
		}
		m_value = new char[strlen(fn.m_value) + 1];
		strcpy(m_value, fn.m_value);
		return *this;
		// // O: insert return statement here
	}

	FullName::operator const char* () const
	{

		return m_value;
	}

	FullName::operator bool() const
	{
		return (m_value != nullptr && Name::operator bool());
	}

	std::ostream& FullName::display(std::ostream& ostr) const
	{
		if (*this)
		{
			Name::display(ostr) << " " << m_value;
		}
		return ostr;
		// // O: insert return statement here
	}

	std::istream& FullName::read(std::istream& istr)
	{
		char read1[1024];
		Name::read(istr);
		istr.getline(read1, 1024, '\n');
		if (m_value)
		{
			delete[] m_value;
			m_value = nullptr;
		}

		if (istr)
		{
			m_value = new char[strlen(read1) + 1];
			strcpy(m_value, read1);
		}

		return istr;
		// // O: insert return statement here
	}

}