/*---------------------------------------------------------
Name:        Samarth Sunilkumar Patel
Student ID:  150061208
Seneca Email:sspatel65@myseneca.ca
Section:     NBB
Date:	     6 June,2022
------------------------------------------------------------*/





#ifndef _SDDS_BARCHART_H
#define _SDDS_BARCHART_H

#include "Bar.h"

namespace sdds
{
    // a character pointer to hold the dynamically allocated "title of the chart"
    // a Bar pointer to hold the dynamically allocated array of Bars.
    // a character variable to hold the fill character
    // an integer variable to hold the size of the dynamically allocated array of Bars
    // an integer variable to keep track of the number of added samples to set the Bars.
    class BarChart
    {
        char *m_title;
        Bar *m_bars;
        char m_fill;
        int m_size;
        int m_count;

    public:
        BarChart();
        ~BarChart();
        void setEmpty();
        // a function to return if all the Bars are in a valid state or not.
        bool isValid() const;
        void init(const char *title, int noOfSampels, char fill);
        void add(const char *bar_title, int value);
        void draw() const;
        void deallocate();
    };
} // namespace sdds

#endif