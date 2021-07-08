#include <iostream>
#include <string>

using namespace std;

double calculateMPG(int miles, int gallons) {
    if (gallons == 0) {
        throw 0;
    }

    if (miles < 0 || gallons < 0) {
        throw string {"Negative Value Error"};
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
        cerr << "Sorry, you can't divide by " << ex << endl;
    }
    catch (string &ex) {
        cerr << ex << endl;
    }
    catch (...) {
        cerr << "Everything is handled" << endl;
    }

    cout << "Bye" << endl;

    return 0;
}
