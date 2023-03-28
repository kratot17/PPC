#include <iostream>
#include <exception>

class Base { virtual void dummy() {} };
class Derived: public Base { int a; };

int main () {

    try {
        Base * pba = new Derived;
        Base * pbb = new Base;
        Derived * pd;

        pd = dynamic_cast<Derived*>(pba);
        if (pd==0) std::cout << "Nulovy ukazatel v prvnim pripade.\n";

        pd = dynamic_cast<Derived*>(pbb);
        if (pd==0) std::cout << "Nulovy ukazatel v druhem pripade.\n";

    } catch (std::exception & e) {
        std::cout << "Vyjimka: " << e.what();
    }

    return 0;
}