
/*---------------------------------------------------------
Name:        Samarth Sunilkumar Patel
Student ID:  150061208
Seneca Email:sspatel65@myseneca.ca
Section:     NBB
Date:	     10 July,2022
------------------------------------------------------------*/

// I have done all the coding by myself and only copied the code that my professor provided to complete my project milestones.





#ifndef SDDS_MENU_H__
#define SDDS_MENU_H__
#include <iostream>
#include <string.h>

namespace sdds
{
    const int MAX_MENU_ITEMS = 20;
    class Menu;
    class MenuItem
    {
    private:
        char *m_name;
        MenuItem(const char *name = "");
        MenuItem &operator=(const MenuItem &) = delete;
        MenuItem(const MenuItem &) = delete;
        operator const char *() const;
        std::ostream &display(std::ostream &os) const;
        operator bool() const;
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
        Menu &operator=(const Menu &) = delete;
        Menu(const Menu &) = delete;
        operator unsigned int() const;
        operator bool() const;
        const char *operator[](int index) const;
        int operator~();
        std::ostream &displayTitle(std::ostream &os) const;
        std::ostream &display(std::ostream &os) const;
        int run();
        Menu &operator<<(const char *menuitemConent);
        operator int() const;
    };
    std::ostream &operator<<(std::ostream &os, const Menu &menu);
};

#endif