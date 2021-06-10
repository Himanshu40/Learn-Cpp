#include <iostream>

using namespace std;

class Shallow {
        int *data;
    public:
        Shallow(int d);
        Shallow(const Shallow &src);
        int getData();
        void setData(int dataVal);
        ~Shallow();
};

Shallow::Shallow(int d) {
    data = new int;
    *data = d;
}

// Compiler generated copy constructor if we don't provide this one & also Member wise copy
Shallow::Shallow(const Shallow &src) 
        : data{src.data} {
    cout << src.data << endl;
    cout << "Copy construtor - shallow" << endl;
}

int Shallow::getData() {
    return *data;
}

void Shallow::setData(int dataVal) {
    *data = dataVal;
}

Shallow::~Shallow() {
    delete data;
    cout << "Destructor is called" << endl;
}

void displayShallow(Shallow s) {
    cout << s.getData() << endl;
}

int main() {
    Shallow obj1{100};
    displayShallow(obj1); //Here data memory is freed for s which also effects obj1

    /*Shallow obj2{obj1};
    obj2.setData(1000);*/

    return 0;
}