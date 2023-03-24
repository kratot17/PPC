#include <iostream>
#include <regex>
#include <iomanip>
#include <sstream>
#include <regex>
#include "parse.hpp"

struct // Default values
{
    int min = -99;
    int max = 100;
    int width = 3;
    bool align = false; // left: false, right: true
} myCfg;

class Table {
private:
    char colIdx = 'A';
public:
    int elCount, cellSize;
    void printRow(int elCount, int cellSize) {
        for (int i = 0; i < elCount + 1; i++) {
            std::cout << "+" << std::string(cellSize + 2, '-');
        }
        std::cout << "+\n";
    }

    void printHdr(int elCount, int cellSize, bool align) {
        printRow(elCount, cellSize);
        std::cout << "|" << std::string(cellSize + 2, ' ');
        if (align) {
            for (int i = 0; i < elCount; i++) {
                std::cout << "| " << std::setw(cellSize) << colIdx++ << " ";
            }
        } else {
            for (int i = 0; i < elCount; i++) {
                std::cout << "| " << std::left << std::setw(cellSize) << colIdx++ << " ";
            }
        }
        std::cout << "|\n";
    }
};

int chToInt(char input) {
    return input - 65;
};

int main() {
    // variable for decoded config
    config_t config;
    std::string line;
    // parse the configuration
    do {
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

    // look for errors in configuration
    if (myCfg.min > myCfg.max || myCfg.width < 0) {
        std::cerr << "Invalid configuration" <<
                  std::endl;
        return 102;
    }

    // parse the data
    std::vector <std::vector<int>> values;
    std::regex regex("SUM\\((\\w+):(\\w+)\\)"); // define a regex pattern
    std::smatch match; // define a variable to store the match

    while (std::getline(std::cin, line)) {
        std::stringstream ss(line);
        std::vector<int> row;
        std::string cell;
        int number, sum, sumFromIdx, sumToIdx, elIdx;

        while (std::getline(ss, cell, ';')) {
            try { // If loaded cell is number
                number = std::stoi(cell);
                row.push_back(number);
            }
            catch (const std::exception &e) { // if loaded cell is not an int
                if (std::regex_search(cell, match, regex)) { // search for a match
                    sumFromIdx = chToInt(match[1].str()[0]); // extract the first capture group
                    sumToIdx = chToInt(match[2].str()[0]); // extract the second capture group
                } else {
                    std::cerr << "Invalid input" <<
                              std::endl;
                    return 101;
                }
                sum = 0;
                for (auto i: row) {
                    if (sumToIdx + 1 > row.size()) {
                        std::cerr << "Invalid input" <<
                                  std::endl;
                        return 101;
                    }
                    if (elIdx >= sumFromIdx && elIdx <= sumToIdx) {
                        sum += i;
                    }
                }
                row.push_back(sum);
            }
        }
        values.push_back(row);
    }

    // check for input range and cell size error
    for (auto i: values) {
        for (auto j: i) {
            if (j > myCfg.max || j < myCfg.min) {
                std::cerr << "Out of range" << std::endl;
                return 100;
            } else if (std::to_string(j).length() > myCfg.width) {
                std::cerr << "Cell is too short" << std::endl;
                return 103;
            }
        }
    }

    // print out the my configuration
    std::cout << "config.min=" << myCfg.min << std::endl;
    std::cout << "config.max=" << myCfg.max << std::endl;
    std::cout << "config.width=" << myCfg.width << std::endl;
    if (myCfg.align)
        std::cout << "config.align=right\n" << std::endl;
    if (!myCfg.align)
        std::cout << "config.align=left\n" << std::endl;

    // declare the table
    Table myTable;
    myTable.cellSize = myCfg.width;
    for (
        auto i: values) {
        if (i.size() > myTable.elCount)
            myTable.elCount = i.size();
    }

    // print table
    myTable.printHdr(myTable.elCount, myTable.cellSize, myCfg.align);
    for (std::size_t i = 0; i < values.size(); i++) {
        myTable.printRow(myTable.elCount, myTable.cellSize);
        if (myCfg.align)
            std::cout << "| " << std::setw(myTable.cellSize) << i + 1 << " ";
        else
            std::cout << "| " << std::left << std::setw(myTable.cellSize) << i + 1 << " ";
        for (std::size_t j = 0; j < myTable.elCount; j++) {
            if (myCfg.align) {
                if (values[i].size() <= j) { // blanks
                    // std::cout << "| " << std::string(myTable.cellSize, ' ') << " ";
                } else {
                    std::cout << "| " << std::setw(myTable.cellSize) << values[i][j] << " ";
                }
            } else {
                if (values[i].size() <= j) // blanks
                    std::cout << "| " << std::string(myTable.cellSize, ' ') << " ";
                else
                    std::cout << "| " << std::left << std::setw(myTable.cellSize) << values[i][j] << " ";
            }
        }
        std::cout << "|" << std::endl;
    }
    myTable.printRow(myTable.elCount, myTable.cellSize);

    return 0;
}
