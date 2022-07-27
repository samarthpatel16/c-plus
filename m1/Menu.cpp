
/*---------------------------------------------------------
Name:        Samarth Sunilkumar Patel
Student ID:  150061208
Seneca Email:sspatel65@myseneca.ca
Section:     NBB
Date:	     10 July,2022
-----------------------------------------------------------*/

// I have done all the coding by myself and only copied the code that my professor provided to complete my project milestones.




#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <string.h>

using namespace std;
#include "Menu.h"

namespace sdds
{
    MenuItem::MenuItem(const char *name)
    {
        m_name = new char[strlen(name) + 1];
        strcpy(m_name, name);
    }
    MenuItem::~MenuItem()
    {
        delete[] m_name;
    }
    MenuItem::operator bool() const
    {
        return strlen(m_name) > 0;
    }
    ostream &MenuItem::display(ostream &os) const
    {
        if (strlen(m_name) > 0)
            os << m_name;
        return os;
    }
    MenuItem::operator const char *() const
    {
        return m_name;
    }
    Menu::Menu(const char *title) : m_title(title)
    {
        m_numItems = 0;
        m_items = new MenuItem *[MAX_MENU_ITEMS];
        for (int i = 0; i < MAX_MENU_ITEMS; i++)
        {
            m_items[i] = nullptr;
        }
    }
    ostream &Menu::display(ostream &os) const
    {
        os << setfill(' ');
        if (m_numItems != 0)
        {
            displayTitle(os);
            if (m_title)
                os << ":" << endl;
            for (int i = 0; i < m_numItems; i++)
            {
                os << setw(2) << right << i + 1 << "- ";
                m_items[i]->display(os) << endl;
            }
            os << " 0- Exit" << endl
               << "> ";
        }
        return os;
    }
    Menu::~Menu()
    {
        for (int i = 0; i < m_numItems; i++)
        {
            delete m_items[i];
        }
        delete[] m_items;
    }
    ostream &Menu::displayTitle(ostream &os) const
    {
        if (m_title)
            m_title.display(os);
        return os;
    }
    int Menu::run()
    {
        if (m_numItems > 0)
        {
            display(cout);
            int option = -1;
            while (true)
            {
                cin >> option;
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(9999999, '\n');
                    cout << "Invalid Selection, try again: ";
                }
                else if (option >= 0 && option - 1 < m_numItems)
                {
                    return option;
                }
                else
                {
                    cout << "Invalid Selection, try again: ";
                }
            }
            return 0;
        }
        return 0;
    }
    int Menu::operator~()
    {
        return run();
    }
    const char *Menu::operator[](int index) const
    {
        if (m_numItems != 0)
            index = index % m_numItems;
        if (index >= 0 && index < m_numItems)
            return m_items[index]->m_name;
        return nullptr;
    }
    ostream &operator<<(ostream &os, const Menu &menu)
    {
        menu.displayTitle(os);
        return os;
    }
    Menu &Menu::operator<<(const char *menuitemConent)
    {
        if (m_numItems < MAX_MENU_ITEMS)
        {
            m_items[m_numItems] = new MenuItem(menuitemConent);
            m_numItems++;
        }
        return *this;
    }
    Menu::operator int() const
    {
        return m_numItems;
    }
    Menu::operator unsigned int() const
    {
        return m_numItems;
    }
    Menu::operator bool() const
    {
        return m_numItems > 0;
    }
} // namespace sdds
