#include <iostream>

using namespace std;

int *input(const size_t size) {
    int *array {new int[size]};

    cout << "Enter the elements of array:\n";
    for (size_t i {0}; i != size; ++i) {
        cin >> array[i];
    }

    return array;
}

void display(const int *const array, const size_t size) {
    cout << "[ ";

    for (size_t i {0}; i != size; ++i) {
        cout << array[i] << " ";
    }

    cout << "]\n";
}

int *applyAll(const int *const array1, 
              const size_t size1, 
              const int *const array2, 
              const size_t size2) {
    int *result {new int[size1 * size2]};
    size_t count {0};

    for (size_t j {0}; j != size2; ++j) {
        for (size_t k {0}; k != size1; ++k) {
            result[count++] = array1[k] * array2[j];
        }
    }

    return result;
}


int main() {
    size_t size1 {};

    cout << "----------------------------\n";
    cout << "Enter the size of array 1: ";
    cin >> size1;

    int *array1 {input(size1)};

    size_t size2 {};

    cout << "Enter the size of array 2: ";
    cin >> size2;

    int *array2 {input(size2)};
    cout << "----------------------------\n";

    display(array1, size1);
    display(array2, size2);

    cout << "----------------------------\n";

    int *result {applyAll(array1, size1, array2, size2)};

    //cout << sizeof(result) / sizeof(result[0]); 
    //display(result, size1 * size2);
    display(result, size1 * size2);

    cout << "----------------------------\n";

    delete [] array1;
    delete [] array2;
    delete [] result;

    return 0;
}