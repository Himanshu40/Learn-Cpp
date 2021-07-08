#include <iostream>

using namespace std;

double calculateMPG(int miles, int gallons) {
    if (gallons == 0) {
        throw 0;
    }

    return static_cast<double>(miles) / gallons;
}

int main() {
    int miles {};
    int gallons {};
    double milesPerGallon {};

    cout << "enter the miles driven: ";
    cin >> miles;
    cout << "enter the gallons used: ";
    cin >> gallons;

    try {
        milesPerGallon = calculateMPG(miles, gallons);
        cout << "Result: " << milesPerGallon << endl;
    }
    catch (int &ex) {
        cout << "Sorry, you can't divide by " << ex << endl;
    }

    cout << "Bye" << endl;

    return 0;
}
