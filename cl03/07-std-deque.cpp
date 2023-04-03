#include <iostream>
#include <deque>

using namespace std;

int main()
{
	deque<int> x;
	x.push_back (100); 
    x.push_front (200);
	x.push_back (300); 
    x.push_front (400);
	x.insert (x.begin() + 1, 500);

    // copy, read, display \& pop
	for (deque<int> y (x); !y.empty (); y.pop_front())
		cout << y.front () << endl;

	x.erase (x.begin () + 1, x.begin () + 3 );

	// iterate in reverse direction
	deque<int>::reverse_iterator it;
	for (it = x.rbegin(); it != x.rend (); ++it)
		cout << *it << endl;

    return 0;
}