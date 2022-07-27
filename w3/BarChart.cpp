
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

#include "BarChart.h"

using namespace std;

namespace sdds
{
    BarChart::BarChart()
    {
        m_title = nullptr;
        m_bars = nullptr;
        m_fill = ' ';
        m_size = 0;
        m_count = 0;
    }

    BarChart::~BarChart()
    {
        deallocate();
    }

    void BarChart::setEmpty()
    {
        deallocate();
        m_title = nullptr;
        m_bars = nullptr;
        m_fill = ' ';
        m_size = 0;
        m_count = 0;
    }

    bool BarChart::isValid() const
    {
        if (m_size != m_count)
            return false;
        for (int i = 0; i < m_count; i++)
        {
            if (!m_bars[i].m_valid)
            {
                return false;
            }
        }
        return true;
    }

    void BarChart::init(const char *title, int noOfSampels, char fill)
    {
        setEmpty();
        if (title != nullptr && title[0] != '\0' && noOfSampels > 0 && fill != '\0')
        {

            m_title = new char[strlen(title) + 1];
            strcpy(m_title, title);
            m_bars = new Bar[noOfSampels];
            m_fill = fill;
            m_size = noOfSampels;
            m_count = 0;
        }
    }

    void BarChart::add(const char *bar_title, int value)
    {
        if (bar_title != nullptr && bar_title[0] != '\0' && value > 0)
        {
            if (m_count < m_size)
            {
                m_bars[m_count].set(bar_title, m_fill, value);
                m_count++;
            }
        }
    }

    void BarChart::draw() const
    {
        if (isValid())
        {
            // prints the title of the Chart and goes to new line
            // prints 71 dashes ('-') and goes to a new line
            // prints all the Bars
            // prints 71 dashes ('-') and goes to a new line Otherwise,

            cout << m_title << endl;
            cout << string(71, '-') << endl;
            for (int i = 0; i < m_count; i++)
            {
                m_bars[i].draw();
            }
            cout << string(71, '-') << endl;
        }
        else
        {
            // Invalid Chart!
            cout << "Invalid Chart!" << endl;
        }
    }

    void BarChart::deallocate()
    {
        if (m_title != nullptr)
        {
            delete[] m_title;
            m_title = nullptr;
        }
        if (m_bars != nullptr)
        {
            delete[] m_bars;
            m_bars = nullptr;
        }
    }
} // namespace sdds
