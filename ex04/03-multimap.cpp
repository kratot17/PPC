#include <iostream>
#include <ctime> // kvuli inicializaci nahodneho generatoru
#include <map>

int main()
{
    std::srand(std::time(nullptr)); // inicializace nahodneho generatoru

    std::multimap<std::string, int> M;
    
    for(int i=0; i<5;i++ )
        M.insert({"jablko", std::rand() % 30}); // nahodny int mezi 0-29 vcetne 
    for(int i=0; i<3;i++ )
        M.insert({"hruska", 30 + std::rand() % 15}); // nahodny int mezi 30-44 vcetne 
    for(int i=0; i<3;i++ )
        M.insert({"angrest", 45 + std::rand() % 15}); // nahodny int mezi 45-59 vcetne

    std::cout << "Hledam Hrusku pomoci find:\n";
    auto h = M.find("hruska"); // vraci iterator, potrebujeme potom pouzit ->
    std::cout << h->first << " | " << h->second <<std::endl;
    
    /* while (h != M.end())
    {
        std::cout << h->first << " | " << h->second <<std::endl;
        h++;
    } */ // takhle ziskame vsechny hrusky, ale i to, co je za nimi

    std::cout << "Hledam Hrusku pomoci equal_range:\n";
    auto p = M.equal_range("hruska"); // vraci par iteratoru, ktere vymezuji vyskyt hrusek v mape
    for(auto it = p.first; it != p.second; it++)
        std::cout << it->first << " | " << it->second <<std::endl;

    std::cout << "p.first ukazuje na prvni hrusku: " << p.first->first << " | " << p.first->second <<std::endl;
    std::cout << "p.second ukazuje na prvni ne-hrusku za radou hrusek: "<< p.second->first << " | " << p.second->second <<std::endl;

    return 0;
}