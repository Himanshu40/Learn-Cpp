// Read and display Shakespeare Sonnet 18 poem using getline
#include <iostream>
#include <fstream>

int main() {
    std::ifstream inFile {"poem.txt"};

    if (!inFile) {
        std::cerr << "Problem opening file" << std::endl;
        return 1;
    }

    std::string line;

    while (std::getline(inFile, line)) {
        std::cout << line << std::endl;
    }

    inFile.close();

    return 0;
}
