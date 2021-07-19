// Read File 1
// Test for file open and simple read of 3 data items
#include <iostream>
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

    inFile >> line;
    inFile >> num;

    // inFile >> line >> num;

    std::cout << line << std::endl;         // Prints "Hello" only one word
    std::cout << num << std::endl;

    inFile.close();

    return 0;
}
