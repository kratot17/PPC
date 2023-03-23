#include <iostream>
#include <string>
#include <regex>
#include <vector>
#include <iomanip>
#include "main.hpp"
#include "parse.hpp"

struct // Default values
{
    int min = -99;
    int max = 100;
    int width = 3;
    bool align = false; // left: false, right: true
} myCfg;

int chToInt(char input) {
    return input - 65;
};

int main() {
    // Variable for decoded config
    config_t config;
    std::string line;
    do // Parse the configuration
    {
        std::getline(std::cin, line);

        config = getConfig(line);
        if (config.valid) {
            if (config.type == "min")
                myCfg.min = stoi(config.value);
            if (config.type == "max")
                myCfg.max = stoi(config.value);
            if (config.type == "width")
                myCfg.width = stoi(config.value);
            if (config.type == "align") {
                if (config.value == "right")
                    myCfg.align = true;
                else
                    myCfg.align = false;
            }
        }
    } while (config.valid);

    std::vector <std::vector<int>> values;

    while (std::getline(std::cin, line)) {
        std::stringstream ss(line);
        std::vector<int> row;
        std::string cell;
        int number;

        while (std::getline(ss, cell, ';')) {
            try // If loaded cell is number
            {
                number = std::stoi(cell);
                row.push_back(number);
            }
            catch (const std::exception &e) // if there is a text (SUM?)
            {
                int sum = 1;
                row.push_back(sum);
            }
        }
        values.push_back(row);
    }

    // Print out the my configuration
    std::cout << "config.min=" << myCfg.min << std::endl;
    std::cout << "config.max=" << myCfg.max << std::endl;
    std::cout << "config.width=" << myCfg.width << std::endl;
    if (myCfg.align)
        std::cout << "config.align=right\n"
                  << std::endl;
    if (!myCfg.align)
        std::cout << "config.align=left\n"
                  << std::endl;

    // Print table
    for (std::size_t i = 0; i < values.size(); i++) {
        for (std::size_t j = 0; j < values[i].size(); j++) {
            std::cout << values[i][j] << " ";
            // Tady budu resit sumy
        }
        std::cout << std::endl;
    }

    return 0;
}
