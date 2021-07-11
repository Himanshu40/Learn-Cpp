#ifndef _BASE_H_
#define _BASE_H_


class Base {
    private:
        int num;
        int *size;
    public:
        Base();
        Base(int num, int sizeValue);
        Base(const Base &src);
        Base(Base &&src) noexcept;
        ~Base();

        Base &operator=(const Base &rhs);
        Base &operator=(Base &&rhs) noexcept;

        void display() const;
};


#endif
