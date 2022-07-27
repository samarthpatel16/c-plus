/*---------------------------------------------------------
Name:        Samarth Sunilkumar Patel
Student ID:  150061208
Seneca Email:sspatel65@myseneca.ca
Section:     NBB
Date:	     13 June,2022
------------------------------------------------------------*/




#define _CRT_SECURE_NO_WARNINGS
#include "CleanerBot.h"

using namespace std;

namespace sdds
{
    CleanerBot::CleanerBot()
    {
        m_location = nullptr;
        m_battery = 0;
        m_brush = 0;
        m_active = false;
    }

    CleanerBot::CleanerBot(const char *location, double battery, int brush, bool active)
    {
        m_location = nullptr;
        m_battery = 0;
        m_brush = 0;
        m_active = false;
        set(location, battery, brush, active);
    }

    CleanerBot::CleanerBot(const CleanerBot &other)
    {
        m_location = nullptr;
        m_battery = 0;
        m_brush = 0;
        m_active = false;
        *this = other;
    }

    CleanerBot::~CleanerBot()
    {
        delete[] m_location;
    }

    void CleanerBot::set(const char *location, double battery, int brush, bool active)
    {
        if (location != nullptr && strlen(location) > 0)
        {
            if (m_location != nullptr)
            {
                delete[] m_location;
            }
            m_location = new char[strlen(location) + 1];
            strcpy(m_location, location);
        }
        m_battery = battery;
        m_brush = brush;
        m_active = active;
    }

    void CleanerBot::setLocation(const char *location)
    {
        if (location != nullptr && strlen(location) > 0)
        {
            if (m_location != nullptr)
            {
                delete[] m_location;
            }
            m_location = new char[strlen(location) + 1];
            strcpy(m_location, location);
        }
    }

    void CleanerBot::setActive(bool active)
    {
        m_active = active;
    }

    const char *CleanerBot::getLocation() const
    {
        return m_location;
    }

    double CleanerBot::getBattery() const
    {
        return m_battery;
    }

    int CleanerBot::getBrush() const
    {
        return m_brush;
    }

    bool CleanerBot::isActive() const
    {
        return m_active;
    }

    bool CleanerBot::isValid() const
    {
        return m_location != nullptr && m_battery > 0 && m_brush > 0;
    }

    void CleanerBot::display() const
    {
        //    | LOCATION   | 99999.9 | 9999999999999999 | NO/YES |
        // Example:
        //     | Kitchen | 88.6 | 5 | YES |
        cout << "| " << setw(10) << left << m_location << " | ";
        cout << setw(7) << right  << setprecision(1) << fixed << m_battery << " | ";
        cout << setw(18) << right << m_brush << " | ";
        if (m_active)
        {
            cout << "YES   ";
        }
        else
        {
            cout << "NO    ";
        }
        cout << " |" << endl;
    }

    CleanerBot &CleanerBot::operator=(const CleanerBot &other)
    {
        if (this != &other)
        {
            if (m_location != nullptr)
            {
                delete[] m_location;
            }
            m_location = new char[strlen(other.m_location) + 1];
            strcpy(m_location, other.m_location);
            m_battery = other.m_battery;
            m_brush = other.m_brush;
            m_active = other.m_active;
        }
        return *this;
    }

    int report(CleanerBot *bot, const short num_bots)
    {
        int to_be_charged = 0;
        int valid_bots = 0;
        cout << "         ------ Cleaner Bots Report -----" << endl
             << "     ---------------------------------------" << endl
             << "| Location   | Battery |  Number of Brushes | Active |" << endl
             << "|------------+---------+--------------------+--------|" << endl;
        for (int i = 0; i < num_bots; i++)
        {
            if (bot[i].isValid())
            {
                if (bot[i].getBattery() < 30)
                {
                    to_be_charged++;
                }
                valid_bots++;
                bot[i].display();
            }
        }
        if (to_be_charged > 0)
        {
            cout << "\n|====================================================|" << endl
                 << "| LOW BATTERY WARNING:                               |" << endl
                 << "|====================================================|" << endl;
        }
        // | Number of robots to be charged: 2                  |
        cout << "| Number of robots to be charged: " << to_be_charged << "                  |" << endl;

        cout << "| Sorting robots based on their available power:     |" << endl
             << "| Location   | Battery |  Number of Brushes | Active |" << endl
             << "|------------+---------+--------------------+--------|" << endl;
        sort(bot, num_bots);
        for (int i = 0; i < num_bots; i++)
        {
            if (bot[i].isValid())
            {
                bot[i].display();
            }
        }
        cout << "|====================================================|" << endl;
        return valid_bots;
    }

    // Sort the bots based on their available power (descending) and invalid bots are last.
    void sort(CleanerBot *bot, const short num_bots)
    {
        for (int i = 0; i < num_bots; i++)
        {
            for (int j = i + 1; j < num_bots; j++)
            {
                if (bot[i].isValid() && bot[j].isValid() && bot[i].getBattery() < bot[j].getBattery())
                {
                    CleanerBot temp( bot[i]);
                    bot[i] = bot[j];
                    bot[j] = temp;
                }
            }
        }
    }
} // namespace sdds
