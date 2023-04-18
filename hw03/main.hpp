#include <vector>
#include <string>

#ifndef __MAIN_HPP__
#define __MAIN_HPP__

struct sort_name;

class Item {
protected:
    int ID;
public:
    std::string name, year;
    Item(std::string a, std::string b);

    virtual ~Item();

    friend sort_name;
};

// Book related to the Database
class Book : public Item {
public:
    Book(std::string title, std::string author, std::string year)
            : Item(title, year), author(author) {}

    std::string getAuthor() const { return author; }

private:
    std::string author;
};

// Journal related to the Database
class Journal : public Item {
public:
    Journal(const std::string& name, const std::string& volume, const std::string& issue, const std::string& year)
            : Item(name, year), volume(volume), issue(issue) {}
    std::string volume;
    std::string issue;
};

// declaration of the sort function according to name
struct sort_name {
    inline bool operator()(const Item *a, const Item *b);
};

class Database {
private:
    std::vector<Item *> db;
public:
    // put db.find and db.list here
    Database();

    void add(Item *a);

    void list(); // declaration of list method
    void find(const std::string &name); // declaration of find method
    ~Database(); // declare destructor
};

#endif // __MAIN_HPP__