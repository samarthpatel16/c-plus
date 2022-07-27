

/*---------------------------------------------------------
Name:        Samarth Sunilkumar Patel
Student ID:  150061208
Seneca Email:sspatel65@myseneca.ca
Section:     NBB
Date:	     7 July,2022
------------------------------------------------------------*/




// Final Project Milestone 1
// Date Tester program
// File	dateTester.cpp
// Version 1.0
// Author	Fardad Soleimanloo
// Description
// This programs tests the Date class and is not for submission
//
// When testing before submission: DO NOT MODIFY THIS FILE IN ANY WAY
//
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;
#include "Date.h"
using namespace sdds;

// A fool proof Date entry from console
Date getDate();

int main()
{
   Date
       D1, // daysSince0001_1_1 to be recieved from console
       D2(2022, 6, 20);

   D1 = getDate();
   cout << "Your Entry: " << D1 << endl;
}

Date getDate()
{
   Date D;
   do
   {
      cin >> D;                                                       // get D from console
   } while (!D && cout << D.dateStatus() << ", Please try again > "); // if D is invalid, print error message and loop
   return D;
}
