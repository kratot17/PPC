#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include "main.hpp"

Database::Database() {
    // Database constructor
}

// add item to the database
void Database::add(Item *a) {
    db.push_back(a);
}

// definition of the sort function according to name
bool sort_name::operator()(const Item *a, const Item *b) {
    return true;
}

// constructor of the Item class
Item::Item(std::string a, std::string b){
}


void Database::list() {
    std::cout << "List of all items in the database:\n";
    for (const auto& item : db) {
        std::cout << item->name << ", " << item->year << "\n";
    }
}

void Database::find(const std::string& name) {
    std::cout << "Items with name \"" << name << "\":\n";
    for (const auto& item : db) {
        if (item->name == name) {
            std::cout << item->name << ", " << item->year << "\n";
        }
    }
}

Database::~Database() {
    for (auto i = db.begin(); i != db.end(); i++)
        delete *i;
    db.clear();
}

int main() {
    Database db;
    db.add(new Journal("IEEE Transaction on Computers", "C-35", "10", "1986"));
    db.add(new Journal("IEEE Transaction on Computers", "C-35", "11", "1986"));
    db.add(new Journal("IEEE Transactions on Communications", "28", "8", "1980"));
    db.add(new Book("Dva roky prazdnin", "Jules Verne", "1888"));
    db.add(new Book("Tajuplny ostrov", "Jules Verne", "1874"));
    db.add(new Book("Ocelove mesto", "Jules Verne", "1879"));
    std::string a;
    while (std::getline(std::cin, a)) {
        size_t position;
        if ((position = a.find(":")) == std::string::npos) {
            if (a == "list")
                db.list();
        } else {
            std::string command = a.substr(0, position);
            std::string argument = a.substr(position + 1);
            if (command == "find")
                db.find(argument);
            // put here other cmds
        }
    }
    return 0;
}
