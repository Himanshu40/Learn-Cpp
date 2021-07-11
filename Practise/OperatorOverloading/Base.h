#ifndef _BASE_H_
#define _BASE_H_
#include <iostream>


class Base {
    private:
        static int objCount;
        int size;
        int *data;
    public:
        Base();
        Base(int size, int value);
        Base(const Base &obj);
        Base(Base &&obj) noexcept;
        ~Base();

        Base &operator=(const Base &rhs);
        Base &operator=(Base &&rhs);

        friend std::ostream &operator<<(std::ostream &os, const Base &rhs);
        friend std::istream &operator>>(std::istream &is, Base &rhs);

        void display() const;
        static int getObjCount();
};


#endif
