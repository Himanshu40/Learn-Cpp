#include <iostream>

using namespace std;

int main() {
    int miles {};
    int gallons {};
    double milesPerGallon {};

    cout << "enter the miles driven: ";
    cin >> miles;
    cout << "enter the gallons used: ";
    cin >> gallons;

    try {
        if (gallons == 0) {
            throw 0;
        }

        milesPerGallon = static_cast<double>(miles) / gallons;
        cout << "Result: " << milesPerGallon << endl;
    }
    catch (int &ex) {
        cout << "Sorry, you can't divide by " << ex << endl;
    }

    cout << "Bye" << endl;

    return 0;
}
