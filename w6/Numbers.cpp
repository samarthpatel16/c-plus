

/*---------------------------------------------------------
Name:        Samarth Sunilkumar Patel
Student ID:  150061208
Seneca Email:sspatel65@myseneca.ca
Section:     NBB
Date:	     7 July,2022
------------------------------------------------------------*/




#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <fstream>
#include "Numbers.h"
#include "Numbers.h" // intentional
using namespace std;
namespace sdds
{

   Numbers::Numbers()
   {
      setEmpty();
      m_isOriginal = false;
   }

   Numbers::Numbers(const char *filename)
   {
      setEmpty();
      m_isOriginal = true;
      setFilename(filename);
      m_numCount = numberCount();
      if (m_numCount == 0 || !load())
      {
         delete[] m_numbers;
         delete[] m_filename;
         setEmpty();
         m_isOriginal = false;
      }
      else
      {
         sort();
      }
   }

   Numbers::~Numbers()
   {
      save();
      delete[] m_numbers;
      delete[] m_filename;
   }

   bool Numbers::isEmpty() const
   {
      return m_numbers == nullptr;
   }

   void Numbers::setEmpty()
   {
      m_numbers = nullptr;
      m_filename = nullptr;
      m_numCount = 0;
   }

   void Numbers::setFilename(const char *filename)
   {
      delete[] m_filename;
      m_filename = new char[strlen(filename) + 1];
      strcpy(m_filename, filename);
   }

   void Numbers::sort()
   {
      int i, j;
      double temp;
      for (i = m_numCount - 1; i > 0; i--)
      {
         for (j = 0; j < i; j++)
         {
            if (m_numbers[j] > m_numbers[j + 1])
            {
               temp = m_numbers[j];
               m_numbers[j] = m_numbers[j + 1];
               m_numbers[j + 1] = temp;
            }
         }
      }
   }

   double Numbers::average() const
   {
      double aver = 0.0;
      if (!isEmpty())
      {
         for (int i = 0; i < m_numCount; i++)
            aver += m_numbers[i];
         aver = aver / m_numCount;
      }
      return aver;
   }

   
   double Numbers::max() const
   {
      double maxVal = 0.0;
      if (!isEmpty())
      {
         maxVal = m_numbers[0];
         for (int i = 1; i < m_numCount; i++)
            if (maxVal < m_numbers[i])
               maxVal = m_numbers[i];
      }
      return maxVal;
   }


double Numbers::min() const 
   {
      double minVal = 0.0;
      if (!isEmpty())
      {
         minVal = m_numbers[0];
         for (int i = 1; i < m_numCount; i++)
            if (minVal > m_numbers[i])
               minVal = m_numbers[i];
      }
      return minVal;
   }


   // copy constructor
   Numbers::Numbers(const Numbers &other)
   {
      setEmpty();
      m_isOriginal = false;
      *this = other;
   }

   // copy assignment operator
   Numbers &Numbers::operator=(const Numbers &other)
   {
      if (this != &other)
      {
         if (m_numbers != nullptr)
            delete[] m_numbers;
         if (m_filename != nullptr)
            delete[] m_filename;
         m_numCount = 0;
         if (!other.isEmpty())
         {
            m_numbers = new double[other.m_numCount];
            if (other.m_filename != nullptr)
            {
               m_filename = new char[strlen(other.m_filename) + 1];
               strcpy(m_filename, other.m_filename);
            }
            m_numCount = other.m_numCount;
            for (int i = 0; i < m_numCount; i++)
               m_numbers[i] = other.m_numbers[i];
         }
      }
      return *this;
   }

   // numberCount()
   int Numbers::numberCount()
   {
      int num_count = 0;
      ifstream file;
      file.open(m_filename);
      if (file.is_open())
      {
         char cha;
         while (file.get(cha))
         {
            if (cha == '\n')
               num_count++;
         }
         file.close();
      }
      return num_count;
   }

   // load()
   bool Numbers::load()
   {
      int value_count = 0;
      int num = numberCount();
      if (num > 0)
      {
         m_numbers = new double[num];
         ifstream file1;
         file1.open(m_filename);
         file1.clear();
         if (file1.is_open())
         {
            while (!file1.eof())
            {
               file1 >> m_numbers[value_count];
               if (!file1.fail())
                  value_count++;
               else
                  break;
            }
            file1.close();
         }
      }
      sort();
      return m_numCount == value_count;
   }

   // save()
   void Numbers::save()
   {
      ofstream file;
      if (m_filename)
      {
         file.open(m_filename);
         if (file.is_open())
         {
            sort();
            for (int inti = 0; inti < m_numCount; inti++)
               file << m_numbers[inti] << endl;
            file.close();
         }
      }
   }
   // Operatro += (adds a number to the array)
   Numbers &Numbers::operator+=(double numbervalue)
   {
      if (m_numbers == nullptr)
      {
         m_numbers = new double[1];
         m_numbers[0] = numbervalue;
         m_numCount = 1;
      }
      else
      {
         double *temp = new double[m_numCount + 1];
         for (int i = 0; i < m_numCount; i++)
            temp[i] = m_numbers[i];
         temp[m_numCount] = numbervalue;
         delete[] m_numbers;
         m_numbers = temp;
         m_numCount++;

         sort();
      }
      return *this;
   }

   ostream &Numbers::display(ostream &ostr) const
   {
      if (isEmpty())
      {
         ostr << "Empty list";
      }
      else
      {
         ostr << "=========================" << endl;
         if (m_isOriginal)
            ostr << m_filename << endl;
         else
            ostr << "*** COPY ***" << endl;
         for (int i = 0; i < m_numCount; i++)
         {
            ostr << m_numbers[i];
            if (i < m_numCount - 1)
               ostr << ", ";
         }
         ostr << endl;
         ostr << "-------------------------" << endl;
         ostr << "Total of " << m_numCount << " number(s)" << endl;
         ostr << "Largest number:  " << max() << endl;
         ostr << "Smallest number: " << min() << endl;
         ostr << "Average :        " << average() << endl;
         ostr << "=========================";
      }
      return ostr;
   }

   ostream &operator<<(ostream &ostr, const Numbers &numbers)
   {
      return numbers.display(ostr);
   }

   //    std::istream &operator>>(std::istream &istr, Numbers &N);
   istream &operator>>(istream &istr, Numbers &numbers)
   {
      double num;
      istr >> num;
      numbers += num;
      return istr;
   }

}
