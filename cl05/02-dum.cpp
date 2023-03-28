#include <iostream>
#include <vector>

struct Pokoj {
	Pokoj() { std::cout << "Pokoj\n"; }
};
class Dum {
	std::vector<Pokoj> pokoje;
	unsigned pocetPokoju;

public:
	Dum (int x) : pocetPokoju(x), pokoje (pocetPokoju) {
		std::cout << "Dum s " << pocetPokoju << " pokoji\n";
	}
};

int main() 
{
	Dum d(5);
	// co se stane?
	return 0;
}
