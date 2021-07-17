#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

int main() {
    std::ifstream inFile {"romeoandjuliet.txt"};

    if (!inFile) {
        std::cerr << "Error opening file" << std::endl;
        return 1;
    }

    std::ofstream outFile {"romieandjulietLine.txt"};

    if (!outFile) {
        std::cerr << "Error creating file" << std::endl;
        return 1;
    }

    std::string line;
    int lineNum {1};

    while (std::getline(inFile, line)) {
        if (line.find_last_not_of(' ') != 0) {
            outFile << std::setw(7) << std::left << lineNum << line << std::endl;
            ++lineNum;
        }
        else {
            outFile << line << std::endl;
        }
    }

    outFile.close();
    inFile.close();

    return 0;
}
