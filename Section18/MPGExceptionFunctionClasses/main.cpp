#include <iostream>
#include <string>

using namespace std;

class DivideByZeroException {
};

class NegativeValueException {
};

double calculateMPG(int miles, int gallons) {
    if (gallons == 0) {
        throw DivideByZeroException();
    }

    if (miles < 0 || gallons < 0) {
        throw NegativeValueException();
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
    catch (const DivideByZeroException &ex) {
        cerr << "Sorry, you can't divide by Zero" << endl;
    }
    catch (const NegativeValueException &ex) {
        cerr << "Sorry, one of your parameters is negative" << endl;
    }

    cout << "Bye" << endl;

    return 0;
}
