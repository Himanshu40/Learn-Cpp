#include <iostream>
#include <fstream>
#include <string>

bool findString(const std::string &wordFind, const std::string &wordRead) {
    std::size_t found = wordRead.find(wordFind);

    if (found != std::string::npos) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    std::ifstream inFile {"romeoandjuliet.txt"};

    if (!inFile) {
        std::cerr << "Problem opening the file" << std::endl;
        return 1;
    }

    std::string wordFind;
    std::string wordRead;
    int wordCount {};
    int matchCount {};

    std::cout << "Enter the substring to search for: ";
    std::cin >> wordFind;

    while (inFile >> wordRead) {
        ++wordCount;

        if (findString(wordFind, wordRead)) {
            ++matchCount;
        }
    }

    std::cout << wordCount << " words were searched..." << std::endl;
    std::cout << "The substring " << wordFind << " was found " << matchCount << std::endl;

    return 0;
}
