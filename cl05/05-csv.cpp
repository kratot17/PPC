#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <string>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <regex>
#include <iterator>

typedef std::vector<int> line;

std::istream & operator>> (std::istream & is, line & r) {

    r.clear();
    // l - radka, kterou nactu z proudu
    // field je polozka radky - ;field;
    std::string l, field;

    std::getline (is, l);
    std::istringstream iss(l);

    while (getline (iss, field, ';'))   // vysledkem je rozdeleny isstringstream podle deliciho znaku - ';'
    {
        try {
            r.push_back(stoi(field));
        }
        catch (...) {  // zachyceni vsech vyjimek
            std::regex reg ("(\\w+)\\((\\w):(\\w)\\)"); // w <-> [a-zA-Z] -> hledam text, odpovidaci SLOVO(PISMENO:PISMENO)
            std::smatch match;
            if (std::regex_search (field, match, reg))
            {
                std::smatch::iterator it = match.begin() + 1;
                
                if ((it++)->compare("SUM") == 0)
                {
                    int ii[2];
                    std::generate_n (ii, 2, [&it](){return (*(it++)).str().at(0) - 'A';});
                    r.push_back (std::accumulate(r.begin()+ii[0], r.begin()+ii[1]+1, 0));
                }
            }
        }
    }
    return is;
}

int main () {
    std::ifstream file("data.csv");
    line r;

    // zkonvertujeme kazdy jednotlivy radek na std::vector<int>
    while (file >> r) {
        for (auto i : r) {
            std::cout << std::setw(5) << i << " "; 
        }
        std::cout << std::endl;
    }
}