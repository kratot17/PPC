#include <vector>
#include <string>

#ifndef __MAIN_HPP__
#define __MAIN_HPP__

struct sort_id;
struct sort_name;
struct sort_year;

class Item {
protected:
    int ID;

public:
    std::string name, year;

    Item(std::string a, std::string b);

    virtual ~Item();

    virtual void print_info() = 0;

    virtual bool search(std::string argument) = 0;

    virtual bool is_id(int id) = 0;

    virtual void set_id(int i) = 0;

    friend sort_id;
    friend sort_name;
    friend sort_year;
};

class Book : public Item {
public:
    std::string author;

    Book(std::string name, std::string author, std::string year) : Item(name, year), author(author) {}

    void print_info() override;

    bool search(std::string argument) override;

    bool is_id(int id) override;

    void set_id(int i) override;
};

class Journal : public Item {
public:
    std::string volume;
    std::string issue;

    Journal(std::string name, std::string volume, std::string issue, std::string year) : Item(name, year),
                                                                                         volume(volume), issue(issue) {}

    void print_info() override;

    bool search(std::string argument) override;

    bool is_id(int id) override;

    void set_id(int i) override;
};

// declaration of the sorting functions according to name
struct sort_id {
    inline bool operator()(const Item *a, const Item *b);
};

struct sort_name {
    inline bool operator()(const Item *a, const Item *b);
};

struct sort_year {
    inline bool operator()(const Item *a, const Item *b);
};

class Database {
private:
    std::vector<Item *> db;

public:
    Database();

    void add(Item *a);
    void sort(std::string sort_by, std::string sort_order);

    void set_id();
    void list();                        // declaration of list method
    void find(const std::string &key);  // declaration of find method
    void erase(const std::string &key); // declaration of erase method
    void remove(const std::string &id); // declaration of erase method
    ~Database();                        // declare destructor
};

#endif // __MAIN_HPP__