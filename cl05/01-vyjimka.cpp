#include <iostream>
#include <exception>

int main() {
	double a, b;

	std::cin >> a >> b;

	try {
		if (b == 0) throw "Deleni nulou.\n";
		std::cout << a / b << std::endl;
	}
	catch (const char* e) {
		std::cout << "Vyjimka - " << e;
	}

	return 0;
}