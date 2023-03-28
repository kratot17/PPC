#include <iostream>
#include <iterator>
#include <array>

using namespace std;

int main()
{
	array<int, 10> x;
	
    x.fill (-1);
	x[3] = 100; // unchecked access
	
	for (array<int,10>::size_type i = 0; i < x.size(); i++)
		x[i] += 100;
	
	copy (x.begin(), x.end(), ostream_iterator<int> (cout, "\n"));
	
    // kopie pole x
    array<int, 10> y(x);
    
    return 0;
}