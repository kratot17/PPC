#include <iostream>
using namespace std;

class Ovoce 
{
    protected:
        int pocet_seminek; // je dostupne v potomcich objektu
    public:
        // Ovoce():pocet_seminek(1) {cout << "Vytvarim Ovoce" << endl; }
        Ovoce(int x = 1):pocet_seminek(x) {cout << "Vytvarim Ovoce" << endl; }
        ~Ovoce() {cout << "Kompostuji Ovoce" << endl; }
        void rozrizni() {cout << "Z ovoce vypadlo " << pocet_seminek << " seminek." << endl; pocet_seminek = 0;}
};

class Jablko : public Ovoce
{
    /* Rezimy dedeni:
    * public - zachovava puvodni viditelnost 
    * protected - public -> private
    * private - vsechno z parent objektu je private
    */
    public:
        double prumer;
        Jablko(double p = 8.0, int x = 6):Ovoce(x), prumer(p) {cout << "Vytvarim Jablko" << endl; }
        ~Jablko() {cout << "Kompostuji Jablko" << endl; }
        void rozrizni() {cout << "Z jablka o prumeru " << prumer <<" cm vypadlo " << pocet_seminek << " seminek." << endl; pocet_seminek = 0;}
        void spadni_na_hlavu () {cout << "Gravitaci uz objevil Newton. Smula." << endl;}
};

int main()
{
    Ovoce svestka;
    Ovoce meloun(150);
    Jablko j1(10.1,7);
    Jablko j2; // u volani neparametrickeho konstruktoru nejsou zavorky

    meloun.rozrizni();
    svestka.rozrizni();
    j1.spadni_na_hlavu();
    j1.rozrizni(); // vola se  Jablko::rozrizni()
    j2.Ovoce::rozrizni(); // vola se funkce rodicovskeho objektu

    return 0;
}