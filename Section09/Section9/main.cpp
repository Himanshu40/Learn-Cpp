#include <iostream>
#include <vector>
#include "header.h"

using namespace std;

int main() {

    char choice{};
    vector<int> numVec;

    do {
        cout << "********************************************\n";
        cout << "P - Print numbers\n";
        cout << "A - Add a number\n"; 
        cout << "M - Display mean of the numbers\n"; 
        cout << "S - Display the smallest number\n"; 
        cout << "L - Display the largest number\n";
        cout << "F - Find a number and display the number of times it occurs\n";
        cout << "C - Clear list\n"; 
        cout << "Q - Quit\n";
        cout << "********************************************\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 'p':
            case 'P': printElements(numVec);   
                      break;
            case 'a':
            case 'A': addElement(numVec);
                      break;
            case 'm':
            case 'M': meanElements(numVec);
                      break;
            case 's':
            case 'S': smallestElement(numVec); 
                      break;
            case 'l':
            case 'L': largestElement(numVec);
                      break;
            case 'f':
            case 'F': findElement(numVec);
                      break;
            case 'c':
            case 'C': clearElement(numVec);
                      break;
            case 'q':
            case 'Q': cout << "\nGoodbye\n" << endl;
                      break;
            default: cout << "\nUnknown selection, please try again\n" << endl;
        }
    } while (!(choice == 'q' || choice == 'Q'));

    return 0;
}
