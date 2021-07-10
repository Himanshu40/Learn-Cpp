#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> vector1;
    vector<int> vector2;

    vector1.push_back(10);
    vector1.push_back(20);

    cout << vector1.at(0) << " " << vector1.at(1) << " " << vector1.size() << "\n";

    vector2.push_back(100);
    vector2.push_back(200);

    cout << vector2.at(0) << " " << vector2.at(1) << " " << vector2.size() << "\n";

    vector<vector<int>> vector_2d;

    vector_2d.push_back(vector1);
    vector_2d.push_back(vector2);

    cout << vector_2d.at(0).at(0) << " " << vector_2d.at(0).at(1) << "\n";
    cout << vector_2d.at(1).at(0) << " " << vector_2d.at(1).at(1) << "\n"; 

    vector1.at(0) = 100; // changing vector 1 to 100 will not effect 2D vector

    cout << vector_2d.at(0).at(0) << " " << vector_2d.at(0).at(1) << "\n";
    cout << vector_2d.at(1).at(0) << " " << vector_2d.at(1).at(1) << "\n"; 

    cout << vector1.at(0) << " " << vector1.at(1) << " " << vector1.size() << "\n";

    return 0;
}