#ifndef _DERIVED_H_
#define _DERIVED_H_
#include "Base.h"

class Derived : public Base {
    private:
        int num1;
        int *size1;
    public:
        Derived();
        Derived(int num1, int size1);
        Derived(const Derived &src);
        Derived(Derived &&src) noexcept;
        ~Derived();

        Derived &operator=(const Derived &rhs);
        Derived &operator=(Derived &&rhs) noexcept;

        void display() const;
};


#endif
