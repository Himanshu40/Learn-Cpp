// Write File
#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ofstream outFile {"Demo.txt", std::ios::app};

    if (!outFile) {
        std::cerr << "Error creating file" << std::endl;
        return 1;
    }

    std::string line;

    std::cout << "Enter something to write to the file: ";
    std::getline(std::cin, line);

    outFile << line << std::endl;

    outFile.close();

    return 0;
}
