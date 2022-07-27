/*---------------------------------------------------------
Name:        Samarth Sunilkumar Patel
Student ID:  150061208
Seneca Email:sspatel65@myseneca.ca
Section:     NBB
Date:	     6 June,2022
------------------------------------------------------------*/






#ifndef _SDDS_BAR_H
#define _SDDS_BAR_H

namespace sdds
{
    // Suggested member variables
    // a Cstring to hold a maximum of 20 characters for the title
    // a char variable to hold the fill character
    // an integer variable to hold the sample value of the Bar
    // Suggested public member functions
    // a function to set the Bar to the empty state
    // a function to set the title, fill character and value of the bar and set the function to an invalid state if the value is not acceptable (less than zero or more than 100)
    // a function that returns "if the Bar is valid or not
    class Bar
    {
        char *m_title;
        char m_fill;
        int m_value;
        void setEmpty();
        bool isValid(int value);
        void deallocate();

    public:
        bool m_valid;
        Bar();
        ~Bar();
        void set(const char *title, char fill, int value);
        void draw();
    };
} // namespace sdds

#endif