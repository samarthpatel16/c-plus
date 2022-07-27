
/*---------------------------------------------------------
Name:        Samarth Sunilkumar Patel
Student ID:  150061208
Seneca Email:sspatel65@myseneca.ca
Section:     NBB
Date:	     21 July,2022
------------------------------------------------------------*/
// Final Project Milestone 2
// LibApp Mockup Module
// File	ms2_tester.cpp
// Version 1.0
// Author	Fardad Soleimanloo


#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <string.h>
using namespace std;
#include "Menu.h"

namespace sdds
{
    // MenuItem functions
    MenuItem::MenuItem(const char *namein)
    {
        m_name = new char[strlen(namein) + 1];
        strcpy(m_name, namein);
    }

    MenuItem::operator bool() const
    {
        return m_name[0] != '\0';
    }
    MenuItem::~MenuItem()
    {
        delete[] m_name;
    }
    
    std::ostream &MenuItem::display(std::ostream &os) const
    {
        if (m_name[0] != '\0')
        {
            os << m_name;
        }
        return os;
    }
    // const char* type conversion operator
    MenuItem::operator const char *() const
    {
        return m_name;
    }
    // Menu functions
    Menu::Menu(const char *title) : m_title(title)
    {
        m_numItems = 0;
        // initialize the menu items to nullptr
        m_items = new MenuItem *[MAX_MENU_ITEMS];
        for (int i = 0; i < MAX_MENU_ITEMS; i++)
        {
            m_items[i] = nullptr;
        } }

    Menu::~Menu()
    {
        for (int k = 0; k < m_numItems; k++)
        {delete m_items[k];}
        delete[] m_items;
    }
    std::ostream &Menu::displayTitle(std::ostream &os) const
    {
        if (bool(m_title))
        {m_title.display(os); }
        return os;}

    std::ostream &Menu::display(std::ostream &os) const
    {
        os << setfill(' ');
        if (m_numItems > 0)
        {
            if (bool(m_title))
            {
                displayTitle(os);
                os << endl;
            }
            for (int k = 0; k < m_numItems; k++)
            {
                os << std::setw(2) << right << k + 1 << "- ";
                m_items[k]->display(os) << endl;
            }
            os << " 0- Exit" << endl;
            os << "> ";
        }
        return os;
    }

    int Menu::run()
    {
        if (m_numItems > 0)
        {
            display(cout);
            int choice = -1;
            while (choice == -1)
            {
                cin >> choice;		
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(9999999, '\n');
                    cout << "Invalid Selection, try again: ";
                    choice = -1;
                    continue;}
		if (choice >= 0 && choice - 1 < m_numItems)
                {return choice;}
                
                else
                { cout << "Invalid Selection, try again: "; choice = -1;} }
            return -1;
        }
        return 0;
    }

    int Menu::operator~()
    {
        return run();
    }

    // Menu &operator<<(const char *menuitemConent);
    Menu &Menu::operator<<(const char *menuitemConent)
    {
        if (m_numItems != MAX_MENU_ITEMS)
        {
            m_items[m_numItems] = new MenuItem(menuitemConent);
            m_numItems=m_numItems+1;
        }
        return *this;}
    // operator int() const;
    Menu::operator int() const
    {
        return m_numItems;
    }
    // operator unsigned int() const;
    Menu::operator unsigned int() const
    {
        return m_numItems;
    }

    // operator bool() const;
    Menu::operator bool() const
    {
        return m_numItems > 0;
    }

    // std::ostream &operator<<(std::ostream &os) const;
    std::ostream &operator<<(std::ostream &os, const Menu &menu)
    {
        os << setfill(' ');
        menu.displayTitle(os);
        return os;
    }

    // const char *operator[](int input) const
    const char *Menu::operator[](int input) const
    {
        
	if (input >= 0 && input < m_numItems)
        {
            return m_items[input]->m_name;
        }
	else if (input >= m_numItems)
        {
            input = input % m_numItems;
        }
        
        return nullptr;
    }

} // namespace sdds
