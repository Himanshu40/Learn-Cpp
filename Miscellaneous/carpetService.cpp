#include <iostream>

using namespace std;

const unsigned int smallRoomCharge {25};
const unsigned int bigRoomCharge {35};
const float serviceTaxCharge {0.06};

unsigned int calcService(unsigned int smallRoom, unsigned int bigRoom) {
    return ((smallRoom * smallRoomCharge) + (bigRoom * bigRoomCharge));
}

float serviceTax(unsigned int cost) {
    return (serviceTaxCharge * cost);
} 

int main() {
    cout << "Hello, welcome to Frank's Carpet Cleaning Service\n\n";

    unsigned int bigRoom, smallRoom;

    cout << "How many small rooms would you like cleaned? ";
    cin >> smallRoom;

    cout << "How many big rooms would you like cleaned? ";
    cin >> bigRoom;

    cout << "\nEstimate for carpet cleaning service\n";
    cout << "Number of small rooms: " << smallRoom << "\n";
    cout << "Number of big rooms: " << bigRoom << "\n";
    cout << "Price per small rooms: $" << smallRoomCharge << "\n";
    cout << "Price per big rooms: $" << bigRoomCharge << "\n";

    unsigned int totalRoomCharge = calcService(smallRoom, bigRoom);
    float taxCost = serviceTax(totalRoomCharge);

    cout << "Cost: $" << totalRoomCharge << "\n";
    cout << "Tax: $" << taxCost << "\n";

    cout << "=====================================\n";
    cout << "Total estimate: $" << (totalRoomCharge + taxCost) << "\n";
    cout << "This estimate is valid for 30 days\n";

    return 0;
}