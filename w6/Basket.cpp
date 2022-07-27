

/*---------------------------------------------------------
Name:        Samarth Sunilkumar Patel
Student ID:  150061208
Seneca Email:sspatel65@myseneca.ca
Section:     NBB
Date:	     11 july,2022
------------------------------------------------------------*/



#include "Basket.h"

using namespace std;

namespace sdds
{
    // constructor
    Basket::Basket()
    {
        m_fruits = nullptr;
        m_cnt = 0;
        m_price = 0;
    }
    // parameterized constructor
    Basket::Basket(Fruit *fruits, int cnt, double price)
    {
        if (fruits == nullptr || cnt < 0)
        {
            m_fruits = nullptr;
            m_cnt = 0;
            m_price = 0;
        }
        else
        {
            m_fruits = new Fruit[cnt];
            m_cnt = cnt;
            m_price = price;
            for (int i = 0; i < cnt; i++)
            {
                m_fruits[i] = fruits[i];
            }
        }
    }

    // copy constructor
    Basket::Basket(const Basket &basket)
    {
        if (basket.m_fruits == nullptr || basket.m_cnt < 0)
        {
            m_fruits = nullptr;
            m_cnt = 0;
            m_price = 0;
        }
        else
        {
            m_fruits = new Fruit[basket.m_cnt];
            m_cnt = basket.m_cnt;
            m_price = basket.m_price;
            for (int i = 0; i < m_cnt; i++)
            {
                m_fruits[i] = basket.m_fruits[i];
            }
        }
    }

    // copy assignment operator
    Basket &Basket::operator=(const Basket &basket)
    {
        if (this != &basket)
        {
            if (m_fruits != nullptr)
            {
                delete[] m_fruits;
            }
            if (basket.m_fruits == nullptr || basket.m_cnt < 0)
            {
                m_fruits = nullptr;
                m_cnt = 0;
                m_price = 0;
            }
            else
            {
                m_fruits = new Fruit[basket.m_cnt];
                m_cnt = basket.m_cnt;
                m_price = basket.m_price;
                for (int i = 0; i < m_cnt; i++)
                {
                    m_fruits[i] = basket.m_fruits[i];
                }
            }
        }
        return *this;
    }

    // destructor
    Basket::~Basket()
    {
        if (m_fruits != nullptr)
        {
            delete[] m_fruits;
        }
    }

    // setPrice(double price)
    void Basket::setPrice(double price)
    {
        m_price = price;
    }

    // bool conversion operator
    Basket::operator bool() const
    {
        return m_fruits != nullptr && m_cnt > 0;
    }

    // += operator
    Basket &Basket::operator+=(const Fruit &fruit)
    {
        if (m_fruits == nullptr || m_cnt < 0)
        {
            m_fruits = new Fruit[1];
            m_fruits[0] = fruit;
            m_cnt = 1;
            m_price = 0;
        }
        else
        {
            Fruit *temp = new Fruit[m_cnt + 1];
            for (int i = 0; i < m_cnt; i++)
            {
                temp[i] = m_fruits[i];
            }
            temp[m_cnt] = fruit;
            delete[] m_fruits;
            m_fruits = temp;
            m_cnt++;
        }
        return *this;
    }

    // overload the insertion operator (operator<<)
    std::ostream &operator<<(std::ostream &os, const Basket &basket)
    {
        if (basket.m_fruits == nullptr || basket.m_cnt < 0)
        {
            os << "The basket is empty!" << endl;
        }
        else
        {
            // Basket Content:<ENDL>
            // [FRUIT_1_NAME]: [FRUIT_1_QUANTITY]kg<ENDL>
            // [FRUIT_2_NAME]: [FRUIT_2_QUANTITY]kg<ENDL>
            // ...
            // Price: [BASKET_PRICE]<ENDL>
            os << "Basket Content:" << endl;
            for (int i = 0; i < basket.m_cnt; i++)
            {
                os << setw(10) << basket.m_fruits[i].m_name << ": " << setprecision(2) << fixed << basket.m_fruits[i].m_qty << "kg" << endl;
            }
            os << "Price: " << setprecision(2) << fixed << basket.m_price << endl;
        }
        return os;
    }

} // namespace sdds
