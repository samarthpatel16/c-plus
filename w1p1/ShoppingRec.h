/*---------------------------------------------------------
Name:        Samarth Sunilkumar Patel
Student ID:  150061208
Seneca Email:sspatel65@myseneca.ca
Section:     NBB200
Date:	     19-may-2022
------------------------------------------------------------*/




#ifndef SDDS_SHOPPINGREC_H 
#define SDDS_SHOPPINGREC_H

#include <iostream>

#include "Utils.h"

namespace sdds
{
	const int MAX_TITLE_LENGTH = 50;

	struct ShoppingRec {
		char m_title[MAX_TITLE_LENGTH + 1];
		int m_quantity;
		bool m_bought;
	};


	ShoppingRec getShoppingRec();
	void displayShoppingRec(const ShoppingRec* shp);
	void toggleBoughtFlag(ShoppingRec* rec);
	bool isShoppingRecEmpty(const ShoppingRec* shp);
}
#endif
