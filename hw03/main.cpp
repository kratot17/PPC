#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include "main.hpp"

Database::Database() {
}

// add item to the database
void Database::add(Item *a) {
    db.push_back(a);
}

void Database::sort(std::string sort_by, std::string sort_order) {
//    std::cout << "I want to sort by: " << sort_by << " Order will be: " << sort_order << std::endl;
    bool change_was_made = true;
    if (sort_by == "id") {}
    else if (sort_by == "name") {
        while (change_was_made) {
            for (int i = 0; i < db.size() - 1; ++i) {
                if (sort_name()) {
                    change_was_made = true;
                } else change_was_made = false;
            }
        }
    } else if (sort_by == "year") {}
}

// sorting functions
bool sort_id::operator()(const Item *a, const Item *b) {
    return a->ID > b->ID;
}

bool sort_name::operator()(const Item *a, const Item *b) {
    return a->name.compare(b->name);
}

bool sort_year::operator()(const Item *a, const Item *b) {
    return a->year.compare(b->year);
}

// constructor of the Item class
Item::Item(std::string a, std::string b) {
    name = a;
    year = b;
}

Item::~Item() {
}

// printing functions
void print_header(std::string argument) {
    std::cout << "+" << std::string(58, '-') << "+\n";
    std::cout << "| " << std::setfill(' ') << std::left << std::setw(57) << argument << "|\n";
}

void print_footer(std::string argument) {
    std::cout << "| " << std::setfill(' ') << std::left << std::setw(57) << argument << "|\n";
    std::cout << "+" << std::string(58, '-') << "+\n";
}

void Item::print_info() {}

void Book::print_info() {
    std::cout << "+" << std::string(4, '-') << "+" << std::string(53, '-') << "+\n";
    std::string line = year + ", " + author;
    std::cout << "| " << std::setfill(' ') << std::setw(2) << std::right << ID << " | " << std::left << std::setw(52)
              << name << "|\n" << "|" << std::string(4, ' ') << "| " << std::setw(52) << line << "|" << std::endl;
}

void Journal::print_info() {
    std::cout << "+" << std::string(4, '-') << "+" << std::string(53, '-') << "+\n";
    std::string line = year + ", " + volume + "(" + issue + ")";
    std::cout << "| " << std::setfill(' ') << std::setw(2) << std::right << ID << " | " << std::left << std::setw(52)
              << name << "|\n" << "|" << std::string(4, ' ') << "| " << std::setw(52) << line << "|" << std::endl;
}

// ID initializing functions
void Item::set_id(int i) {}

void Book::set_id(int i) {
    ID = i + 1;
}

void Journal::set_id(int i) {
    ID = i + 1;
}

// search functions
bool Book::search(std::string argument) {
    std::stringstream ss;
    ss << year << ", " << name << ", " << author;
    if (ss.str().find(argument) != std::string::npos)
        return true;
    else
        return false;
}

bool Journal::search(std::string argument) {
    std::stringstream ss;
    ss << year << ", " << name << ", " << issue << ", " << volume;
    if (ss.str().find(argument) != std::string::npos)
        return true;
    else
        return false;
}

bool Item::is_id(int id) { return 0; }

bool Book::is_id(int id) {
    return (id == ID);
}

bool search(std::string key, std::string string[]) {
    for (int i = 0; i < (int) string->size(); i++) {
        if (string[i] == key) {
            return true;
        }
    }
    return false;
}


bool Journal::is_id(int id) {
    return (id == ID);
}

// main functions
void Database::list() {
    int elCount = 0;
    print_header("List of all records");
    for (int i = 0; i < (int) db.size(); i++) {
        db[i]->print_info();
        elCount++;
    }
    std::cout << "+" << std::string(4, '-') << "+" << std::string(53, '-') << "+\n";
    print_footer("Total: " + std::to_string(elCount));
}

void Database::find(const std::string &key) {
    print_header("Search for \"" + key + "\"");
    int elCount = 0;
    for (int i = 0; i < (int) db.size(); i++) {
        if (db[i]->search(key)) {
            db[i]->print_info();
            elCount++;
        }
    }
    std::cout << "+" << std::string(4, '-') << "+" << std::string(53, '-') << "+\n";
    print_footer("Total: " + std::to_string(elCount));
}

void Database::erase(const std::string &key) {
    bool item_erased;
    do {
        item_erased = false;
        for (int i = 0; i < (int) db.size(); i++) {
            if (db[i]->search(key)) {
                db.erase(db.begin() + i);
                item_erased = true;
            } else {
                continue;
            }
        }
    } while (item_erased);
}

void Database::remove(const std::string &id) {
    bool item_removed = false;
    for (int i = 0; i < (int) db.size(); i++) {
        if (db[i]->is_id(std::stoi(id))) {
            db.erase(db.begin() + i);
            item_removed = true;
        } else {
            continue;
        }
    }
    if (!item_removed) { // if no item was removed
        print_header("ID = " + id + " is not in the database");
        std::cout << "+" << std::string(58, '-') << "+\n";
    }
}

void Database::set_id() {
    for (int i = 0; i < (int) db.size(); i++) {
        db[i]->set_id(i);
    }
}

Database::~Database() {
    for (auto i = db.begin(); i != db.end(); i++) {
        delete *i;
    }
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
    db.set_id();

    std::string commands_req_arg[3] = {"find", "erase", "remove"};
    std::string a;
    while (std::getline(std::cin, a)) {
        size_t position;
        if ((position = a.find(":")) == std::string::npos) {
            if (a == "list")
                db.list();
            else if (search(a, commands_req_arg)) {
                print_header("Command \"" + a + "\" expects some argument");
                std::cout << "+" << std::string(58, '-') << "+\n";
            } else if (a == "sort") {
                print_header("Unknown sorting order");
                std::cout << "+" << std::string(58, '-') << "+\n";
            } else {
                print_header("Unknown command \"" + a + "\"");
                std::cout << "+" << std::string(58, '-') << "+\n";
            }
        } else {
            std::string command = a.substr(0, position);
            std::string argument = a.substr(position + 1);
            if (command == "find")
                db.find(argument);
            else if (command == "erase")
                db.erase(argument);
            else if (command == "remove") {
                db.remove(argument);
            } else if (command == "sort") {
                if ((position = argument.find(":")) == std::string::npos) {
                    db.sort(argument, "asc"); // default sorting: ascending
                } else {
                    std::string sort_by = argument.substr(0, position);
                    std::string sort_order = argument.substr(position + 1);
                    db.sort(sort_by, sort_order);
                }
            }
        }
    }
    return 0;
}

