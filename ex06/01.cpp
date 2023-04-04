#include<iostream>

class addition {
    public:
    int add(int num1, int num2) {
    return (num1 + num2);
    }
    addition() {
        std::cout << " class was made" << std::endl;
    }
};

int main() {
    addition myAdd;
    std::cout << myAdd.add(5, 4) << std::endl;

    return 0;
}