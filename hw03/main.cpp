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
    std::cout << "+" << std::string(4, '-') << "+" << std::string(53, '-') << "+\n";
}
void Journal::print_info()
{
    std::string line = year + ", " + volume + "(" + issue + ")";
    std::cout << "| " << std::setfill(' ') << std::setw(2) << std::right << ID << " | " << std::left << std::setw(52) << name << "|\n"
              << "|" << std::string(4, ' ') << "| " << std::setw(52) << line << "|" << std::endl;
    std::cout << "+" << std::string(4, '-') << "+" << std::string(53, '-') << "+\n";
}

void Database::list()
{
    int elCount = 0;
    std::cout << "+" << std::string(58, '-') << "+\n";
    std::cout << "| "
              << std::setfill(' ') << std::left << std::setw(57) << "List of all records"
              << "|\n";

    std::cout << "+" << std::string(4, '-') << "+" << std::string(53, '-') << "+\n";
    for (int i = 0; i < (int)db.size(); i++)
    {
        db[i]->print_info();
        elCount++;
    }
    std::cout << "| "
              << "Total: " << elCount << std::string(49, ' ') << "|" << std::endl;
    std::cout << "+" << std::string(58, '-') << "+\n";
}
void Book::set_id(int i){
    ID=i+1;
}
void Journal::set_id(int i){
    ID=i+1;
}
void Item::set_id(int i){}


bool Book::compare_argmunet(std::string argument)
{
    std::stringstream ss;
    ss << year << ", " << name << ", " << author;
    if (ss.str().find(argument) != std::string::npos)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Journal::compare_argmunet(std::string argument)
{
    std::stringstream ss;
    ss << year << ", " << name << ", " << issue <<", "<<volume;
    if (ss.str().find(argument) != std::string::npos)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void Database::find(const std::string &key)
{
    std::string line = "Search for \"" + key + "\"";

    int elCount = 0;
    std::cout << "+" << std::string(58, '-') << "+\n";
    std::cout << "| "
              << std::setfill(' ') << std::left << std::setw(57) << line << "|\n";
    std::cout << "+" << std::string(4, '-') << "+" << std::string(53, '-') << "+\n";
    for (int i = 0; i < (int)db.size(); i++)
    {
        if (db[i]->compare_argmunet(key)) // || db[i]->author add search variation
        {
            db[i]->print_info();
            elCount++;
        }
    }
    std::cout << "| "
              << "Total: " << elCount << std::string(49, ' ') << "|" << std::endl;
    std::cout << "+" << std::string(58, '-') << "+\n";
}

void Database::erase(const std::string &key)
{
    std::cout << "This is to be erased: " << key << std::endl;
  //  std::vector<int> to_destuct;
  std::cout<<db.size()<<std::endl;
    for (int i = 0; i < (int)db.size(); i++)
    {
        if (db[i]->compare_argmunet(key)) // || db[i]->author add erase variation
        {   
            delete db[i];
            db.erase();
        std::cout<<db.size()<<std::endl;
            for (int i = 0; i < (int)db.size(); i++)
            {
                std::cout<<db.size()<<std::endl;
                db[i]->print_info();
            }
            
            
        }else{
            continue;
        }
    }
    
    
}
void Database::set_id(){
for(int i=0;i<(int)db.size();i++){
    db[i]->set_id(i);
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
    db.set_id();
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
            else if (command == "erase")
                db.erase(argument);
            // put here other cmds
        }
    }
    return 0;
}
