#include <iostream>
#include <iomanip>

struct Cplx {
    double re, im;
    
    Cplx(double r = 0, double i = 0): re(r), im(i) {};
    Cplx(const Cplx & c): re(c.re), im(c.im) {}; // kopirujici konstruktor

    Cplx operator+ (const Cplx & b) const {return Cplx(this->re + b.re, this->im + b.im);} // operator definovan jako clenska funkce
    Cplx operator+ (const double & b) const {return Cplx(this->re + b, this->im + 0);}

    Cplx & operator= (const Cplx & c) // operator prirazeni
    {
        if (this == &c) // osetreni zapisu do sebe sama (x=x)
            return *this; 
        this->re = c.re; 
        this->im = c.im;
        return *this;
    } 

    bool operator== (const Cplx & b) const {return (this->re == b.re) && (this->im == b.im); }

    void print() const {std::cout << std::showpos << this->re << this->im << "j"<< std::endl;}
};

Cplx operator+(const double & a , const Cplx & b)  // operace a+b
{
    return b + a;
}

Cplx operator-(const Cplx & a , const Cplx & b)  // operace a-b
{
    return Cplx(a.re - b.re, a.im - b.im);
}

Cplx operator-(const double & a , const Cplx & b)  // operace a-b
{
    return Cplx(a - b.re, 0 - b.im);
}

Cplx operator-(const Cplx & a , const double & b)  // operace a-b
{
    return Cplx(a.re - b, a.im - 0);
}

std::ostream & operator<< (std::ostream & os, const Cplx & x )
{
    os << std::showpos << x.re << x.im << "j";
    return os;
}
int main()
{
    Cplx a;
    a.im = 5.0;
    Cplx b(3.0);
    Cplx c(6.0,-2.0);
    Cplx d = b-c;
    Cplx e = 5-c;
    Cplx f = b+c;

    //a.print(); b.print(); c.print(); d.print(); e.print(); f.print();
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "c: " << c << std::endl;
    std::cout << "d: " << d << std::endl;
    std::cout << "e: " << e << std::endl;
    std::cout << "f: " << f << std::endl;

    std::cout << "a: " << a << "&: " << &a << std::endl;
    
    a = f; // volame prirazeni
    Cplx g(a); // volame kopirujici konstruktor
    Cplx h = a; // volame kopirujici konstruktor

    std::cout << "a: " << a << "&: " << &a << std::endl;
    std::cout << "f: " << f << "&: " << &f << std::endl;
    std::cout << "g: " << g << "&: " << &g << std::endl;
    std::cout << "h: " << h << "&: " << &h << std::endl;

    std::cout << (Cplx(1,1) == Cplx(1,1)) << " " << (Cplx(1,1) == Cplx(1,0)) << std::endl;
    return 0;
}