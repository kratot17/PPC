//
// Created by Tomáš Kratochvíle on 05.04.2023.
//
#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream source("routing.txt");
    std::ofstream dst("dst.txt");
    if (!source.is_open()) {
        std::cerr << "Failed to open source." << std::endl;
        return 1;
    }
    if (!dst.is_open()) {
        std::cerr << "Failed to create dst." << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(source, line)) {
        std::cout << "cout << \"" << line << "\" << endl;" << std::endl;
        dst << "cout << \"" << line << "\" << endl;" << std::endl;
    }

    source.close();
    dst.close();

    return 0;
}
