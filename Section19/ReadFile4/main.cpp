// Read and display Shakespeare Sonnet 18 poem using unformatted get
#include <iostream>
#include <fstream>

int main() {
    std::ifstream inFile {"poem.txt"};

    if (!inFile) {
        std::cerr << "Problem opening file" << std::endl;
        return 1;
    }

    char c;

    while (inFile.get(c)) {
        std::cout << c;
    }
    
    std::cout << std::endl;

    inFile.close();

    return 0;
}
