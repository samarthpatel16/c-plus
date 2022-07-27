#define _CRT_SECURE_NO_WARNINGS
#include "Publication.h"
using namespace std;
namespace sdds
{
    Publication::Publication()
    {
        m_title = nullptr;
        m_shelfId[0] = '\0';
        m_membership = 0;
        m_libRef = -1;
    }
    // sets the membership attribute to either zero or a five-digit integer.
    // void set(int member_id);
    void Publication::set(int member_id)
    {
        m_membership = member_id;
    }
    void Publication::setRef(int value)
    {
        m_libRef = value;
    }
    void Publication::resetDate()
    {
        m_date = Date();
    }

    // type()
    // virtual char type()const;
    char Publication::type() const
    {
        return 'P';
    }

    // onLoan()
    bool Publication::onLoan() const
    {
        return m_membership != 0;
    }

    // checkoutDate()
    Date Publication::checkoutDate() const
    {
        return m_date;
    }

    // operator==
    bool Publication::operator==(const char *title) const
    {
        return m_title != nullptr && strstr(m_title, title) != NULL;
    }
    // operator const char *
    Publication::operator const char *() const
    {
        return m_title;
    }
    // getRef()
    int Publication::getRef() const
    {
        return m_libRef;
    }
    // conIO
    bool Publication::conIO(std::ios &ios) const
    {
        // Returns true if the address of the io object is the same as the address of either the cin object or the cout object.
        return &ios == &std::cin || &ios == &std::cout;
    }
    // write
    std::ostream &Publication::write(std::ostream &os) const
    {
        if (conIO(os))
        {
            os << "| " << std::setw(4) << m_shelfId << " | " << std::setw(30) << std::setfill('.') << left << m_title << setfill(' ') << " | ";
            if (m_membership == 0)
            {
                os << " N/A  | ";
            }
            else
            {
                os << m_membership << " | ";
            }
            os << right << m_date << " |";
        }
        else
        {
            os << type() << "\t" << m_libRef << "\t" << m_shelfId << "\t" << m_title << "\t " << m_membership << "\t " << right << m_date;
        }
        return os;
    }

    // read
    std::istream &Publication::read(std::istream &istr)
    {
        // First, clear all the attributes by freeing the memory and setting everything to their default values
        if (m_title != nullptr)
        {
            delete[] m_title;
        }
        m_title = nullptr;
        m_shelfId[0] = '\0';
        m_membership = 0;
        m_libRef = -1;
        m_date = Date();
        char title[2550];
        char shelfId[100] = "\0";
        int membership = 0;
        int libRef = -1;
        ;
        Date date;
        if (conIO(istr))
        {
            //             prompt: "Shelf No: "
            // read the shelf number up to its limit (see Lib.h).
            // if the number is not exactly the length it is supposed to be, set the istr to a fail state manually?

            istr.clear();
            cout << "Shelf No: ";
            istr >> shelfId;
            if (strlen(shelfId) != SDDS_SHELF_ID_LEN)
            {
                istr.setstate(ios::failbit);
            }
            if (!istr.fail())
            {
                if (istr.peek() == '\n')
                    istr.get();
                cout << "Title: ";
                istr.getline(title, 255);
                if (!istr.fail())
                {
                    cout << "Date: ";
                    istr >> date;
                    if (istr.fail())
                    {
                        istr.ignore(1000, '\n');
                    }
                }
                else
                {
                    istr.ignore(1000, '\n');
                    cout << "Date: ";
                }
            }
            else
            {
                cout << "Title: ";
                cout << "Date: ";
                istr.ignore(1000, '\n');
            }
        }
        else
        {
            istr >> libRef >> shelfId;
            // read the title till tab
            if (istr.peek() == '\t')
            {
                istr.get();
            }
            istr.getline(title, 255, '\t');
            if (istr.peek() == '\t')
            {
                istr.get();
            }
            istr >> membership >> date;
        }
        if (date.errCode())
        {
            istr.setstate(ios::failbit);
        }
        if (istr.fail())
        {
        }
        else
        {
            // if the istr is in a good state, set the attributes to the values read.
            m_title = new char[strlen(title) + 1];
            strcpy(m_title, title);
            strcpy(m_shelfId, shelfId);
            m_membership = membership;
            m_libRef = libRef;
            m_date = date;
        }
        return istr;
    }

    // operator bool
    Publication::operator bool() const
    {
        return m_title != nullptr && m_shelfId[0] != '\0';
    }

    // destructor
    Publication::~Publication()
    {
        delete[] m_title;
    }

    // copy constructor
    Publication::Publication(const Publication &other)
    {
        if (m_title != nullptr)
        {
            delete[] m_title;
            m_title = nullptr;
        }
        if (other.m_title != nullptr)
        {
            m_title = new char[strlen(other.m_title) + 1];
            strcpy(m_title, other.m_title);
        }
        else
        {
            m_title = nullptr;
        }
        strcpy(m_shelfId, other.m_shelfId);
        m_membership = other.m_membership;
        m_libRef = other.m_libRef;
        m_date = other.m_date;
    }
    // assignment operator
    Publication &Publication::operator=(const Publication &other)
    {
        if (this != &other)
        {
            if (m_title != nullptr)
            {
                delete[] m_title;
                m_title = nullptr;
            }
            if (other.m_title != nullptr)
            {
                m_title = new char[strlen(other.m_title) + 1];
                strcpy(m_title, other.m_title);
            }
            else
            {
                m_title = nullptr;
            }
            strcpy(m_shelfId, other.m_shelfId);
            m_membership = other.m_membership;
            m_libRef = other.m_libRef;
            m_date = other.m_date;
        }
        return *this;
    }
} // namespace sdds
