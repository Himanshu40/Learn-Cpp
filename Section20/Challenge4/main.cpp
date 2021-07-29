// Section 20
// Challenge 4
// Identifying palindrome strings using a stack and queue
#include <cctype>
#include <stack>
#include <queue>
#include <iostream>
#include <string>
#include <iomanip>

bool is_palindrome(const std::string& s)
{
    std::stack<char> s1;
    std::queue<char> q1;

    for (char c : s) {
        if (std::isalpha(c)) {
            c = std::toupper(c);
            s1.push(c);
            q1.push(c);
        }
    }

    while (!s1.empty() && !q1.empty()) {
        auto stackElem = s1.top();
        auto queueElem = q1.front();

        if (stackElem != queueElem) {
            return false;
        }
        s1.pop();
        q1.pop();
    }

    return true;
}

int main()
{
    std::vector<std::string> test_strings {"a", "aa", "aba", "abba", "abbcbba", "ab", "abc", "radar", "bob", "ana",
        "avid diva", "Amore, Roma", "A Toyota's a toyota", "A Santa at NASA", "C++",
        "A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!", "This is a palindrome", "palindrome"};
   
    std::cout << std::boolalpha;
    std::cout << std::setw(8) << std::left << "Result" << "String" << std::endl;
    
    for(const auto& s : test_strings) {
        std::cout << std::setw(8) << std::left << is_palindrome(s)  << s << std::endl;
    }
    std::cout << std::endl;

    return 0;
}