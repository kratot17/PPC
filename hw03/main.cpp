#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include "main.hpp"

Database::Database()
{
    // Database constructor
}

// add item to the database
void Database::add(Item *a)
{
    db.push_back(a);
}

// definition of the sort function according to name
bool sort_name::operator()(const Item *a, const Item *b)
{
    return true;
}

// constructor of the Item class
Item::Item(std::string a, std::string b)
{
    name = a;
    year = b;
}

Item::~Item()
{
}

void Item::print_info() {}
void Book::print_info()
{
    std::string line = year + ", " + author;
    std::cout << "| " << std::setfill(' ') << std::setw(2) << std::right << ID << " | " << std::left << std::setw(52) << name << "|\n"
              << "|" << std::string(4, ' ') << "| " << std::setw(52) << line << "|" << std::endl;
}
void Journal::print_info()
{
    std::string line = year + ", " + volume + "(" + issue + ")";
    std::cout << "| " << std::setfill(' ') << std::setw(2) << std::right << ID << " | " << std::left << std::setw(52) << name << "|\n"
              << "|" << std::string(4, ' ') << "| " << std::setw(52) << line << "|" << std::endl;
}

void Database::list()
{
    int elCount = 0;
    std::cout << "+" << std::string(58, '-') << "+\n";
    std::cout << "| "
              << "List of all records" << std::string(38, ' ') << "|\n";
    std::cout << "+" << std::string(4, '-') << "+" << std::string(53, '-') << "+\n";
    for (int i = 0; i < (int)db.size(); i++)
    {
        db[i]->print_info();
        std::cout << "+" << std::string(4, '-') << "+" << std::string(53, '-') << "+\n";
        elCount = i + 1;
    }
    std::cout << "| "
              << "Total: " << elCount << std::string(49, ' ') << "|" << std::endl;
    std::cout << "+" << std::string(58, '-') << "+\n";
}

void Database::find(const std::string &name)
{
    std::cout << "Items with name \"" << name << "\":\n";
    for (const auto &item : db)
    {
        if (item->name == name)
        {
            std::cout << item->name << ", " << item->year << "\n";
        }
    }
}

Database::~Database()
{
    for (auto i = db.begin(); i != db.end(); i++)
        delete *i;
    db.clear();
}

int main()
{
    Database db;
    db.add(new Journal("IEEE Transaction on Computers", "C-35", "10", "1986"));
    db.add(new Journal("IEEE Transaction on Computers", "C-35", "11", "1986"));
    db.add(new Journal("IEEE Transactions on Communications", "28", "8", "1980"));
    db.add(new Book("Dva roky prazdnin", "Jules Verne", "1888"));
    db.add(new Book("Tajuplny ostrov", "Jules Verne", "1874"));
    db.add(new Book("Ocelove mesto", "Jules Verne", "1879"));
    std::string a;
    while (std::getline(std::cin, a))
    {
        size_t position;
        if ((position = a.find(":")) == std::string::npos)
        {
            if (a == "list")
                db.list();
        }
        else
        {
            std::string command = a.substr(0, position);
            std::string argument = a.substr(position + 1);
            if (command == "find")
                db.find(argument);
            // put here other cmds
        }
    }
    return 0;
}
