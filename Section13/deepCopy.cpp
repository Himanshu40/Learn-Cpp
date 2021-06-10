#include <iostream>

using namespace std;

class Deep {
        int *data;
    public:
        Deep(int d);
        Deep(const Deep &src);
        int getData();
        void setData(int dataVal);
        ~Deep();
};

Deep::Deep(int d) {
    data = new int;
    *data = d;
}

// User defined Constructor so that instead of copying the pointer
// we are copying the data of the pointer which is pointing to
Deep::Deep(const Deep &src) : Deep {*src.data} {
    cout << *src.data << endl;
    cout << "Copy construtor - Deep" << endl;
}

int Deep::getData() {
    return *data;
}

void Deep::setData(int dataVal) {
    *data = dataVal;
}

Deep::~Deep() {
    delete data;
    cout << "Destructor is called" << endl;
}

void displayDeep(Deep s) {
    cout << s.getData() << endl;
}

int main() {
    Deep obj1{100};
    displayDeep(obj1);

    /*Deep obj2{obj1};
    obj2.setData(1000);*/

    return 0;
}