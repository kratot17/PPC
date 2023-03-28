#include <iostream>
#include <numeric>
#include <iterator>

using namespace std;

int main ()
{
	cout << accumulate (
		istream_iterator<int> (cin),
		istream_iterator<int> (), 0);

	cout << endl;
}