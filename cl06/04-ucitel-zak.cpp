#include <iostream>

class Ucitel {
private:
    std::string jmeno;

public:
    Ucitel (std::string in_jmeno) {
        jmeno = in_jmeno;
    }

    std::string getJmeno() {
        return jmeno;
    }
};

class Zak {
private:
    Zak* soused;
    Ucitel* tridniUcitel;
    std::string jmeno;

public:   
    Zak (std::string in_jmeno, Ucitel* ucitel){
        jmeno = in_jmeno;
        tridniUcitel = ucitel;
        soused = 0;
    }

    void setSoused (Zak* novySoused) {
        soused = novySoused;
    }
       
    std::string getJmeno () {
        return jmeno;
    }

    std::string getJmenoSouseda (){
        return soused->getJmeno();
    }
   
    std::string getJmenoUcitele(){
        return tridniUcitel->getJmeno();
    }
};

int main (void) {
    Ucitel* pepaNovak = new Ucitel("Josef Novak");
   
    Zak* karlicek = new Zak("Karlicek Mackalu", pepaNovak);
    Zak* josifek = new Zak("Josifek Mackalu", pepaNovak);
   
    // priradime sousedy
    karlicek->setSoused(josifek);
    josifek->setSoused(karlicek);
   
    // vypiseme informace pro kontrolu
    std::cout << "Jmeno: " << josifek->getJmeno() << std::endl;
    std::cout << "Jmeno souseda: " << josifek->getJmenoSouseda() << std::endl;
    std::cout << "Jmeno ucitele: " << josifek->getJmenoUcitele() << std::endl;
   
    // prisly nove studentky
    Zak* majolenka = new Zak ("Majolenka Helmansu", pepaNovak);
    Zak* julinka = new Zak ("Julinka Kosu", pepaNovak);
   
    // a studenti se presadili...
    // zde je jasne patrna docasnost vazby
    // pozor nepoplest vazby
    karlicek->setSoused(majolenka);
    majolenka->setSoused(karlicek);
   
    josifek->setSoused(julinka);
    julinka->setSoused(josifek);
   
    // opet vypiseme
    // ...
   
    // nezapominame uvolnit pamet, objekty jsou na sobe nezavisle
    delete karlicek;
    delete josifek;
    delete pepaNovak;
    delete majolenka;
    delete julinka;
    return 0;
}