#include <iostream>
#include <regex>
#include <iomanip>
#include <sstream>
#include "parse.hpp"

struct // Default values
{
    int min = -99;
    int max = 100;
    int width = 3;
    bool align = false; // left: false, right: true
} myCfg;

class Table {
public:
    int elCount, cellSize;

    void printRow(int elCount, int cellSize) {
        cellSize += 2;
        for (int i; i < elCount + 1; i++) {
            std::cout << "+" << std::string(cellSize, '-');
        }
        std::cout << "+\n";
    }
};

int chToInt(char input) {
    return input - 65;
};

int main() {
    // variable for decoded config
    config_t config;
    std::string line;
    do // parse the configuration
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

    // print out the my configuration
    std::cout << "config.min=" << myCfg.min << std::endl;
    std::cout << "config.max=" << myCfg.max << std::endl;
    std::cout << "config.width=" << myCfg.width << std::endl;
    if (myCfg.align)
        std::cout << "config.align=right\n"
                  << std::endl;
    if (!myCfg.align)
        std::cout << "config.align=left\n"
                  << std::endl;


    // declare the table
    Table myTable;
    myTable.cellSize = myCfg.width;
    for (auto i: values) {
        if (i.size() > myTable.elCount)
            myTable.elCount = i.size();
    }

    // print table
    for (std::size_t i = 0; i < values.size(); i++) {
        myTable.printRow(myTable.elCount, myTable.cellSize);
        for (std::size_t j = 0; j < values[i].size(); j++) {
            if (j == 0)
                std::cout << "| " << std::setw(myTable.cellSize) << values[i][j] << " | ";
            else std::cout << std::setw(myTable.cellSize) << values[i][j] << " | ";
            // sums
        }
        std::cout << std::endl;
    }
    myTable.printRow(myTable.elCount, myTable.cellSize);

    return 0;
}
