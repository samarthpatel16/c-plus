
/*---------------------------------------------------------
Name:        Samarth Sunilkumar Patel
Student ID:  150061208
Seneca Email:sspatel65@myseneca.ca
Section:     NBB
Date:	     13 June,2022
------------------------------------------------------------*/



#ifndef _SDDS_CLEANERBOT_H
#define _SDDS_CLEANERBOT_H

#include <iostream>
#include <string.h>
#include <iomanip>

namespace sdds
{
    class CleanerBot
    {
        char *m_location;
        double m_battery;
        int m_brush;
        bool m_active;

    public:
        CleanerBot();
        CleanerBot(const char *location, double battery, int brush, bool active);
        CleanerBot(const CleanerBot &other);
        ~CleanerBot();
        void set(const char *location, double battery, int brush, bool active);
        void setLocation(const char *location);
        void setActive(bool active);
        // getters
        const char *getLocation() const;
        double getBattery() const;
        int getBrush() const;
        bool isActive() const;
        bool isValid() const;
        void display() const;
        // assignment operator
        CleanerBot &operator=(const CleanerBot &other);
    };
    int report(CleanerBot *bot, const short num_bots);
    void sort(CleanerBot *bots, const short num_bots);

} // namespace sdds

#endif