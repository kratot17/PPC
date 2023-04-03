#include <iostream>

using namespace std;

struct cplx {
	float im; 
	float re;
};    

cplx operator+(cplx &a, cplx &b) { // přetížení +  
	cplx tmp;
	tmp.re = a.re + b.re; 
	tmp.im = a.im + b.im;
	return tmp;
}

cplx operator-(cplx &a, cplx &b) { // petížení -
	cplx tmp;
	tmp.re = a.re - b.re; 
	tmp.im = a.im - b.im;
	return tmp;
}

int main ()
{
	cplx c = {10, 20};
	cplx d = {30, 30};
	cplx e, f;

	e = c + d;            // zkrácené požití operátoru
	cout << std::showpos; // manipulátor pro vynucení znaménka
	cout << "e = " << e.re << e.im << "j\n"; 
	f = operator-(c, d);  // funkční použití operátoru
	cout << "f = " << f.re << f.im << "j\n";

	return 0;
}