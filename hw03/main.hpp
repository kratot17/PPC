#include <vector>
#include <string>

#ifndef __MAIN_HPP__
#define __MAIN_HPP__

struct sort_name;

class Item
{
protected:
    int ID;

public:
    std::string name, year;
    Item(std::string a, std::string b) {
        
    };

    virtual ~Item();
    virtual void print_info() = 0;

    friend sort_name;
};

class Book : public Item
{
public:
    std::string author;
    Book(std::string name, std::string author, std::string year) : Item(name, year), author(author) {}
    void print_info() override;
};

class Journal : public Item
{
public:
    std::string volume;
    std::string issue;
    Journal(std::string name, std::string volume, std::string issue, std::string year) : Item(name, year), volume(volume), issue(issue) {}
    void print_info() override;
};

// declaration of the sort function according to name
struct sort_name
{
    inline bool operator()(const Item *a, const Item *b);
};

class Database
{
private:
    std::vector<Item *> db;

public:
    // put db.find and db.list here
    Database();

    void add(Item *a);

    void list();                        // declaration of list method
    void find(const std::string &key); // declaration of find method
    void erase(const std::string &key); // declaration of erase method
    ~Database();                        // declare destructor
};

#endif // __MAIN_HPP__