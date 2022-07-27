/*---------------------------------------------------------
Name:        Samarth Sunilkumar Patel
Student ID:  150061208
Seneca Email:sspatel65@myseneca.ca
Section:     NBB
Date:	     17 June,2022
------------------------------------------------------------*/


#ifndef SDDS_CHAPTER_H_
#define SDDS_CHAPTER_H_
#include <iostream>
namespace sdds
{
    const int MAX_CHAPTER_TITLE = 20;
    class Chapter
    {
        char m_title[MAX_CHAPTER_TITLE + 1];
        int m_num_pages;
        int m_num_words;
        unsigned int m_chapter_number;
        void init_chapter();

    public:
        Chapter();
        Chapter(const char *title_);
        Chapter(const char *title_, int chapter_num, int n_pages, int n_words);
        std::ostream &display(std::ostream &) const;
        // int type cast operator
        operator int() const;
        // double type cast operator
        operator double() const;
        // const char* type cast operator
        operator const char *() const;
        // assignment operator overload
        Chapter &operator=(const Chapter &);
        // prefix ++ operator overload
        Chapter &operator++();
        // prefix -- operator overload
        Chapter &operator--();
        // insertion helper operator overload
        friend std::ostream &operator<<(std::ostream &, const Chapter &);
    };
}
#endif
