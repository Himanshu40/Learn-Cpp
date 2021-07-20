#include <iostream>
#include <string>

template <int N>
class Array {
    private:
        int size {N};
        int values[N];

        friend std::ostream &operator<<(std::ostream &os, const Array<N> &arr) {
           os << "[";

           for (const auto &val : arr.values) {
               os << val << " ";
           } 

           os << "]" << std::endl;

           return os;
        }
    public:
        Array() = default;
        
        Array(int initValue) {
            for (auto &item : values) {
                item = initValue;
            }
        }

        void fill(int val) {
            for (auto &item : values) {
                item = val;
            }
        }

        int getSize() const {
            return size;
        }

        int &operator[](int index) {
            return values[index];
        }
};

int main() {
    Array<5> nums;
    
    std::cout << "The size of nums is: " << nums.getSize() << std::endl;
    std::cout << nums << std::endl;

    nums.fill(0);
    std::cout << "The size of nums is: " << nums.getSize() << std::endl;
    std::cout << nums << std::endl;

    nums.fill(10);
    std::cout << nums << std::endl;

    nums[0] = 1000;
    nums[3] = 3000;
    std::cout << nums << std::endl;

    Array<20> nums2 {1};
    std::cout << "The size of nums2 is: " << nums2.getSize() << std::endl;
    std::cout << nums2 << std::endl;

    nums2[0] = 1000;
    nums2[3] = 3000;
    std::cout << nums2 << std::endl;

    return 0;
}
