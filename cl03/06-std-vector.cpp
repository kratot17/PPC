#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> x;
	x.resize (10); // 0 0 0 ... 0
	x.push_back (100);
	x.insert (x.begin() + 5, 200); // vložení čísla
	
    x[3] = 120; // změna prvku, bez kontroly
	x.at (4) = 150; // změna prvku, kontrola
	
    copy (x.begin(), x.end (), ostream_iterator<int> (cout, " "));
    cout << endl;

	vector<int> y (x.begin () + 1, x.begin () + 9); // kopírování v rozsahu
	sort (y.begin(), y.end ());
	copy (y.begin(), y.end (), ostream_iterator<int> (cout, " " ));
    cout << endl;
    return 0;
}