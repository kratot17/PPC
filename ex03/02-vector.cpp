#include <iostream>
#include <vector>

int main()
{ 
    std::vector<int> a(7);
    std::vector<int> b;

    std::cout << "Delka a: " << a.size() << " kapacita a: " << a.capacity() << std::endl; 
    std::cout << "Delka b: " << b.size() << " kapacita b: " << b.capacity() << std::endl;

    for(unsigned int i = 0; i < a.size(); i++ )
    {
        // a[i] = i*i; // operator [] nekontroluje index proti size()
        // std::cout << "a[" << i << "]=" << a[i] << "; ";
        a.at(i) = i*i; // fce .at() kontroluje index proti size(), pri poruseni vyvola vyjimku std::out_of_range
        std::cout << "a[" << i << "]=" << a.at(i) << "; ";
    }
    std::cout << std::endl; 

    try
    {
        std::cout << "a[" << 99 << "]=" << a.at(99) << "; "; // tento kod muze vyvolat vyjimku
    }
    catch(const std::out_of_range & e) // obecna vyjimka: const std::exception & e
    {
        std::cerr << e.what() << '\n';
    }

    b = a; //vectol lze priradit (zkopirovat)
    
    b.insert(b.begin()+2, 99 ); //vlozime pred prvek s indexem 2 hodnotu 99. potencialne neefektivni operace

    for(unsigned int i = 0; i < a.size(); i++ )
        std::cout << "a[" << i << "]=" << a.at(i) << "; ";
    std::cout << std::endl; 
    for(unsigned int i = 0; i < b.size(); i++ )
        std::cout << "b[" << i << "]=" << b.at(i) << "; ";
    std::cout << std::endl;

    a.reserve(10);
    std::cout << "Delka a: " << a.size() << " kapacita a: " << a.capacity() << std::endl;
    a.resize(15);
    std::cout << "Delka a: " << a.size() << " kapacita a: " << a.capacity() << std::endl; 
    a.resize(3);
    std::cout << "Delka a: " << a.size() << " kapacita a: " << a.capacity() << std::endl; 
    a.shrink_to_fit();
    std::cout << "Delka a: " << a.size() << " kapacita a: " << a.capacity() << std::endl;

    std::vector<double> * c = new std::vector<double>(3, 1.111); // dynamicky alokujeme vektor se 3 prvky s hodnotou 1.111
    for(unsigned int i =0; i<4 ;i++)
    {
        c->push_back(i*i*i); // vlozime prvek na konec vektoru
        std::cout << "vlozeno: " << c->back() << std::endl;
    }

    for (auto k : *c) // range for - prochazi reference na kazdy prvek vektoru
        std::cout << k << "; ";
    std::cout << std::endl;
    
    delete c; // uvolnime pamet

    return 0;
}
