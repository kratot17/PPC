#include <iostream>
#include <vector>
#include <variant>

// Storing string and int values to the same vector
// Impement that to main.cpp

int main() {
    std::vector<std::variant<int, std::string>> values;

    // Add some values to the vector
    values.push_back(42);
    values.push_back("hello");
    values.push_back(3);

    // Access the values in the vector
    for (const auto& value : values) {
        if (auto* ptr = std::get_if<int>(&value)) {  // Check if the value is an int
            std::cout << "int: " << *ptr << '\n';
        } else if (auto* ptr = std::get_if<std::string>(&value)) {  // Check if the value is a string
            std::cout << "string: " << *ptr << '\n';
        }
    }

    return 0;
}
