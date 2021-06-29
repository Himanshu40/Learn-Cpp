#include <iostream>
#include <vector>
#include <iomanip>
#include "header.h"


using namespace std;


void printElements(vector<int> &tempVec) {
    if (tempVec.size()) {
        cout << "\n[ ";
        
        for (auto i : tempVec) {
            cout << i << " ";
        }

        cout << "]\n" << endl;
    }
    else {
        cout << "\n[] - the list is empty\n" << endl;
    }
}


void addElement(vector<int> &tempVec) {
    int num{};

    cout << "\nEnter an integer: ";
    cin >> num;
    
    tempVec.push_back(num);
    cout << num << " is added to the list\n" << endl;
}


void meanElements(vector<int> &tempVec) {
    if (tempVec.size()) {
        double mean{};
        int sum{};

        for (auto i : tempVec) {
            sum += i;
        }

        mean = static_cast<double>(sum) / tempVec.size();

        cout << fixed;
        cout << "\nMean: " << setprecision(2) << mean << "\n" << endl;
    }
    else {
        cout << "\nUnable to calculate the mean - no data\n" << endl;
    }
}


void smallestElement(vector<int> &tempVec) {
    if (tempVec.size()) {
        if (tempVec.size() == 1) {
            cout << "\nSmallest element: " << tempVec[0] << "\n" << endl;
        }
        else {
            int smallNum = tempVec[0];

            for (unsigned i = 1; i != tempVec.size(); ++i) {
                if (smallNum > tempVec[i]) {
                    smallNum = tempVec[i];
                }
            }

            cout << "\nSmallest element: " << smallNum << "\n" << endl;
        }
    }
    else {
        cout << "\nUnable to determine the smallest number - list is empty\n" << endl;
    }
}


void largestElement(vector<int> &tempVec) {
    if (tempVec.size()) {
        if (tempVec.size() == 1) {
            cout << "\nLargest element: " << tempVec[0] << "\n" << endl;
        }
        else {
            int largeNum = tempVec[0];

            for (unsigned i = 1; i != tempVec.size(); ++i) {
                if (largeNum < tempVec[i]) {
                    largeNum = tempVec[i];
                }
            }

            cout << "\nLargest element: " << largeNum << "\n" << endl;
        }
    }
    else {
        cout << "\nUnable to determine the largest number - list is empty\n" << endl;
    }
}


void findElement(vector<int> &tempVec) {
    if (tempVec.size()) {
        int checkNum{};
        int count{};

        cout << "\nEnter the element: ";
        cin >> checkNum;

        for (auto i : tempVec) {
            if (i == checkNum) {
                ++count;
            }
        }

        if (count) {
            cout << checkNum << " found " << count << " times in the list\n" << endl;
        }
        else {
            cout << "\nNo element found in the list\n" << endl;
        }
    }
    else {
        cout << "\nUnable to find the number - list is empty\n" << endl;
    }
}


void clearElement(std::vector<int> &tempVec) {
    if (tempVec.size()) {
        tempVec.clear();
        cout << "\nList is now empty\n" << endl;
    }
    else {
        cout << "\n[] - list is already empty. No clear operation done performed in list\n" << endl;
    }
}
