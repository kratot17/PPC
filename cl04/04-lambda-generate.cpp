#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> seq;
    int s = 123;

    // chyba
    // lambda se pokousi ovlivnovat promennou zachycenou hodnotou
    // generate_n (back_inserter (seq), 10, [s]() {return s++;});

    // ok
    // predchozi problem se da napravit pomoci mutable
    // hodnota promenne s se se ale nezmeni
    generate_n (back_inserter (seq), 10, [s]() mutable {return s++;});
    std::cout << "s: " << s << std::endl;

    for (auto a : seq) std::cout << a << " ";
    std::cout << std::endl;

    // ok
    // lambda ovlivnuje promennou zachycenou referenci
    generate_n (back_inserter (seq), 10, [&s]() {return s++;});
    std::cout << "s: " << s << std::endl;

    for (auto a : seq) std::cout << a << " ";
    std::cout << std::endl;

    return 0;
}
