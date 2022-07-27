
/*---------------------------------------------------------
Name:        Samarth Sunilkumar Patel
Student ID:  150061208
Seneca Email:sspatel65@myseneca.ca
Section:     NBB
Date:	     7 July,2022
------------------------------------------------------------*/



#ifndef SDDS_NUMBERS_H_
#define SDDS_NUMBERS_H_
#include <iostream>
namespace sdds
{
   class Numbers
   {
      double *m_numbers;
      char *m_filename;
      bool m_isOriginal;
      int m_numCount;
      bool isEmpty() const;
      void setEmpty();
      void setFilename(const char *filename);
      void sort();

   public:
      Numbers();
      Numbers(const char *filename);
      // copy constructor
      Numbers(const Numbers &other);
      // copy assignment operator
      Numbers &operator=(const Numbers &other);
      // numberCount()
      int numberCount();
      // load()
      bool load();
      // save();
      void save();
      // Operatro += (adds a number to the array)
      Numbers &operator+=(double num);
      // ostream& display(ostream& ostr) const
      std::ostream &display(std::ostream &ostr) const;
      double average() const;
      double max() const;
      double min() const;
      ~Numbers();
   };
   // ostream& operator<<(ostream& os, const Numbers& N);
   std::ostream &operator<<(std::ostream &os, const Numbers &N);
   // istream& operator>>(istream& istr, Numbers& N);
   std::istream &operator>>(std::istream &istr, Numbers &N);
}
#endif // !SDDS_NUMBERS_H_
