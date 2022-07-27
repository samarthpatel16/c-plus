/*---------------------------------------------------------
Name:        Samarth Sunilkumar Patel
Student ID:  150061208
Seneca Email:sspatel65@myseneca.ca
Section:     NBB
Date:	     17 June,2022
------------------------------------------------------------*/


#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iomanip>
#include "Book.h"

using namespace std;
namespace sdds
{
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

	Book::Book(const char *title_)
	{
		init_book();
		strcpy(m_title, title_);
	}

	Book::Book(const char *title_, const char *author_, double price_)
	{
		init_book();
		strcpy(m_title, title_);
		strcpy(m_author, author_);
		m_price = price_;
	}

	// Print a book summary
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

	// int add_chapter(Chapter *chapter);
	int Book::add_chapter(Chapter *chapter)
	{
		if (m_num_chapters < MAX_NUM_CHAPTERS)
		{
			m_chapters[m_num_chapters] = *chapter;
			m_num_chapters++;
			m_num_pages += int(*chapter);
			return m_num_chapters;
		}
		return -1;
	}
	// postfix ++ operator
	Book &Book::operator++()
	{
		m_num_chapters++;
		return *this;
	}
	// // display
	// std::ostream &display(std::ostream &) const;
	std::ostream &Book::display(std::ostream &os) const
	{
		// Title:'Object Oriented Programming using C++'
		// Author: 'Bjarne Stroustrup'
		// | Chapter 1  | Introduction         |
		// | Chapter 2  | Language History     |
		// | Chapter 3  | Varibales            |
		// | Chapter 4  | Flow Control         |

		os << "Title:'" << m_title << "'" << endl;
		os << "Author: '" << m_author << "'" << endl;
		for (int i = 0; i < m_num_chapters; i++)
		{
			os << "| Chapter " << i + 1 << "  | ";
			//  Introduction
			// use char * operator to get the chapter title
			//const char *a = static_cast<const char *>(m_chapters[i]);
			os << setw(20) << left << static_cast<const char *>(m_chapters[i]) << " |" << endl;
		}
		return os;
	}
	// // int type cast operator
	// operator int() const;
	Book::operator int() const
	{
		return m_num_chapters;
	}
	// // bool type cast operator
	// operator bool() const;
	Book::operator bool() const
	{
		if (m_title == nullptr && m_title[0] != '\0')
			return false;
		if (m_author == nullptr && m_author[0] != '\0')
			return false;
		if (m_num_chapters == 0)
			return false;
		if (m_num_pages == 0)
			return false;
		return true;
	}
	// // double type cast operator
	// operator double() const;
	Book::operator double() const
	{
		return m_price;
	}
	// // const char* type cast operator
	// operator const char *() const;
	Book::operator const char *() const
	{
		return m_title;
	}
	// //  logical not operator overload
	// bool operator!() const;
	bool Book::operator!() const
	{
		return !bool(*this);
	}
	// // += operator overload
	// Book &operator+=(const Chapter &);
	Book &Book::operator+=(Chapter &chapter)
	{
		add_chapter(&chapter);
		return *this;
	}
	// // -= operator overload
	// Book &operator-=(const Chapter &);
	Book &Book::operator-=(const double &price)
	{
		m_price -= price;
		return *this;
	}
	// //  insertion operator overload
	// std::ostream &operator<<(std::ostream &, const Book &);
	std::ostream &operator<<(std::ostream &os, const Book &book)
	{
		book.display(os);
		return os;
	}
}
