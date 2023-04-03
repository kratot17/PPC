#include <iostream>

using namespace std;

void print (int x, int y = 0, int z = 0) 
{
	cout << "x=" << x << "\n";
	cout << "y=" << y << "\n";
	cout << "z=" << z << std::endl;
}

int main()
{
	print (10, 20, 30); 
	print (10, 20);     
	print (10);         

	return 0;
}