#include <iostream>
#include <vector>

using namespace std;

class Move {
        int *data;
    public:
        void setData(int d) {*data = d;};
        int getData() {return *data;};
        Move(int d);
        Move(const Move &src);
        Move(Move &&src) noexcept;
        ~Move();
};

Move::Move(int d) {
    data = new int;
    *data = d;
    cout << "Constructor for: " << d << endl;
}

Move::Move(const Move &src) : Move{*src.data} {
    cout << "Constructor deep copy for: " << *data << endl;
}

Move::Move(Move &&src) noexcept : data{src.data} {
    src.data = nullptr;
    cout << "Move Constructor for: " << *data << endl;
}

Move::~Move() {
    if (data != nullptr) {
        cout << "Destructor freeing data for:" << *data << endl;
    }
    else {
        cout << "Destructor freeing data for nullptr" << endl;
    }

    delete data;
}

void display(Move obj) {
    cout << obj.getData() << endl;
}

int main() {
    vector<Move> vec;

    // // Temporary objects which are unamed so they are R-Values
    vec.push_back(Move{10});
    //vec.push_back(Move{20});
    // vec.push_back(Move{30});
    // vec.push_back(Move{40});

    return 0;
}