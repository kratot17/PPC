#include <iostream>

class Jidlo {
private:
    int zdravi; 
    int kalorie;
public:
    Jidlo (int in_zdravi, int in_kalorie):zdravi(in_zdravi), kalorie(in_kalorie) {}
    int getZdravi () {return zdravi;}
    int getKalorie () {return kalorie;}
};

class Medved {
private:
    // dali jsme je private, protoze je budeme menit pouze pomoci metody snez
    // jinak nemaji jit modifikovat
    int zdravi;
    int kalorie;
public:
    // pokud nerekneme jinak, bude mit me2d na pocatku 50 kalorii
    Medved () {
        zdravi = 100;
        kalorie = 50;
        std::cout << "Mame noveho medveda s 50 kaloriemi" << std::endl;
    }
   
    // ale muze urcit jiny pocet
    Medved (int in_kalorie) {
        zdravi = 100;
        kalorie = in_kalorie;
        // bezne v konstruktorech a destruktorech nic nevypisujeme
        // toto je pouze na ukazku
        std::cout << "Mame noveho medveda s " << kalorie << " kaloriemi" << std::endl;
    }
   
    void snez (int in_kalorie, int in_zdravi) {
        zdravi  += in_zdravi;
        kalorie += in_kalorie;
    }
   
    // mohou si udelat sami doma
    void vypisInfoOMedvedovi() {
        std::cout << "Medved ma " << kalorie << " kalorii a ";
        std::cout << zdravi << "% zdravi." << std::endl;
    }
    
    ~Medved() {
        std::cout << "Medved sel spat s " << kalorie << " kaloriemi v brise" << std::endl;
    }
}; 

int main(void) {

    Medved* brumla;
    brumla = new Medved(100);
   
    // turista je kurak, proto pridava kalorie, ale ubira zdravi
    // pripomenout, ze deklarace a inicializace objetu se da spojit
    Jidlo* turista = new Jidlo(5000, -30);
    brumla->snez(turista->getKalorie(), turista->getZdravi());
    delete turista; // turista snezen
   
    brumla->vypisInfoOMedvedovi();
   
    // myska by lehka, ale pomerne zdrava
    Jidlo* mys = new Jidlo (60, 10);
    brumla->snez (mys->getKalorie(),mys->getZdravi());
    delete mys; // mys uz byla snezena
   
    // brumla->vypisInfoOMedvedovi();
   
    delete brumla; // konec me2da
    return 0;
}