/*---------------------------------------------------------
Name:        Samarth Sunilkumar Patel
Student ID:  150061208
Seneca Email:sspatel65@myseneca.ca
Section:     NBB
Date:	     19-may-2022
------------------------------------------------------------*/



#ifndef SDDS_SHOPPINGLIST_H 
#define SDDS_SHOPPINGLIST_H
#include "ShoppingRec.h"
#include "File.h"

namespace sdds {

	bool loadList();
	void displayList();
	void removeBoughtItems();
	void removeItem(int index);
	bool saveList();
	void clearList();
	void toggleBought();
	void addItemToList();
	void removeItemfromList();
	bool listIsEmpty();
}


#endif
