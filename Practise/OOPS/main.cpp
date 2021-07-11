#include <iostream>
#include <vector>

using namespace std;

class Base {
    private:
        static int objCount;
        int size;
        int *data;
    public:
        Base() : Base {0, 0} {
            cout << "No-args constructor called for " << *data << endl;
        }
        
        Base(int size, int value) : size {size} {
            data =  new int;
            *data = value;
            ++objCount;

            cout << "Parameterized constructor called for " << *data << endl;
        }

        Base(const Base &obj) : Base {obj.size, *obj.data} {
            cout << "Deep copy constructor called for " << *data << endl;
        }

        Base(Base &&obj) noexcept : size {obj.size}, data {obj.data} {
            obj.data = nullptr;

            cout << "Move constructor called for " << *data << endl;
        }

        ~Base() {
            if (data != nullptr) {
                cout << "Destructor called for " << *data << endl;
                --objCount;

            }
            else {
                cout << "Destructor called for nullptr" << endl;
            }

            delete data;
        }

        void display() const {
            cout << "Size = " << size << ", Data = " << *data << endl;
        }

        static int getObjCount() {
            return objCount;
        }
};

int Base::objCount {0};

void displayObjCount() {
    cout << "Total object created = " << Base::getObjCount() << endl;
}

int main() {
    Base b1;
    b1.display();


    Base b2 {5, 10};
    b2.display();

    Base b3 {b2};
    b3.display();

    vector<Base> vec;

    vec.push_back(Base {6, 11});
    vec.push_back(Base {7, 12});

    const Base b4;
    b4.display();

    displayObjCount();
    
    return 0;
}
