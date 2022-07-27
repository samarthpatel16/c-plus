
/*---------------------------------------------------------
Name:        Samarth Sunilkumar Patel
Student ID:  150061208
Seneca Email:sspatel65@myseneca.ca
Section:     NBB
Date:	     20 June,2022
------------------------------------------------------------*/



#ifndef SDDS_HERO_H
#define SDDS_HERO_H
#include <iostream>
#include <string.h>
#include "Power.h"

namespace sdds
{
    const int MAX_NAME_LEN = 50;
    class Hero
    {
        // Declare an array to hold the name of a hero, not exceeding MAX_NAME_LEN characters.
        // Declare a Pointer of type Power that will hold a dynamic set of powers a hero may have.
        // Declare an integer variable for the number of powers a hero may have.
        // Declare a integer variable for the power level of a hero.

        char m_name[MAX_NAME_LEN + 1];
        Power *m_powers;
        int m_numPowers;
        int m_powerLevel;
        void UpdatePowerLevel();

    public:
        // Default constructor to set a hero to a safe empty state.
        Hero();
        // Overloaded constructor with 3 parameters to set the name, list of powers
        //  and the count of powers a hero have. This constructor will also set/update the powerlevel of a hero.
        Hero(const char *name, const Power *powers, int numPowers);
        ~Hero();
        // Display
        std::ostream &display() const;
        // overload the += operator
        Hero &operator+=(Power &power);
        // overload the -= operator
        Hero &operator-=(int powerLevel);
        // operator<
        bool operator<(const Hero &other) const;
        // operator>
        bool operator>(const Hero &other) const;
        // operator>> : This operator will take two parameters. The left parameter is a reference to a power. The right parameter is a reference to a hero.
        friend Hero &operator>>(Power &power, Hero &hero);
        // operator<< : This operator will take two parameters. The left parameter is a reference to a hero. The right parameter is a reference to a power. This operator will add the power to the hero and update the hero accordingly.
        friend Hero &operator<<(Hero &hero, Power &power);
        // oveload insertion operator
        friend std::ostream &operator<<(std::ostream &os, const Hero &hero);
    };
}

#endif