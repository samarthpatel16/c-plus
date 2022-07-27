/*---------------------------------------------------------
Name:        Samarth Sunilkumar Patel
Student ID:  150061208
Seneca Email:sspatel65@myseneca.ca
Section:     NBB
Date:	     31-may-2022
------------------------------------------------------------*/




#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <iomanip>
#include "Army.h"

using namespace std;

namespace sdds
{
    //  void setEmpty();
    void Army::setEmpty()
    {
        m_units = 0;
        strcpy(m_nationality, "");
    }

    // void createArmy(const char* country, double pow, int troops);
    void Army::createArmy(const char *country, double pow, int troops)
    {
        if (country != nullptr && strlen(country) > 0 && pow > 0 && troops > 0)
        {
            strncpy(m_nationality, country, MAX_NAME_LEN);
            m_units = troops;
            m_power = pow;
        }
        else
            setEmpty();
    }

    // void updateUnits(int troops)
    void Army::updateUnits(int troops)
    {
        m_units += troops;
        // increment power by 25% of troops
        m_power += (troops * 0.25);
    }

    // const char* checkNationality() const;
    const char *Army::checkNationality() const
    {
        return m_nationality;
    }

    // int checkCapacity() const;
    int Army::checkCapacity() const
    {
        return m_units;
    }

    // double checkPower() const;
    double Army::checkPower() const
    {
        return m_power;
    }

    // bool isEmpty() const;
    bool Army::isEmpty() const
    {
        return m_units == 0;
    }

    // bool isStrongerThan(const Army& army)const;
    bool Army::isStrongerThan(const Army &army) const
    {
        return m_power > army.m_power;
    }

    // void battle( Army& arm1, Army& arm2);
    void battle(Army &arm1, Army &arm2)
    {
        // In battle of Atlantis and Ambrosia, Atlantis is victorious!
        if (arm1.isStrongerThan(arm2))
        {
            cout << "In battle of " << arm1.checkNationality() << " and " << arm2.checkNationality() << ", ";
            cout << arm1.checkNationality() << " is victorious!" << endl;
            arm2.updateUnits(-1 * arm2.checkCapacity() / 2);
        }
        else
        {
            cout << "In battle of " << arm1.checkNationality() << " and " << arm2.checkNationality() << ", ";
            cout << arm2.checkNationality() << " is victorious!" << endl;
            arm1.updateUnits(-1 * arm1.checkCapacity() / 2);
        }
    }

    void displayDetails(const Army *armies, int size)
    {
        std::cout << "Armies reporting to battle: " << std::endl;
        for (int i = 0; i < size; i++)
        {
            if (!armies[i].isEmpty())
            {
                // Nationality: XXXXXXXXXXX, Units Count: XXXX, Power left:<ENDL>
                std::cout << "Nationality: " << armies[i].checkNationality();
                cout << ", Units Count: " << armies[i].checkCapacity();
                cout << ", Power left: " << setprecision(1) << fixed << armies[i].checkPower() << endl;
            }
        }
    }

} // namespace sdds
