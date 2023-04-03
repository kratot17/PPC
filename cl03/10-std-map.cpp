#include <iostream>
#include <map>

using namespace std;

int main()
{
    map<string,int> x;
	x.insert (make_pair ("test", 10));
	x["key"] = 20;
	x["testkey"] = x["test"] + x["key"];

	map<string,int>::const_iterator it;
	for (it = x . begin(); it != x . end (); ++it )
		cout << it -> first << "->" << it -> second << endl;

	map<string,int>::iterator pos = x.find ("test");
	cout << (pos != x.end () ? "present" : "not present") << endl;
	x.erase (pos);

    return 0;
}