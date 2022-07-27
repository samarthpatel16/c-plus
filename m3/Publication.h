#ifndef __SDDS__PUBLICATION_H__
#define __SDDS__PUBLICATION_H__

#include "Lib.h"
#include "Streamable.h"
#include "Date.h"
#include <cstring>
namespace sdds
{
    class Publication : public Streamable
    {
        char *m_title;
        char m_shelfId[5];
        int m_membership;
        int m_libRef;
        Date m_date;

    public:
        Publication();
        virtual void set(int member_id);
        // Sets the membership attribute to either zero or a five-digit integer.
        void setRef(int value);
        // Sets the **libRef** attribute value
        void resetDate();
        // Sets the date to the current date of the system.
        virtual char type() const;
        // Returns the character 'P' to identify this object as a "Publication object"
        bool onLoan() const;
        // Returns true is the publication is checkout (membership is non-zero)
        Date checkoutDate() const;
        // Returns the date attribute
        bool operator==(const char *title) const;
        // Returns true if the argument title appears anywhere in the title of the
        // publication. Otherwise, it returns false; (use strstr() function in <cstring>)
        operator const char *() const;
        // Returns the title attribute
        int getRef() const;
        // Returns the libRef attirbute.
        bool conIO(std::ios &ios) const;
        std::ostream &write(std::ostream &os) const;
        std::istream &read(std::istream &istr);
        operator bool() const;
        // Rules of Three
        // Destructor
        ~Publication();
        //  copy constructor
        Publication(const Publication &other);
        // copy assignment operator
        Publication &operator=(const Publication &other);
    };
} // namespace sdds

#endif