#include <iostream>
#include <iomanip>
#include <map>

int main()
{
    //std::map<std::string, int> M; 
    std::map<std::string, int> M = {{"Praha", 1300000},{"Ostrava",300000}};
    M["Brno"] = 400000;
    M["Plzen"] = 150000;
    M.insert(std::make_pair("As",20000));
    M["Praha"] = 1300001; // neexistuji duplicitni hodnoty, dojde k prepsani;
    M.insert({"Cernoucek", 297});

    // prochazeni kontejneru
    for(auto k:M)
        std::cout<<std::left << std::setw(12) << k.first << " | " << k.second <<std::endl;

    std::cout << "Hledam Plzen:\n";
    auto f = M.find("Plzen"); // vraci iterator, potrebujeme potom pouzit ->
    std::cout<<std::left << std::setw(12) << f->first << " | " << f->second <<std::endl;

    std::cout << "Hledam Londyn:\n";
    f = M.find("Londyn"); // pri nenalezeni se vrati iterator .end();
    if (f != M.end())
        std::cout<<std::left << std::setw(12) << f->first << " | " << f->second <<std::endl;
    else
        std::cout<< "** Londyn nebyl nalezen. Smula.**" <<std::endl;
        
    return 0;
}