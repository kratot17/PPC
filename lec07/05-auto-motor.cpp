#include <iostream>

class Motor {
private:
    int vykon;
    int pocetValcu;
   
public:
    Motor(int in_vykon, int in_pocetValcu) {
        vykon = in_vykon;
        pocetValcu = in_pocetValcu;
    }

    int getVykon() {
        return vykon;
    }

    int getPocetValcu() {
        return pocetValcu;
    }
};

class Auto {
private:
    Motor* motor;
    std::string SPZ;

public:   
    // konstruktor celku musi vyzadat veskere informace i pro soucasti
    Auto (int in_vykon, int in_pocetValcu, std::string in_SPZ) {
        SPZ = SPZ;
        motor = new Motor (in_vykon, in_pocetValcu);
    }

    // zde poprve opravdu smyslupne vyuzijeme destruktor
    ~Auto() {
        delete motor;
    }
   
    // pro pristup k vlastnostem soucasti je nutne udelat rozhrani
    int getVykonMotoru() {
        return motor->getVykon();
    }
   
    int getPocetValcu() {
        return motor->getPocetValcu();
    }
   
    std::string getSPZ() {
        return SPZ;
    }
};

int main(void){
    // nyni vzniklo auto a s nim i jeho motor
    Auto* audi = new Auto(105, 4, "007 BOREC");

    // zde je dukaz
    std::cout << "Vykon motoru: " << audi->getVykonMotoru() << std::endl;
   
    // a nyni zanikl i motor
    delete audi;
    return 0;
}