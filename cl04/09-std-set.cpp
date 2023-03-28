#include <iostream>
#include <set>

using namespace std;

int main()
{
	set<int> x;
	x.insert (20);
	x.insert (100);
	x.insert (1000);
	cout << (x.count (20) == 1 ? "present" : "not present" ) << endl;
	set<int>::iterator pos = x.find (1000);
	if (pos != x.end ()) x.erase (pos);
	set<int>::iterator it;
	for (it = x . begin(); it != x.end (); ++it)
		cout << *it << endl;

    return 0;
}
