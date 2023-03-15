
#include <iostream> // C++ include - neni pripona .h
#include <iomanip> // C++ manipulace s io

using namespace std;

int main ()
{
    double pi = 3.14159265;
    double pj = 65.8765432;
    double pk = 768956.623;

    cout << pi << ' ' << pj << ' ' << pk << endl; // defaultne na 6 PLATNYCH mist
    
    cout << std::setprecision(2); // zmeni presnost pro vsechny nasledujici vypisy
    cout << pi << ' ' << pj << ' ' << pk << endl; // na 2 PLATNA mista

    cout << std::fixed; // zmena formatu vypisu: precision ted udava pocet DESETINNYCH mist
    cout << pi << ' ' << pj << ' ' << pk << endl; // na 2 DESETINNA mista

    cout << std::setprecision(5); // zmeni presnost pro vsechny nasledujici vypisy
    cout << pi << ' ' << pj << ' ' << pk << endl; // na 5 DESETINNYCH mist

    cout << std::scientific; // zmena formatu vypisu: scientific
    cout << pi << ' ' << pj << ' ' << pk << endl; 

    cout.unsetf(ios_base::floatfield); // resetuje format vypisu na defaultni, pozor, nemeni precision
    cout << setprecision(6);
    cout << pi << ' ' << pj << ' ' << pk << endl; 


    cout << std::setw(10) << pi << ' ' << pj << ' ' << pk << endl;  // setw() meni sirku pole pro nasledujici vypis (jen pro jeden dalsi)
    return 0;
}