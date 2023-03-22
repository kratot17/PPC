#include <iostream>
#include <string>
#include <sstream>
#include <utility>
#include <vector>

class Config
{
public:
    bool isDefined;
    int value;
    std::string algn;
};

int main()
{
    std::string tmp, configStr, valuesStr;

    // config load
    while (std::getline(std::cin, tmp) && tmp.compare("=") != 0)
    {
        // line proces
        configStr += tmp + "\n";
    }
    std::cout << "configStr:\n"
              << configStr << std::endl;

    // values load
    while (std::getline(std::cin, tmp))
    {
        // line proces
        valuesStr += tmp + "\n";
    }
    std::cout << "valuesStr:\n"
              << valuesStr << std::endl;

    // parse & store values
    std::vector<std::vector<int>> numbers;         // Vector to store numeric values
    std::vector<std::vector<std::string>> strings; // Vector to store string values

    std::istringstream iss(valuesStr); // Create a string stream from the input

    std::string line;
    while (std::getline(iss, line))
    {                                  // Read input line by line
        std::vector<int> nums;         // Vector to store numeric values for the current line
        std::vector<std::string> strs; // Vector to store string values for the current line

        std::istringstream line_iss(line); // Create a string stream from the current line
        std::string token1;
        while (std::getline(line_iss, token1, ';'))
        { // Read line token1 by token1, separated by ';'
            if (token1.substr(0, 4) == "SUM(")
            { // If the token1 starts with "SUM(", it's a string
                strs.push_back(token1);
            }
            else
            {                                     // Otherwise, it's a numeric value
                nums.push_back(std::stoi(token1)); // Convert the token1 to an int and store it
            }
        }

        numbers.push_back(nums); // Store the numeric values for the current line
        strings.push_back(strs); // Store the string values for the current line
    }

    // Print the parsed values for debugging
    for (const auto &nums : numbers)
    {
        for (const auto &num : nums)
        {
            std::cout << num << ' ';
        }
        std::cout << '\n';
    }
    for (const auto &strs : strings)
    {
        for (const auto &str : strs)
        {
            std::cout << str << ' ';
        }
        std::cout << '\n';
    }

    // parse & store config
    std::stringstream ss2(configStr);
    Config min, max, width, align;
    std::string value;
    std::string token;

    while (std::getline(ss2, token, '\n'))
    {
        std::stringstream line(token);
        std::string key;
        std::getline(line, key, '=');

        if (key == "config.min")
        {
            min.isDefined = true;
            std::getline(line, value);
            min.value = std::stoi(value);
        }
        else if (key == "config.max")
        {
            max.isDefined = true;
            std::getline(line, value);
            max.value = std::stoi(value);
        }
        else if (key == "config.width")
        {
            width.isDefined = true;
            std::getline(line, value);
            width.value = std::stoi(value);
        }
        else if (key == "config.align")
        {
            align.isDefined = true;
            std::getline(line, align.algn);
        }
    }

    // Vypsání hodnot pro kontrolu
    std::cout << "config.min = " << min.value << " is defined: " << min.isDefined << std::endl;
    std::cout << "config.max = " << max.value << " is defined: " << max.isDefined << std::endl;
    std::cout << "config.width = " << width.value << " is defined: " << width.isDefined << std::endl;
    std::cout << "config.align = " << align.algn << " is defined: " << align.isDefined << std::endl;

    return 0;
}
