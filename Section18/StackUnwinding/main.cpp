#include <iostream>

using namespace std;

void funcA();
void funcB();
void funcC();

void funcA() {
    cout << "Starting function A" << endl;
    funcB();
    cout << "Ending function A" << endl;
}

void funcB() {
    cout << "Starting function B" << endl;

    try {
        funcC();
    }
    catch (int &ex) {
        cerr << "Caught error in function B" << endl;
    }

    cout << "Ending function B" << endl;
}

void funcC() {
    cout << "Starting function C" << endl;
    throw 100;
    cout << "Ending function C" << endl;
}

int main() {
    cout << "Starting main" << endl;

    try {
        funcA();
    }
    catch (int &ex) {
        cerr << "caught error in main" << endl;
    }

    cout << "Finishing main" << endl;

    return 0;
}
