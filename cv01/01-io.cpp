#include <stdio.h> // C include  /usr/include, /usr/local/include
#include <iostream> // C++ include - neni pripona .h

namespace test
{
    int a = 11;
    int b = 12;
}

using namespace std;
using namespace test;

int main ()
{
    printf("Ahoj z C!\n");

    std::cout << "Ahoj z C++!\n";

    std::cout << "jedna " << "dva " << 3 << ' ' << 3.141592 << std::endl;

    std::cout << "10 + 30 = " << 10+30 << std::endl;

    int a = 30;
    std::cout << "a = " << a << " test::a = " << test::a << std::endl;

    cout << "a = " << a << " b = " << b << endl;

    cout << "test::a = " << test::a << " test::b = " << test::b << endl;

    /*
        std::cout - standardni vystup (v C: stdout)
        std::cerr - standardni chybovy vystup (v C: stderr)
        std::cin  - standardni vstup (v C: stdin)
        std::clog - standardni logovaci vystupyyy
    */
    
    cout << "Zadej cislo datoveho typu int:" << endl;

    std::cin >> test::b;

    if (std::cin.good())
        cout << "zadal jsi " << test::b << std::endl;
    else
        cout << "nauc se datove typy!" <<  endl;
    return 0;
}