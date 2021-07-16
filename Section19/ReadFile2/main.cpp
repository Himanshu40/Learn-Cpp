// Read File 2
// Test for file open and simple read of 2 data items
#include <iostream>
#include <iomanip>
#include <fstream>

int main() {
    std::ifstream inFile;
    inFile.open("Hello.txt");

    if (!inFile) {
        std::cerr << "Problem opening file" << std::endl;
        return 1;
    }

    std::cout << "File is good to go" << std::endl;

    std::string line;
    int num;

    while(!inFile.eof()) {                  // OR while (inFile >> line >> num)
        inFile >> line >> num;
        
        std::cout << std::setw(10) << std::left << line
                << std::setw(10) << num
                << std::endl;
    }

    inFile.close();

    return 0;
}
