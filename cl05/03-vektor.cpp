#include <iostream>

#define ASSIGN

class Vektor {
	int * data, velikost;
public:
	explicit Vektor (int v): velikost(v) {
        data = new int[velikost];
		for (int i = 0; i < velikost; i++) data[i] = 0;
	}
	~Vektor () {delete [] data;}
	int & operator[] (int idx);
#ifdef ASSIGN    
    Vektor & operator = (const Vektor & src);
#endif
};

int & Vektor::operator[] (int idx) {
	if ( idx < 0 || idx >= velikost )
		throw "Index mimo meze";
	return data[idx];
}

#ifdef ASSIGN
Vektor & Vektor::operator = (const Vektor & src) {
	if ( &src == this ) return *this;
	delete [] data;
	velikost = src.velikost;
	data = new int [velikost];
	for ( int i = 0; i < velikost; i ++ )
		data[i] = src.data[i];
	return *this;
}
#endif

int main() {

	Vektor a(5), b(5);
	
	a[4] = 3;
	b = a;	   // problem 1
	b[3] = 5;  // problem 2
	
	for (int i = 0; i < 5; i++)
		std::cout << a[i] << " ";
	std::cout << std::endl;

    for (int i = 0; i < 5; i++)
		std::cout << b[i] << " ";
	std::cout << std::endl;

	return 0;
}