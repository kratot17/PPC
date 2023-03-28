#include <iostream>

struct A {
	// atributy maji stejnou viditelnost
	// defaultni konstruktor vytvoreny prekladacem
	// trivial, pod, standard
	int m1;
	int m2;
};

struct B {
	// atributy nemaji stejnou viditelnost
	// defaultni konstruktor vytvoreny prekladacem
	// trivial, non-pod, non-standard
    int m1;
private:
    int m2;
};

struct C {
	// defaultni konstruktor definovan uzivatelem 
	// non-trivial, non-pod, standard
	C() {}
};

struct D {
	// non-trivial, non-pod, non-standard
    virtual void f();
};

struct E {
	// v pripade, ze existuje i jiny, nez defaultni konstktor, 
	// lze trivialniho DT dosahnout explicitnim uvedenim def. konstruktoru
	// trivial, pod, standard
	E(int a, int b) {} 
	E() = default; 
}; 

int main() {

    std::cout << std::boolalpha;

    std::cout << "is_pod:\n";
    std::cout << "A: " << std::is_pod<A>::value << '\n';
	std::cout << "B: " << std::is_pod<B>::value << '\n';
	std::cout << "C: " << std::is_pod<C>::value << '\n';
    std::cout << "D: " << std::is_pod<D>::value << '\n';
	std::cout << "E: " << std::is_pod<E>::value << '\n';

    std::cout << "is_trivial:\n";
	std::cout << "A: " << std::is_trivial<A>::value << '\n';
	std::cout << "B: " << std::is_trivial<B>::value << '\n';
	std::cout << "C: " << std::is_trivial<C>::value << '\n';
    std::cout << "D: " << std::is_trivial<D>::value << '\n';
	std::cout << "E: " << std::is_trivial<E>::value << '\n';

    std::cout << "is_standard_layout:\n";
	std::cout << "A: " << std::is_standard_layout<A>::value << '\n';
	std::cout << "B: " << std::is_standard_layout<B>::value << '\n';
	std::cout << "C: " << std::is_standard_layout<C>::value << '\n';
    std::cout << "D: " << std::is_standard_layout<D>::value << '\n';
	std::cout << "E: " << std::is_standard_layout<E>::value << '\n';

    return 0;
}