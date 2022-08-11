#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include "Chapter.h"
using namespace std;

namespace sdds {
	void Chapter::init_chapter()
	{
		m_title[0] = '\0';
		m_num_pages = 0;
		m_num_words = 0;
		m_chapter_number = 0;
	}
	Chapter::Chapter()
	{
		init_chapter();
	}

	Chapter::Chapter(const char* title_)
	{
		init_chapter();
		strcpy(m_title, title_);
	}
	Chapter::Chapter(const char* title_, int chapter_num, int n_pages, int n_words)
	{
		strcpy(m_title, title_);
		m_chapter_number = chapter_num;
		m_num_pages = n_pages;
		m_num_words = n_words;
	}
	Chapter::operator int() const
	{
		return m_num_pages;
	}
	Chapter::operator double() const
	{
		return ((double)m_num_words / m_num_pages);
	}
	Chapter::operator const char* () const
	{
		return m_title;
	}
	Chapter& Chapter::operator=(const Chapter& chap)
	{
		strcpy(m_title, chap.m_title);
		m_num_pages = chap.m_num_pages;
		m_num_words = chap.m_num_words;
		m_chapter_number = chap.m_chapter_number;
		return *this;
	}
	Chapter& Chapter::operator++()
	{
		// TODO: insert return statement here

		m_num_pages++;
			return *this;

	}
	Chapter& Chapter::operator--()
	{
		// TODO: insert return statement here

		m_num_pages--;
		return *this;
	}
	
	std::ostream& operator<<(std::ostream& ans, const Chapter& cc)
	{
		cc.display(ans);
		return ans;
		// TODO: insert return statement here
	}
	int Chapter::pageNo() const
	{
		return m_num_pages;
	}

	ostream& Chapter::display(std::ostream& os)const
	{
		cout.setf(std::ios::left);
		os << "| Chapter ";
		os.width(2);
		os << m_chapter_number << " | ";
		os.width(MAX_CHAPTER_TITLE);
		os << m_title << " |" << endl;
		return os;
	}


}
