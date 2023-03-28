#include <iostream>

struct Zamek 
{
	Zamek() { std::cout << "uzamcen\n"; }

	// Rule of Three:
	// Trida pracuje se zdrojem (zamek) a tak musi
	// definovat (nebo explicitne zakazat) nasledujici:
	// - kopirovaci konstruktor
	// - prirazovaci operator
	// - destruktor

	Zamek (const Zamek &) = delete;
	Zamek & operator=(const Zamek &) = delete;
	~Zamek () { std::cout << "odemcen\n"; }
};

void kritickaSekce() 
{
	Zamek z;
	std::cout << "kriticka sekce\n";
}

int main() 
{
	kritickaSekce();
	return 0;
}
