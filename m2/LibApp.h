/*---------------------------------------------------------
Name:        Samarth Sunilkumar Patel
Student ID:  150061208
Seneca Email:sspatel65@myseneca.ca
Section:     NBB
Date:	     21 July,2022
------------------------------------------------------------*/



#ifndef __SDDS__LIBAPP_H__
#define __SDDS__LIBAPP_H__

#include <iostream>
#include <iomanip>
#include <string.h>
#include "Menu.h"

namespace sdds
{
    class LibApp
    {
	void returnPub(); /*  Calls the search() method.
                              prints "Returning publication"<NEWLINE>
                              prints "Publication returned"<NEWLINE>
                              sets m_changed to true;
                          */
        bool m_changed;
        Menu m_mainMenu;
        Menu m_exitMenu;
        bool confirm(const char *message);
	void newPublication();
        void removePublication();
        void checkOutPub();
        void exitMessage();
        void load();   // prints: "Loading Data"<NEWLINE>
        void save();   // prints: "Saving Data"<NEWLINE>
        void search(); // prints: "Searching for publication"<NEWLINE>

        
        

    public:
        LibApp();
        ~LibApp();
        void run();
    };
} // namespace sdds

#endif