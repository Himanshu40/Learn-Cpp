//Challenge 2 - Automated Grader
#include <iostream>
#include <iomanip>
#include <fstream>

int main() {
    std::ifstream inFile {"responses.txt"};

    if (!inFile) {
        std::cerr << "Problem opening file" << std::endl;
        return 1;
    }

    std::cout << std::setw(10) << std::left << "Student"
              << std::setw(10) << std::right << "Score"
              << std::endl;
              
    std::cout << std::setfill('-') << std::setw(20) << "" << std::endl;
    std::cout << std::setfill(' ') << "";

    std::string line;
    int gradeCount {};
    int totalStudent {};
    int totalGrade {};

    while (inFile >> line) {
        if (line[0] == 'A') {
            gradeCount += 1;
        }
        if (line[1] == 'B') {
            gradeCount += 1;
        }
        if (line[2] == 'C') {
            gradeCount += 1;
        }
        if (line[3] == 'D') {
            gradeCount += 1;
        }
        if (line[4] == 'E') {
            gradeCount += 1;
        }

        inFile >> line;
        
        std::cout << std::setw(10) << std::left << line 
                  << std::setw(10) << std::right << gradeCount
                  << std::endl;

        totalGrade += gradeCount;
        totalStudent += 1;
        gradeCount = 0;
    }

    std::cout << std::setfill('-') << std::setw(20) << "" << std::endl;
    std::cout << std::setfill(' ') << "";

    std::cout << std::setw(15) << std::left << "Average score"
              << std::setw(5) << std::right << static_cast<double>(totalGrade) / totalStudent
              << std::endl;

    inFile.close();

    return 0;
}
