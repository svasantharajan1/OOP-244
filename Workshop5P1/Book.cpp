#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Book.h"
#include "Chapter.h"

using namespace std;
namespace sdds {
	void Book::init_book()
	{
		m_title[0] = '\0';
		m_author[0] = '\0';
		m_num_chapters = 0;
		m_num_pages = 0;
	}

	Book::Book()
	{
		init_book();
	}

	Book::Book(const char* title_)
	{
		init_book();
		strcpy(m_title, title_);
	}

	Book::Book(const char* title_, const char* author_, double price_)
	{
		init_book();
		strcpy(m_title, title_);
		strcpy(m_author, author_);
		m_price = price_;
	}


	int Book::add_chapter(Chapter* chapter)
	{
		m_chapters[m_num_chapters] = *chapter;
		this->operator++(0);
		m_num_pages += chapter->pageNo();
		return 1;
	}

	Book Book::operator++(int)
	{
		Book b = *this;
		m_num_chapters++;
		return b;
	}

	std::ostream& Book::displayBook(std::ostream&out) const
	{
		// TODO: insert return statement here
		out << "Title:'" << m_title << "'" << endl;
		out << "Author: '" << m_author << "'" << endl;
		for (int i = 0; i < MAX_NUM_CHAPTERS; i++)
		{
			if (m_chapters[i].pageNo() > 0)
			{
				m_chapters[i].display(out);
			}

		}
		return out;
	}

	Book::operator int() const
	{
		return m_num_chapters;
	}

	Book::operator bool() const
	{
		bool answer = false;
		int flag = -1;
		if (m_title[0] != '\0' && m_author[0] != '\0' && m_num_chapters > 0)
		{
			for (int i = 0; i < m_num_chapters && flag == -1; i++)
			{
				if (m_chapters[i].pageNo() > 0)
				{
					answer = true;
					flag = 1;
				}
			}
		}
		return answer;
	}

	Book::operator double() const
	{
		return m_price;
	}

	Book::operator const char* () const
	{
		return m_title;
	}

	bool Book::operator!() const
	{
		bool answer = true;
		int flag = -1;
		if (m_title[0] != '\0' && m_author[0] != '\0' && m_num_chapters > 0)
		{
			for (int i = 0; i < m_num_chapters && flag == -1; i++)
			{
				if (m_chapters[i].pageNo() > 0)
				{
					answer = false;
					flag = 0;
				}
			}
		}
		return answer;
	}

	Book& Book::operator+=(Chapter chap)
	{
		// TODO: insert return statement here
		add_chapter(&chap);
		return *this;
	}

	Book& Book::operator-=(double discount)
	{
		// TODO: insert return statement here
		m_price -= discount;
		return *this;
	}


	std::ostream& operator<<(std::ostream& ans, const Book& book)
	{
		// TODO: insert return statement here

		return book.displayBook(ans);
	}

	void Book::summary()
	{
		cout.setf(ios::left);
		cout << "| ";
		cout.width(MAX_BOOK_TITEL);
		cout << m_title << " | ";
		cout.width(MAX_AUTHOR_NAME);
		cout << m_author << " | ";
		cout.width(3);
		cout << m_num_chapters << "  ";
		cout.width(4);
		cout << m_num_pages << " | ";
		cout.width(6);
		cout << m_price << " |" << endl;
	}

}