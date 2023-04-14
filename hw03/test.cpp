//
// Created by Tomáš Kratochvíle on 14.04.2023.
//
#include <iostream>
#include <regex>
#include <string>


std::string *getInput() {
    // get line
    std::string line;
    getline(std::cin, line);
    // parse and process input
    std::regex pattern("(\\w+):(\\w+)");
    std::smatch matches;
    std::string *myArray = new std::string[3]; // myArray[0]: command, myArray[1]: parameter, myArray[2]: error message
    if (!std::regex_search(line, matches, pattern)) { // if input does not contains ":"
        if (line == "list") { // if input is "list"
            myArray[0] = line;
        }
    } else {
        myArray[0] = matches[1];
        myArray[1] = matches[2];
    }
    return myArray;
}

int main() {
    std::string *myArray = getInput();

    std::cout << myArray[0] << " " << myArray[1] << std::endl;

    delete[] myArray;
    return 0;
}
