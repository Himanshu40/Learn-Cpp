// File copy using get/put
#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream inFile {"poem.txt"};
    std::ofstream outFile {"poemOut.txt"};

    if (!inFile) {
        std::cerr << "Error opening input file" << std::endl;
        return 1;
    }

    if (!outFile) {
        std::cerr << "Error opening output file" << std::endl;
        return 1;
    }

    char c;

    while (inFile.get(c)) {
        outFile.put(c);
    }

    outFile << std::endl;
    
    std::cout << "File copied successfully" << std::endl;

    inFile.close();
    outFile.close();

    return 0;
}
