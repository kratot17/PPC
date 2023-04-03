#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<iterator>

struct Strana{
    std::string text;
    std::vector<int> rozcestnik;
};

struct Hra{
    std::vector<Strana> scenar;
    int volba;

    void nacti (std::string filename);
    void hraj (int next = 0);
};



int main()
{
    Hra h;
    // nacteme hru ze souboru
    h.nacti("scenar.txt");
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
        std::getline(ifstr, tmp.text);

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
    
}