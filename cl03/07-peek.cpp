 /*
 * http://www.cplusplus.com/reference/istream/istream/peek/
 *
 */

#include <iostream>     // std::cin, std::cout
#include <string>       // std::string
#include <cctype>       // std::isdigit

int main () {

	std::cout << "Napiste cislo nebo slovo: ";
	std::cout.flush();    // vynucené vyprázdnění výstupního bufferu    

	std::cin >> std::ws;  // odstranění bílých znaků
	int c = std::cin.peek();  // vyzvednutí prvního znaku

	if ( c == EOF ) return 1;
  
	if ( std::isdigit(c) )
  	{
    		int n;
    		std::cin >> n;
    		std::cout << "Napsal jsi číslo: " << n << '\n';
  	}
  	else
  	{
    		std::string str;
    		std::cin >> str;
    		std::cout << "Napsal jsi slovo: " << str << '\n';
  	}

	return 0;
}