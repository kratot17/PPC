#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<iterator>
#include<map>
#include<sstream>

struct Strana{
    std::string text;
    std::vector<int> rozcestnik;
    std::vector<std::string> kramy;
};

struct Hra{
    std::vector<Strana> scenar;
    int volba;
    std::map<std::string, int> inventar; // ohlida duplicity

    void nacti (std::string filename);
    void hraj (int next = 0);
};



int main()
{
    Hra h;
    // nacteme hru ze souboru
    h.nacti("scenar-inv.txt");
    // spustime hru
    h.hraj();
    return 0;
}

void Hra::nacti (std::string filename)
{
    std::ifstream ifstr(filename);
    int pocet_voleb;
    char c;
    if (!ifstr.good())
    {
        std::cerr << "Soubor se nepodarilo otevrit pro cteni\n";
        return;
    }

    while (!ifstr.eof())
    {
        Strana tmp;
        std::string radek_veci;
        std::string vec;
        std::getline(ifstr, tmp.text);

        std::getline(ifstr, radek_veci);
        std::stringstream ss(radek_veci);
        while( std::getline(ss, vec, ';'))
            tmp.kramy.push_back(vec);

        // kontrola
        //for (auto k :tmp.kramy)
        //    std::cout << k << "; ";
        //std::cout << std::endl;

        ifstr >> pocet_voleb; // prectem prvni cislo z radku = pocet voleb
        if (pocet_voleb > 0)
            std::copy_n(std::istream_iterator<int>(ifstr), pocet_voleb, std::back_inserter(tmp.rozcestnik));
            // cteme int pomoci iteratoru ze souboru a vkladame pomoci bac_inserteru do rozcestniku

        do{
            ifstr.get(c); // precteme jeden znak
        } while (c != '\n'); // po poruseni podminky budeme na zacatku dalsiho radku

        // kontrola
        // for (auto r :tmp.rozcestnik)
        //     std::cout << r << "; ";
        // std::cout << std::endl;
        this->scenar.push_back(tmp); // pridame naplnenou stranku na konec scenare
    }
}

void Hra::hraj (int next)
{
    const Strana * pstr;
    do
    {
        // precteme aktualni stranku
        pstr = & scenar.at(next); // at nam nedovoli slapnout mimo scenar
        std::cout << pstr->text << std::endl;
        // vypiseme predmety
        if (pstr->kramy.size() > 0)
        {
            std::cout << "Nasel jsi tyto kramy: ";
            for (auto k : pstr->kramy)
            {
                std::cout << k << "; ";
                auto it = this->inventar.find(k);
                if (it == this->inventar.end())
                    this->inventar.insert({k, 1}); // vlozime aktualni kram z cetnosti 1;
                else
                    it->second += 1; // u nalezeneho kramu, inkrementujeme cetnost o 1
            }
            std::cout << std::endl;
        }
        
        if (pstr->rozcestnik.size() > 0)
        {
            std::cout << "> ";
            // precteme volbu uzivatele
            std::cin >> this->volba;
            // odkazeme se na zvolenou stranku
            next = pstr->rozcestnik.at(volba-1); // volba je indexovana od 1, rozcestnik od 0
            std::cout << std::endl;
        } 
        else
            next=-1;        
    } while ( next > 0);

    std::cout << "Na svem velkolepem dobrodruzstvi jsi nasel tyto veci:\n";
    for (auto k : this->inventar )
        std::cout <<k.second << "x "<< k.first << std::endl; 
    
}