#include <iostream>

int main()
{
	std::string s1("Ahoj");

    std::cout << s1 << "\n";

	std::string s2(8, 'x');

    std::cout << s2 << "\n";

	std::string mesic = "Leden";
	// implicitní volání konstruktoru
	// std::string mesic("Leden");

    std::cout << mesic << std::endl;

    return 0;
}
