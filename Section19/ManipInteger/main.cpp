// Stream manipultors - Integer manipulators
// dec, hex, oct, showbase, uppercase, nouppercase, showpos

#include <iostream>
#include <iomanip>

int main() {
    int num {255};

    // Display using different bases
    std::cout << "\n------------------------" << std::endl;
    std::cout << std::dec << num << std::endl;
    std::cout << std::hex << num << std::endl;
    std::cout << std::oct << num << std::endl;
    //std::cout << std::resetiosflags(std::ios::basefield);
    std::cout << num;                           // Display octal not decimal due to no reset

    // Display swoing the base prefix for hex and oct
    std::cout << "\n------------------------" << std::endl;
    std::cout << std::showbase;
    std::cout << std::dec << num << std::endl;
    std::cout << std::hex << num << std::endl;
    std::cout << std::oct << num << std::endl;
    
    // Display the hex value in uppercase
    std::cout << "\n------------------------" << std::endl;
    std::cout << std::showbase << std::uppercase;
    std::cout << std::hex << num << std::endl;

    // Display the + sign in front of positive base 10 numbers
    std::cout << "\n------------------------" << std::endl;
    std::cout << std::showpos;
    std::cout << std::dec << num << std::endl;
    std::cout << std::hex << num << std::endl;
    std::cout << std::oct << num << std::endl;

    // Set using the set method
    std::cout << "\n------------------------" << std::endl;
    std::cout.setf(std::ios::showbase);
    std::cout.setf(std::ios::uppercase);
    std::cout.setf(std::ios::showpos);

    std::cout << std::dec << num << std::endl;
    std::cout << std::hex << num << std::endl;

    // Reset to defaults
    std::cout << std::resetiosflags(std::ios::basefield);   // Reset integer base back to normal
    std::cout << std::resetiosflags(std::ios::showbase);
    std::cout << std::resetiosflags(std::ios::showpos);
    std::cout << std::resetiosflags(std::ios::uppercase);

    std::cout << "\n------------------------" << std::endl;
    std::cout << "Enter an integer: ";
    std::cin >> num;

    std::cout << "Decimal default: " << num << std::endl;

    std::cout << "Hexadecimal: " << std::hex << num << std::endl;
    std::cout << "Hexadecimal: " << std::hex << std::uppercase << num << std::endl;
    std::cout << "Hexadecimal: " << std::hex << num << std::endl;
    std::cout << "Hexadecimal: " << std::hex << std::nouppercase << num << std::endl;

    std::cout << "Octal: " << std::oct << num << std::endl;
    std::cout << "Hexadecimal: " << std::hex << std::showbase << num << std::endl;
    std::cout << "Octal: " << std::oct << num << std::endl;     // Affects showbase

    std::cout << std::endl;

    return 0;
}
