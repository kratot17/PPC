#include <iostream>

void fce1 (int a)
{
    a = 8;
    std::cout << "fce1: a = " << a << " addr: " << &a << std::endl;
}

void fce2 (int * a)
{
    *a = 10;
    std::cout << "fce2: a = " << *a << " addr: " << a << std::endl;
}

void fce3 (int & a)
{
    a = 12;
    std::cout << "fce3: a = " << a << " addr: " << &a << std::endl;
}

int main()
{
    int x = 2;
    std::cout << "x0 = " << x << " addr: " << &x << std::endl;
    fce1(x);
    std::cout << "x1 = " << x << " addr: " << &x << std::endl;
    fce2(&x);
    std::cout << "x2 = " << x << " addr: " << &x << std::endl;
    fce3(x);
    std::cout << "x3 = " << x << " addr: " << &x << std::endl;
    return 0;
}
