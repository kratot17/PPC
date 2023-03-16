#include <iostream>
using namespace std;

struct Struktura
{
    int defvar; // defaultni viditelnost je public
    Struktura() {defvar = 1; cout << "Konstruktor Struktury" << endl;} // neparametricky konstrutor
    ~Struktura() { cout << "Destruktor Struktury" << endl;}
};

class Trida
{
    int defvar; // defaultni viditelnost je private
    public: 
        Trida() {defvar = 2; cout << "Konstruktor Tridy" << endl;} // neparametricky konstrutor
        Trida(int x);  // parametricky konstrutor - deklarace
        ~Trida() { cout << "Destruktor Tridy" << endl;}
        int  get_defvar() const {return this->defvar;}  // this je ukazatel na aktualni instanci
            //const rika, ze objekt je pro tuto funkci read-only
        void set_defvar(int x) {defvar = x;}
        int a;
};

Trida::Trida(int x) // definice parametrickeho konstruktoru
{
    this->defvar = x; 
    cout << "Parametricky konstruktor Tridy" << endl;
}


int main()
{
    Struktura sa; // Staticka alokace
    sa.defvar = 10;

    Struktura * ps = new Struktura(); // Dynamicka alokace
    ps->defvar = 12;

    Trida ta;
    //ta.defvar = 10; // nelze, protoze je private
    ta.a = 12;
    ta.set_defvar(8);

    Trida tb(12);

    Trida* pt = new Trida(15);

    cout << "sa.defvar = " << sa.defvar << endl;
    cout << "ps->defvar = " << ps->defvar << endl;
    cout << "ta.a = " << ta.a << endl;
    cout << "ta.defvar = " << ta.get_defvar() << endl;
    cout << "tb.defvar = " << tb.get_defvar() << endl;
    cout << "pt->defvar = " << pt->get_defvar() << endl;

    delete ps; // Uvolneni pameti
    delete pt;
    
    return 0;
}
