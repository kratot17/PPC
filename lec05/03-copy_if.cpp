#include <iostream>
#include <algorithm>

struct ispositive	// predikát
{
	bool operator()(int val) const 
	{
		return val>=0;
	}
};

int main () 
{
	int n = 4;
	int first[n] = {0,-1,-2,3};
	int result[n] = {0};

	std::copy_if (first, first+n, result, ispositive());

/*
    	Pro daný rozsah a definovaný predikár, algoritmus rozhodne
	jestli p je pravda pro:

	* všechny prvky v rozsahu (all_of()).
    	* alespoň jeden prvek v rozsahu (any_of()).
    	* žádný prvek v rozsahu (none_of()).
*/
	std::all_of(first, first+n, ispositive());   //false
    
	std::any_of(first, first+n, ispositive());   //true
    
	std::none_of(first, first+n, ispositive());  //false

	return 0;
}