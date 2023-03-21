#include <iostream>
#include <string>
#include <sstream>

int main() {
    std::string tmp = "", input;

    // Načtení vstupu dokud je to možné
    while (std::getline(std::cin, tmp) && tmp.compare("=") != 0) {
        // Zpracování načteného řádku
        input += tmp + "\n";
    }
    std::cout << "input:\n" << input << std::endl;

    // std::string input = "config.min=-99\nconfig.max=150\nconfig.width=3\nconfig.align=left";

    // Vytvoření stringstream objektu ze vstupního řetězce
    std::stringstream ss(input);
    std::string token;

    // Načtení jednotlivých hodnot ze stringstreamu a uložení do proměnných
    int config_min;
    int config_max;
    int config_width;
    std::string config_align = "none";

    while (std::getline(ss, token, '\n')) {
        std::stringstream line(token);
        std::string key;
        std::getline(line, key, '=');

        if (key == "config.min") {
            std::string value;
            std::getline(line, value);
            config_min = std::stoi(value);
        }
        else if (key == "config.max") {
            std::string value;
            std::getline(line, value);
            config_max = std::stoi(value);
        }
        else if (key == "config.width") {
            std::string value;
            std::getline(line, value);
            config_width = std::stoi(value);
        }
        else if (key == "config.align") {
            std::getline(line, config_align);
        }
    }

    // Vypsání hodnot pro kontrolu
    std::cout << "config.min = " << config_min << std::endl;
    std::cout << "config.max = " << config_max << std::endl;
    std::cout << "config.width = " << config_width << std::endl;
    std::cout << "config.align = " << config_align << std::endl;

    return 0;
}
