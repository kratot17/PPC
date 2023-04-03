#include <iostream>
#include <thread>
#include <list>
#include <algorithm>

using namespace std;

// globální seznam, do kterého zapisují jednotlivá vlákna
std::list<int> myList;

// std::mutex myMutex;

void addToList(int max, int interval)
{
       /*
        * při zápisu je vhodné datovou strukturu zamknout mutexem
        * problém ovšem nastane, pokud při práci se zamčenou strukturou dojde k vyjímce
        * std::thread to řeší pomocí lock_guard, který odemkne strukturu při zavolání svého destruktoru
        */
        // std::lock_guard guard(myMutex);
	for (int i = 0; i < max; i++) {
		if( (i % interval) == 0) myList.push_back(i);
	}
}

void printList()
{
        // std::lock_guard guard(myMutex);
	for (auto itr = myList.begin(), end_itr = myList.end(); itr != end_itr; ++itr ) {
		cout << *itr << ",";
	}
}

int main()
{
	int max = 100;

	std::thread t1(addToList, max, 1);
	std::thread t2(addToList, max, 10);
	std::thread t3(printList);

	t1.join();
	t2.join();
	t3.join();

	return 0;
}