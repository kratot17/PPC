#include <iostream>
#include <iomanip>

using namespace std;

int main ()
{
	// int
	cout << "|" <<  1 << "|"  << endl;         // |1|
	cout << "|" << -1 << "|"  << endl;         // |-1|
	cout << "|" <<  123456789 << "|" << endl;  // |123456789|
	cout << "|" << -123456789 << "|" << endl;  // |-123456789|

	// float
	cout << "|" << 1.20000 << "|" << endl;       // |1.2| (nevýznamné nuly nejsou zobrazeny)
	cout << "|" << 1.23456 << "|" << endl;       // |1.23456| (defaultní přesnost 6 číslic včetně desetinného oddělovače)
	cout << "|" << -1.23456 << "|" << endl;      // |-1.23456| (znaménko se do přesnosti nepočítá)
	cout << "|" << 1.234567 << "|" << endl;      // |1.23457|
	cout << "|" << 123456.7 << "|" << endl;      // |123457|
	cout << "|" << 1234567.89 << "|" << endl;    // |1.23457e+006| (scientific notace pro e>=6)
	cout << "|" << 0.0001234567 << "|" << endl;  // |0.000123457|  (významné nuly se do přesnosti nepočítají)
	cout << "|" << 0.00001234567 << "|" << endl; // |1.23457e-005| (scientific notace pro e<=-5)

	// setw
	cout << "|" << setw(5) << 123 << "|" << 123 << endl;  // |  123|123 (setw() platí jen pro jeden následující formátovaný výpis)
	cout << "|" << setw(5) << -123 << "|" << endl;        // | -123|123 (znaménko se do délky pole nezapočítává)
	cout << "|" << setw(5) << 1234567 << "|" << endl;     // |1234567|  (data se nezkracují)

	// setfill, alignment
	cout << setfill('_');   // platí pro všechny následující formátované výpisy
	cout << setw(6) << 123 << setw(4) << 12 << endl;      // ___123__12
	cout << left;           // zarovnání doleva, platí pro všechny následující formátované výpisy
	cout << setw(6) << 123 << setw(4) << 12 << endl;      // 123___12__

	// alignment (left|right|internal)
	cout << showpos;  // ukaž znaménko vždy
	cout << '|' << setw(6) << 123 << '|' << endl;              // |  +123| (default alignment)
	cout << left << '|' << setw(6) << 123 << '|' << endl;      // |+123  |
	cout << right << '|' << setw(6) << 123 << '|' << endl;     // |  +123|
	cout << internal << '|' << setw(6) << 123 << '|' << endl;  // |+  123|

	// fixed-point formátování
	cout << fixed;
	cout << "|" << 1234567.89 << "|" << endl;    // |1234567.890000| (6 číslic za desetinným oddělovačem)
 
	// scientific formátování
	cout << scientific;   
	cout << "|" << 1234567.89 << "|" << endl;    // |1.234568e+006| (6 číslic za desetinným oddělovačem)
         
 
	// setprecision
	cout << fixed << setprecision(2);   // sticky
	cout << "|" << 123.456789 << "|" << endl;  // |123.46|
	cout << "|" << 123. << "|" << endl;        // |123.00|
 
	cout << setprecision(0);
	cout << "|" << 123.456789 << "|" << endl;  // |123|

	cout << 1234 << endl;                      // 1234 (default is dec)
	cout << hex << 1234 << endl;               // 4d2
	cout << 1234 << "," << -1234 << endl;      // 4d2, fffffb2e, záporné číslo ve dvojkovém doplňku
	cout << oct << 1234 << endl;               // 2322
	cout << 1234 << "," << -1234 << endl;      // 2322,37777775456
	cout << setbase(10) << 1234 << endl;       // 1234 (setbase vyžaduje <iomanip>)
 
	// showbase - zobraz hex s 0x prefixem; oct s 0 prefixem
	cout << showbase << 123 << "," << hex << 123 << "," << oct << 123 << endl;  // 123,0x7b,0173
	cout << noshowbase << dec;
 
	// showpos - ukaž znaménko u kladných čísel
	cout << showpos << 123 << endl;  // +123
 
	// uppercase 
	cout << uppercase << hex << 123 << endl;  // 7B

	// boolalpha - zobraz bool jako true/false
	cout << boolalpha << false << "," << true << endl;   // false,true
	cout << noboolalpha << false << "," << true << endl; // 0,1

	return 0;
}