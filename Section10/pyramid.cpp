#include <iostream>
#include <string>

using namespace std;

int main() {

    string sequence;

    cout << "Enter a sequence: ";
    getline(cin, sequence);

    size_t size{sequence.length()};

    for (int i{0}; i != size; ++i) {
        for (int j{0}; j != size - i - 1; ++j) {
            cout << " ";
        }
        for (int k{0}; k != i + 1; ++k) {
            cout << sequence[k];
        }
        for (int l{i - 1}; l >= 0; --l) {
            cout << sequence[l];
        }
        cout << "\n";
    }

    return 0;
}
