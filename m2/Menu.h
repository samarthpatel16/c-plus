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


#ifndef SDDS_MENU_H__
#define SDDS_MENU_H__
#include <iostream>

namespace sdds
{
    const int MAX_MENU_ITEMS = 20;
    class Menu;
    class MenuItem
    {
    private:
        operator bool() const;
        // const char* type conversion operator
        operator const char *() const;
        // displaying the MenuItem
        std::ostream &display(std::ostream &os) const;
        char *m_name;
        MenuItem(const char *name = "");
        // A MenuItem object cannot be copied from or assigned to another MenuItem object.
        // (Copy constructor and Copy assignment are deleted)
        MenuItem(const MenuItem &) = delete;
        MenuItem &operator=(const MenuItem &) = delete;
        // bool type conversion operator
        
    public:
        ~MenuItem();
        friend class Menu;
    };

    class Menu
    {
        MenuItem m_title;
        MenuItem **m_items;
        int m_numItems = 0;

    public:
        Menu(const char *title = "");
        ~Menu();
        int operator~();
        // Menu& Menu::operator<<(const char* menuitemConent);
        Menu &operator<<(const char *menuitemConent);
        // int and unsigned int type conversion operator
        operator int() const;
        operator unsigned int() const;
        // (Copy constructor and Copy assignment are deleted)
        Menu(const Menu &) = delete;
        Menu &operator=(const Menu &) = delete;
        // display title
        std::ostream &displayTitle(std::ostream &os) const;
        // display menu items
        std::ostream &display(std::ostream &os) const;
        // run
        int run();
        // overload operator~
        
        // bool type conversion operator
        operator bool() const;
        // insertion operator
        // std::ostream &operator<<(std::ostream &os) const;
        // Overload the indexing operator to return the const char*
        // of the menu item at the specified index.
        const char *operator[](int index) const;
    };
    std::ostream &operator<<(std::ostream &os, const Menu &menu);
};

#endif