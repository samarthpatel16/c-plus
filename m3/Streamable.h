
#ifndef __SDDS__STREAMABLE_H__
#define __SDDS__STREAMABLE_H__
#include <iostream>
#include <string>
#include <iomanip>
#include <string.h>

namespace sdds
{
    class Streamable
    {
    public:
        virtual std::ostream &write(std::ostream &os) const = 0;
        virtual std::istream &read(std::istream &is) = 0;
        // conIO
        virtual bool conIO(std::ios &ios) const = 0;
        // Boolean conversion operator overload (pure virtual)
        virtual operator bool() const = 0;
        // destructor
        virtual ~Streamable() = default;
        // Insertion operator overload
         friend std::ostream &operator<<(std::ostream &os, const Streamable &obj)
        {
            if (obj)
            {
                obj.write(os);
            }
            return os;
        }
        // Extraction operator overload
         friend std::istream &operator>>(std::istream &is, Streamable &obj)
        {
            return obj.read(is);
        }
    };
}
#endif