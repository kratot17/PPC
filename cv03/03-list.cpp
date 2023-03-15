#include <iostream>
#include <list>

int main()
{ 
    std::list<int> a;

    a.push_back(10);
    a.push_back(20);
    a.push_front(-10);
    a.push_front(-20);

    for(std::list<int>::iterator i = a.begin(); i != a.end(); i++ )
        std::cout << (*i)++  << "; ";  //hodnotu lze prepsat
    std::cout << std::endl;

    for(std::list<int>::reverse_iterator i = a.rbegin(); i != a.rend(); i++ ) //pozpatku
        std::cout << (*i)++ << "; ";  //hodnotu lze prepsat
    std::cout << std::endl;

    for(std::list<int>::const_iterator i = a.cbegin(); i != a.cend(); i++ ) 
        std::cout << *i << "; "; //hodnotu nelze prepsat
    std::cout << std::endl;

    for( std::list<int>::const_reverse_iterator i = a.crbegin(); i != a.crend(); i++ ) //pozpatku
        std::cout << *i << "; "; //hodnotu nelze prepsat
    std::cout << std::endl;
    

    auto iter = a.begin(); // ukazujeme na zacatek
    iter++; iter++; // ukazujeme na prvek "+12"
    a.insert(iter,0); // vlozime nulu pred prvek "+12"

    for (auto k : a) // range for (prochazime reference)
        std::cout << k << "; "; 
    std::cout << std::endl;

    return 0;
}
