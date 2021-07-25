#include <algorithm>
#include <cctype>
#include <deque>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

bool isPalindrome(const std::string &s) {
    std::deque<char> compare1;
    std::deque<char> compare2;

    std::copy_if(s.begin(), s.end(), std::back_inserter(compare1),
        [](char c) {if (std::isalpha(c)) {return std::toupper(c);} return 0;});

    std::copy(compare1.begin(), compare1.end(), std::front_inserter(compare2));

    if (compare1 == compare2) {
        return true;
    }

    return false;
}

int main() {
    std::vector<std::string> testStrings {"a",
                                          "aa",
                                          "aba",
                                          "abba",
                                          "abbcbba",
                                          "ab",
                                          "abc",
                                          "radar",
                                          "bob",
                                          "ana",
                                          "A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama",
                                          "This is a palindrome",
                                          "palindrome",
                                          "avid diva",
                                          "Amore, Roma",
                                          "A Toyota's toyota",
                                          "A Santa at NASA",
                                          "C++"};

    std::cout << std::boolalpha;
    std::cout << std::setw(8) << std::left << "Result" << "String" << std::endl;

    for (const auto &s : testStrings) {
        std::cout << std::setw(8) << std::left << isPalindrome(s) << s <<  std::endl;
    }

    std::cout << std::endl;

    return 0;
}
