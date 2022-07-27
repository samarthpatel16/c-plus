/*---------------------------------------------------------
Name:        Samarth Sunilkumar Patel
Student ID:  150061208
Seneca Email:sspatel65@myseneca.ca
Section:     NBB
Date:	     6 June,2022
------------------------------------------------------------*/







#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <iomanip>

#include "Bar.h"

using namespace std;

namespace sdds
{
    Bar::Bar()
    {
        setEmpty();
    }
    Bar::~Bar()
    {
        deallocate();
    }
    void Bar::setEmpty()
    {
        m_title = nullptr;
        m_fill = ' ';
        m_value = 0;
        m_valid = false;
    }
    void Bar::set(const char *title, char fill, int value)
    {
        deallocate();
        m_title = new char[strlen(title) + 1];
        strcpy(m_title, title);
        m_fill = fill;
        m_value = value;
        m_valid = isValid(value);
    }

    void Bar::draw()
    {
        if (m_valid)
        {
            //    Print the title in 20 characters and fill the spaces with dot characters ('.').
            // print a pipe character ('|')
            // print the fill character to the value divided 2 (ie. 51/2 -> 25)

            cout << setfill('.') << left << setw(20) << m_title << "|";
            for (int i = 0; i < m_value / 2; i++)
            {
                cout << m_fill;
            }
            cout << endl;
            cout << setfill(' ');
        }
    }

    void Bar::deallocate()
    {
        if (m_title)
            delete[] m_title;
        m_title = nullptr;
    }

    bool Bar::isValid(int value)
    {
        return value >= 0 && value <= 100;
    }
} // namespace sdds
