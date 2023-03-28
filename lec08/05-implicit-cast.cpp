#include <iostream>

struct A {};

struct B {
	// konverze z A (konstructor)
	B (const A & x) {
		std::cout << "vola se konstruktor\n";
	}
	// konverze z A (přiřazení)
	B & operator= (const A & x) {
		std::cout << "operator prirazeni\n";
		return *this;
	}
	// konverze do A (type-cast operátor)
	operator A() {
		std::cout << "type-cast operator\n";
		return A();
	}
};

int main() {
    A foo;
    B bar = foo;    // volá se konstruktor
    bar = foo;      // operátor přiřazení
    foo = bar;      // volá se type-cast operátor

    return 0;
}