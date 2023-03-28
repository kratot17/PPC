#include <iostream>

struct cplx {
    float im, re;

    cplx operator+(cplx & a) {
        cplx tmp;
        tmp.im = this->im + a.im;
        tmp.re = this->re + a.re;
        return tmp;
    }

    cplx & operator~() { 
		this->im = -1 * this->im;
		return *this; 
	}
};

cplx operator-(cplx & a, cplx & b) {
    cplx tmp;
	tmp.re = a.re - b.re; 
	tmp.im = a.im - b.im;
	return tmp;
}

int main() {

    cplx *y = new cplx;

    cplx a = {3.3, 2.2}, b = {2.2, 3.3}, c;

    c = a + b;
    std::cout << c.re << std::showpos << c.im << "j" << std::endl;
    c = ~a;
    std::cout << c.re << std::showpos << c.im << "j" << std::endl; 

    return 0;
}