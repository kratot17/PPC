#include <iostream>
#include <list>

using namespace std;

int main()
{
	list<int> x;
	x.push_back (100); x.push_back (200); x.push_front (300);
	list<int>::iterator pos = x.begin ();
	pos++;
	x.insert (pos, 400);
	pos++;
	x.erase (pos);

    // iterate forward
	list<int>::iterator it;
	for (it = x . begin(); it != x.end (); ++it)
		cout << *it << endl;

    return 0;
}

