#include <iostream>
#include <string>

unsigned newID() 
{
	static unsigned last = 0;
	return last++;
}

class Osoba 
{
	std::string jmeno;
	const unsigned id;

public:
	Osoba(const std::string & x) : jmeno(x), id(newID()) {}

	Osoba(const Osoba & x) : jmeno (x.jmeno), id(newID()) {}

	Osoba & operator = (const Osoba & x) 
	{
		jmeno = x.jmeno;
		// id se nezmenilo!
		return *this;
	}

	void tisk() 
	{
		std::cout << id << ": " << jmeno << '\n';
	}
};

int main() 
{
	Osoba jan("Jan Novak");
	Osoba jana("Jana Novakova");
	Osoba klon = jan;

	jan.tisk();
	klon.tisk();

	klon = jana;

	jana.tisk();
	klon.tisk();

	return 0;
}
