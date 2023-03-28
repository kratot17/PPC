#include <iostream>

using namespace std;

int cube (int x) {
	return x * x * x;
}

double cube (double x) {
	return x * x * x;
}


int main()
{
	int a = 2;
	float b = 3.14;

	cout << a << "^3 = " << cube(a) << endl;
	cout << b << "^3 = " << cube(b) << endl;

	return 0;
}