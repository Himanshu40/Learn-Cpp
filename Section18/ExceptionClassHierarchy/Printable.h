#ifndef _I_PRINTABLE_H_
#define _I_PRINTABLE_H_
#include <iostream>


class Printable {
        friend std::ostream &operator<<(std::ostream &os, const Printable &rhs);
    public:
        virtual void print(std::ostream &os) const = 0;
        virtual ~Printable() = default;
};


#endif
