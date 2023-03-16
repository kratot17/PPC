#include <iostream>
#include <iomanip>
#include <map>

int main()
{
    std::multimap<std::string, int> M = {{"Budejovice", 100000}, {"Ostrava", 900000}};
    M.insert({"Praha", 1300000});
    M.insert({"Plzen", 600000});
    M.insert({"Brno", 800000});
    M.insert({"Plzen", 750000});


    // prochazeni kontejneru
    for (auto i : M)
    {
        std::cout << std::left << std::setw(12) << i.first << " " << i.second << std::endl;
    }
    std::cout << "\nhledam prvni vystkyt Plzen" << std::endl;
    // najde prvni vyskyt paru s klicem "Plzen"
    auto i = M.find("Plzen");
    // navratova hodnota je iterator (-> ukazatel)
    std::cout << std::left << std::setw(12) << i->first << " " << i->second << std::endl;
    // protoze je kontejner razen podle klice, lze pak prozkoumat jeste dalsi
    // prvky, jestli nahodou nejsou taky s danym klicem (u std::multimap)


    // v std::multimap lze mit duplicitni klice a tak ma smysl hledat vsechny
    std::cout << "\nhledam vsechny vyskyty Plzen" << std::endl;
    // vyuzijeme funkci equal_range, ktera vraci par iteratoru
    typedef std::multimap<std::string, int>::iterator mit;
    std::pair<mit, mit> nalez = M.equal_range("Plzen");
    // pocet nalezenych vysledku lze zjistit jako vzdalenost mezi 
    std::cout << "pocet nalezu: " << std::distance(nalez.first, nalez.second) << std::endl;
    // vypis nalezu zaznamu s klicem Plzen
    for (mit i = nalez.first; i != nalez.second; i++)
        std::cout << std::left << std::setw(13) << i->first << " " << i->second << std::endl;


    return 0;
}
