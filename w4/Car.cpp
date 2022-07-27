
/*---------------------------------------------------------
Name:        Samarth Sunilkumar Patel
Student ID:  150061208
Seneca Email:sspatel65@myseneca.ca
Section:     NBB
Date:	     9 June,2022
------------------------------------------------------------*/



#define _CRT_SECURE_NO_WARNINGS
#include "Car.h"

using namespace std;

namespace sdds
{
    void Car::resetInfo()
    {
        if (m_type != nullptr)
        {
            delete[] m_type;
        }
        if (m_brand != nullptr)
        {
            delete[] m_brand;
        }
        if (m_model != nullptr)
        {
            delete[] m_model;
        }
        m_type = nullptr;
        m_brand = nullptr;
        m_model = nullptr;
        m_year = 0;
        m_code = 0;
        m_price = 0;
    }

    Car::Car()
    {
        resetInfo();
    }

    Car::Car(const char *type, const char *brand, const char *model, int year, int code, double price)
    {
        resetInfo();
        if (type != nullptr && strcmp(type, "") != 0 && brand != nullptr && strcmp(brand, "") != 0 && model != nullptr && strcmp(model, "") != 0 && year >= 1990 && code > 99 && code < 1000 && price > 0)
        {
            setInfo(type, brand, model, year, code, price);
        }
        else
        {
            resetInfo();
        }
    }
    Car::~Car()
    {
        if (m_type != nullptr)
        {
            delete[] m_type;
        }
        if (m_brand != nullptr)
        {
            delete[] m_brand;
        }
        if (m_model != nullptr)
        {
            delete[] m_model;
        }
    }

    Car &Car::setInfo(const char *type, const char *brand, const char *model, int year, int code, double price)
    {
        if (type != nullptr && strcmp(type, "") != 0 && brand != nullptr && strcmp(brand, "") != 0 && model != nullptr && strcmp(model, "") != 0 && year >= 1990 && code > 99 && code < 1000 && price > 0)
        {
            if (m_type != nullptr)
            {
                delete[] m_type;
            }
            if (m_brand != nullptr)
            {
                delete[] m_brand;
            }
            if (m_model != nullptr)
            {
                delete[] m_model;
            }
            m_type = new char[strlen(type) + 1];
            strcpy(m_type, type);
            m_brand = new char[strlen(brand) + 1];
            strcpy(m_brand, brand);
            m_model = new char[strlen(model) + 1];
            strcpy(m_model, model);
            m_year = year;
            m_code = code;
            m_price = price;
        }
        else
        {
            resetInfo();
        }
        return *this;
    }

    // void printInfo() const;
    void Car::printInfo() const
    {
        cout << "| " << setw(10) << left << m_type
             << " | " << setw(16) << left << m_brand
             << " | " << setw(16) << left << m_model
             << " | " << m_year
             << " |  " << m_code
             << " | " << setw(9) << right << setprecision(2) << fixed << m_price
             << " |" << endl;
    }

    // isValid
    bool Car::isValid() const
    {
        return m_type != nullptr && strcmp(m_type, "") != 0 && m_brand != nullptr && strcmp(m_brand, "") != 0 && m_model != nullptr && strcmp(m_model, "") != 0 && m_year >= 1990 && m_code > 99 && m_code < 1000 && m_price > 0;
    }

    // isSimilarTo
    bool Car::isSimilarTo(const Car &car) const
    {
        if (isValid() && car.isValid())
            return strcmp(m_type, car.m_type) == 0 && strcmp(m_brand, car.m_brand) == 0 && strcmp(m_model, car.m_model) == 0 && m_year == car.m_year;
        return false;
    }

    // has_similar
    bool has_similar(const Car car[], const int num_cars)
    {
        bool has_similar = false;
        for (int i = 0; i < num_cars; i++)
        {
            for (int j = i + 1; j < num_cars; j++)
            {
                if (car[i].isSimilarTo(car[j]))
                {
                    has_similar = true;
                    return has_similar;
                }
            }
        }
        return has_similar;
    }

    // has_invalid
    bool has_invalid(const Car car[], const int num_cars)
    {
        bool has_invalid = false;
        for (int i = 0; i < num_cars; i++)
        {
            if (!car[i].isValid())
            {
                has_invalid = true;
                return has_invalid;
            }
        }
        return has_invalid;
    }
    // print
    void print(const Car car[], const int num_cars)
    {
        for (int i = 0; i < num_cars; i++)
        {
            if (car[i].isValid())
            {
                car[i].printInfo();
            }
        }
    }

} // namespace sdds
