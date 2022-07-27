/*---------------------------------------------------------
Name:        Samarth Sunilkumar Patel
Student ID:  150061208
Seneca Email:sspatel65@myseneca.ca
Section:     NBB
Date:	     31-may-2022
------------------------------------------------------------*/




#ifndef _SDDS_ARMY_H
#define _SDDS_ARMY_H

namespace sdds
{
    const int MAX_NAME_LEN = 50;

    class Army
    {
        char m_nationality[MAX_NAME_LEN + 1];
        int m_units;
        double m_power = 0;

    public:
        void setEmpty();
        void createArmy(const char *country, double pow, int troops);

        void updateUnits(int troops);
        const char *checkNationality() const;
        int checkCapacity() const;

        double checkPower() const;
        bool isEmpty() const;

        bool isStrongerThan(const Army &army) const;
    };
    void battle(Army &arm1, Army &arm2);
    void displayDetails(const Army *armies, int size);

} // namespace sdds

#endif