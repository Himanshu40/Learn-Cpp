#include <iostream>
#include "I_Printable.h"

std::ostream &operator<<(std::ostream &os, const I_Printable &rhs) {
    rhs.print(os);

    return os;
}
