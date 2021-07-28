// Map
#include <iostream>
#include <map>
#include <set>

void display(const std::map<std::string, std::set<int>> &m) {
    std::cout << "[ ";

    for (const auto &elem : m) {
        std::cout << elem.first << ":[ ";

        for (const auto &setElem : elem.second) {
            std::cout << setElem << " ";
        }

        std::cout << "] ";
    }

    std::cout << "]" << std::endl;
}

template <typename T1, typename T2>
void display(const std::map<T1, T2> &l) {
    std::cout << "[";

    for (const auto &elem : l) {
        std::cout << elem.first << ":" << elem.second << " ";
    }

    std::cout << "]" << std::endl;
}

void test1() {
    std::cout << "===TEST1===" << std::endl;

    std::map<std::string, int> m {
        {"Larry", 3},
        {"Moe", 1},
        {"Curly", 2}
    };
    display(m);

    m.insert(std::pair<std::string, int>("Anna", 10));
    display(m);

    m.insert(std::make_pair("Joe", 5));
    display(m);

    m["Frank"] = 18;
    display(m);

    m["Frank"] += 10;
    display(m);

    m.erase("Frank");
    display(m);

    std::cout << "Count for Joe: " << m.count("Joe") << std::endl;
    std::cout << "Count for Frank: " << m.count("Frank") << std::endl;

    auto it = m.find("Larry");

    if (it != m.end()) {
        std::cout << "Found: " << it->first << ":" << it->second << std::endl;
    }

    m.clear();
    display(m);
}

void test2() {
    std::cout << "===TEST2===" << std::endl;

    std::map<std::string, std::set<int>> grades {
        {"Larry", {100, 90}},
        {"Moe", {94}},
        {"Curly", {80, 90, 100}}
    };

    display(grades);

    grades["Larry"].insert(95);
    display(grades);

    auto it = grades.find("Moe");
    if (it != grades.end()) {
        it->second.insert(1000);
    }

    display(grades);
}

int main() {
    test1();
    test2();

    return 0;
}
