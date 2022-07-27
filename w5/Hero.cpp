
/*---------------------------------------------------------
Name:        Samarth Sunilkumar Patel
Student ID:  150061208
Seneca Email:sspatel65@myseneca.ca
Section:     NBB
Date:	     20 June,2022
------------------------------------------------------------*/



#define _CRT_SECURE_NO_WARNINGS
#include "Hero.h"
#include <iostream>
using namespace std;
namespace sdds
{
    // // Default constructor to set a hero to a safe empty state.
    // Hero();
    Hero::Hero()
    {
        m_name[0] = '\0';
        m_powers = nullptr;
        m_numPowers = 0;
        m_powerLevel = 0;
    }
    // // Overloaded constructor with 3 parameters to set the name, list of powers
    // //  and the count of powers a hero have. This constructor will also set/update the powerlevel of a hero.
    // Hero(const char *name, const Power *powers, int numPowers);
    Hero::Hero(const char *name, const Power *powers, int numPowers)
    {
        strncpy(m_name, name, MAX_NAME_LEN);
        m_name[MAX_NAME_LEN] = '\0';
        m_powers = nullptr;
        m_numPowers = numPowers;
        m_powerLevel = 0;
        if (numPowers > 0)
        {
            m_powers = new Power[numPowers];
            for (int i = 0; i < numPowers; i++)
            {
                m_powers[i] = powers[i];
            }
            UpdatePowerLevel();
        }
    }
    // // Display
    // void display() const;
    ostream &Hero::display() const
    {
        // Name: XXXXXXXXXXX<ENDL>
        // List of available powers:
        // powers listed here...
        // powers listed here...
        // powers listed here...
        // powers listed here...
        // Power Level: XXXX<ENDL>
        ostream &os = cout;

        os << "Name: " << m_name << std::endl;
        os << "List of available powers: " << std::endl;
        for (int i = 0; i < m_numPowers; i++)
        {
            os << "  Name: " << m_powers[i].checkName() << ", Rarity: " << m_powers[i].checkRarity() << std::endl;
        }
        os << "Power Level: " << m_powerLevel;
        return os;
    }

    void Hero::UpdatePowerLevel()
    {
        int rarity = 0;
        for (int i = 0; i < m_numPowers; i++)
        {
            rarity += m_powers[i].checkRarity();
        }
        m_powerLevel = rarity * m_numPowers;
    }
    // // overload the += operator
    // Hero &operator+=(int powerLevel);
    Hero &Hero::operator+=(Power &p)
    {
        // Add the power to the hero and update the hero accordingly.
        Power *temp = new Power[m_numPowers + 1];
        for (int i = 0; i < m_numPowers; i++)
        {
            temp[i] = m_powers[i];
        }
        temp[m_numPowers] = p;
        delete[] m_powers;
        m_powers = temp;
        m_numPowers++;
        UpdatePowerLevel();
        return *this;
    }
    // // overload the -= operator
    // Hero &operator-=(int powerLevel);
    Hero &Hero::operator-=(int powerLevel)
    {
        // Subtract the power level from the hero and update the hero accordingly.
        m_powerLevel -= powerLevel;
        return *this;
    }
    // // operator<
    // bool operator<(const Hero &other) const;
    bool Hero::operator<(const Hero &other) const
    {
        return m_powerLevel < other.m_powerLevel;
    }
    // // operator>
    // bool operator>(const Hero &other) const;
    bool Hero::operator>(const Hero &other) const
    {
        return m_powerLevel > other.m_powerLevel;
    }
    // operator>> : This operator will take two parameters. The left parameter is a reference to a power. The right parameter is a reference to a hero.
    // friend Hero &operator>>(Power &power, Hero &hero);
    Hero &operator>>(Power &power, Hero &hero)
    {
        // Add the power to the hero and update the hero accordingly.
        Power *temp = new Power[hero.m_numPowers + 1];
        for (int i = 0; i < hero.m_numPowers; i++)
        {
            temp[i] = hero.m_powers[i];
        }
        temp[hero.m_numPowers] = power;
        delete[] hero.m_powers;
        hero.m_powers = temp;
        hero.m_numPowers++;
        hero.UpdatePowerLevel();
        return hero;
    }
    // operator<< : This operator will take two parameters. The left parameter is a reference to a hero. The right parameter is a reference to a power. This operator will add the power to the hero and update the hero accordingly.
    // friend Hero &operator<<(Hero &hero, Power &power);
    Hero &operator<<(Hero &hero, Power &power)
    {
        // Add the power to the hero and update the hero accordingly.
        Power *temp = new Power[hero.m_numPowers + 1];
        for (int i = 0; i < hero.m_numPowers; i++)
        {
            temp[i] = hero.m_powers[i];
        }
        temp[hero.m_numPowers] = power;
        delete[] hero.m_powers;
        hero.m_powers = temp;
        hero.m_numPowers++;
        hero.UpdatePowerLevel();
        return hero;
    }

    // insertion operator
    std::ostream &operator<<(std::ostream &os, const Hero &hero)
    {
        hero.display();
        return os;
    }

    // destructor
    Hero::~Hero()
    {
        delete[] m_powers;
    }
} // namespace sdds
