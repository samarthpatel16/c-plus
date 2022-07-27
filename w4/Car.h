/*---------------------------------------------------------
Name:        Samarth Sunilkumar Patel
Student ID:  150061208
Seneca Email:sspatel65@myseneca.ca
Section:     NBB
Date:	     9 June,2022
------------------------------------------------------------*/




#ifndef _SDDA_CAR_H
#define _SDDA_CAR_H

#include <iostream>
#include <string.h>
#include <iomanip>

namespace sdds
{
    class Car
    {
        char *m_type = nullptr;
        char *m_brand = nullptr;
        char *m_model = nullptr;
        int m_year;
        int m_code;
        double m_price;
        void resetInfo();

    public:
        Car();
        Car(const char *type, const char *brand, const char *model, int year = 2022, int code = 100, double price = 1);
        ~Car();
        Car &setInfo(const char *type, const char *brand, const char *model, int year, int code, double price);
        void printInfo() const;
        bool isValid() const;
        bool isSimilarTo(const Car &car) const;
    };
    bool has_similar(const Car car[], const int num_cars);
    bool has_invalid(const Car car[], const int num_cars);
    void print(const Car car[], const int num_cars);

}

#endif