/*---------------------------------------------------------
Name:        Samarth Sunilkumar Patel
Student ID:  150061208
Seneca Email:sspatel65@myseneca.ca
Section:     NBB200
Date:	     19-may-2022
------------------------------------------------------------*/




#include "ShoppingRec.h"
using namespace std;

namespace sdds {
    const int MAX_QUANTITY_VALUE = 50;

    ShoppingRec getShoppingRec() {
        ShoppingRec R = {};
        cout << "Item name: ";
        readCstr(R.m_title, MAX_TITLE_LENGTH);
        cout << "Quantity: ";
        R.m_quantity = readInt(1, MAX_QUANTITY_VALUE);
        return R;
    }
    void displayShoppingRec(const ShoppingRec* shp) {
        cout << "[" << (shp->m_bought ? 'X' : ' ') << "]" << shp->m_title <<
            " qty:(" << shp->m_quantity << ")" << endl;
    }
    void toggleBoughtFlag(ShoppingRec* rec) {
        rec->m_bought = !rec->m_bought;

    }
    bool isShoppingRecEmpty(const ShoppingRec* shp) {
        return shp->m_title[0] == 0;
    }
}