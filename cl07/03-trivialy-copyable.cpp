#include <iostream>

struct A {
    int m;
};

struct B {
    // kopirovaci konstruktor
    B(B const&) {}
};

struct C {
    virtual void foo();
};

struct D {
    int m;

    D(D const&) = default; // -> trivially copyable
    D(int x): m(x+1) {}
};

int main() {

    std::cout << std::boolalpha;
    
    std::cout << std::is_trivially_copyable<A>::value << '\n';
    std::cout << std::is_trivially_copyable<B>::value << '\n';
    std::cout << std::is_trivially_copyable<C>::value << '\n';
    std::cout << std::is_trivially_copyable<D>::value << '\n';

    return 0;
}