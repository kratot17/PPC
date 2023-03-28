#include <iostream>
#include <fstream>
#include <stdexcept>
 
double readDouble() 
{
	double d;
	std::cin >> d;
 
	if (std::cin.good()) 
	{
        	return d;
    	}
    	else if (std::cin.bad() || std::cin.eof()) 
	{
		throw std::runtime_error("readDouble() failed");
	}
	else 
	{
		std::cin.clear();
		std::cin.ignore(1, '\n');
		return readDouble();
	}
}
 
int main() 
{
	double a = readDouble();
	double b = readDouble();
	double c = readDouble();
 
	std::cout << (a + b + c) << '\n';

	return 0;
}