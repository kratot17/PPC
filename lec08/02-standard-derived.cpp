#include <iostream>

struct Base1 {
	int i;
};
// Derived nemá standardní rozložení
struct Derived1 : public Base1 {
	int x;
};

struct Base2 {
	void Foo() {}
};
// Derived2 má standardní rozložení
struct Derived2 : public Base2 {
	int x;
};

int main() {
    
    std::cout << std::boolalpha;

    std::cout << "is_standard_layout:\n";
    std::cout << "Derived1: " << std::is_standard_layout<Derived1>::value << '\n';
	std::cout << "Derived2: " << std::is_standard_layout<Derived2>::value << '\n';

    return 0;
}