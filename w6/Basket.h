
/*---------------------------------------------------------
Name:        Samarth Sunilkumar Patel
Student ID:  150061208
Seneca Email:sspatel65@myseneca.ca
Section:     NBB
Date:	     11 july,2022
------------------------------------------------------------*/



#ifndef _SDDS_BASKET_H_
#define _SDDS_BASKET_H_

#include <iostream>
#include <string>
#include <iomanip>

namespace sdds
{
    struct Fruit
    {
        char m_name[30 + 1]; // the name of the fruit
        double m_qty;        // quantity in kilograms
    };
    class Basket
    {
        // m_fruits: a dynamically allocated array of objects of type Fruit. This is the resource that you must manage.
        // m_cnt: the size of the m_fruits array.
        // m_price: the price of the basket.

        Fruit *m_fruits;
        int m_cnt;
        double m_price;

    public:
        // the default constructor
        Basket();
        // parameterized constructor
        Basket(Fruit *fruits, int cnt, double price);
        // copy constructor
        Basket(const Basket &basket);
        // copy assignment operator
        Basket &operator=(const Basket &basket);
        // destructor
        ~Basket();
        // setPrice(double price
        void setPrice(double price);
        //  bool conversion operator
        operator bool() const;
        //  += operator
        Basket &operator+=(const Fruit &fruit);
        // overload the insertion operator (operator<<)
        friend std::ostream &operator<<(std::ostream &os, const Basket &basket);
    };
}

#endif