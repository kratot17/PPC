#include <array>
#include <iostream>

struct Motor {
	Motor() { std::cout << "Motor\n"; }
};

struct Kolo {
	Kolo() { std::cout << "Kolo\n"; }
};

class Auto {
	Motor m;
	std::array<Kolo, 4> k;
public:
	Auto() { std::cout << "Auto\n"; }
};

int main() 
{
	Auto a;
	
	return 0;
}
