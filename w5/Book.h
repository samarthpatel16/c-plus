/*---------------------------------------------------------
Name:        Samarth Sunilkumar Patel
Student ID:  150061208
Seneca Email:sspatel65@myseneca.ca
Section:     NBB
Date:	     17 June,2022
------------------------------------------------------------*/


#ifndef SDDS_BOOK_H_
#define SDDS_BOOK_H_
#include <iostream>
#include "Chapter.h"

namespace sdds
{
    const int MAX_NUM_CHAPTERS = 10;
    const int MAX_BOOK_TITEL = 40;
    const int MAX_AUTHOR_NAME = 20;
    class Book
    {
        char m_title[MAX_BOOK_TITEL + 1];
        char m_author[MAX_AUTHOR_NAME + 1];
        int m_num_chapters;
        int m_num_pages;
        double m_price;
        Chapter m_chapters[MAX_NUM_CHAPTERS];

        void init_book();
        int add_chapter(Chapter *chapter);

    public:
        Book();
        Book(const char *title_);
        Book(const char *title_, const char *author_, double price_);
        void summary(); // Print a book summary
        // postfix ++ operator
        Book &operator++();
        // display
        std::ostream &display(std::ostream &) const;
        // int type cast operator
        operator int() const;
        // bool type cast operator
        operator bool() const;
        // double type cast operator
        operator double() const;
        // const char* type cast operator
        operator const char *() const;
        //  logical not operator overload
        bool operator!() const;
        // += operator overload
        Book &operator+=(Chapter &);
        // -= operator overload
        Book &operator-=(const double &);
        //  insertion operator overload
        friend std::ostream &operator<<(std::ostream &, const Book &);
    };
}
#endif
