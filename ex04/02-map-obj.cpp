#include <iostream>
#include <map>

class Zviratko{
    std::string jmeno;
    int pocet_nozicek;
    int pocet_oci;

    public:
    Zviratko(std::string jm, int pn, int po): jmeno(jm), pocet_nozicek(pn), pocet_oci(po) {};
    bool operator< (const Zviratko & rhs) const {return this->jmeno < rhs.jmeno;} 

    friend std::ostream & operator<< ( std::ostream & os, const Zviratko & z); // friend funkce maji pristup k private/protected, ale nejsou clenske 
};

std::ostream & operator<< ( std::ostream & os, const Zviratko & z)
{
    os << "<" << z.jmeno << ": " << z.pocet_nozicek << " nozicek, " << z.pocet_oci << " oci>"; 
    return os;
}

int main(){
    std::map<Zviratko, int> Chov;
    Chov[Zviratko("jelen", 4, 2)] = 10;
    Chov[Zviratko("pavouk", 8, 20)] = 300;
    Chov[Zviratko("snek", 1, 2)] = 3;
    Chov[Zviratko("kocicka", 4, 2)] = 50;
    Chov[Zviratko("slepice", 2, 2)] = 20;
    Chov[Zviratko("stonozka", 100, 0)] = 100;
    Chov[Zviratko("superstonozka", 191*2, 0)] = 100;
    Chov[Zviratko("kyklop", 2, 1)] = 1;

    for(auto z:Chov)
        std::cout << z.first << " mame v chovu v poctu " << z.second << " kusu." << std::endl;

    // vyhledame jedno konkretni zviratko (nezalezi na poctu nozicek, protoze se vyhledava jen podle jmena)
    auto it =  Chov.find(Zviratko("jelen", 0, 0));
    std::cout << "Chov.find(Zviratko(\"jelen\", 0, 0)) -> " << it->first << " mame v chovu v poctu " << it->second << " kusu." << std::endl;
    
    
    // otestujeme zplozeni zviratka
    //Zviratko t("jelen",4,2);
    //std::cout << t << std::endl;
    return 0;
}
