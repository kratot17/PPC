#include <iostream>
#include <tuple>

int main()
{
    std::tuple<int, int, int> t1(5, 6, 7), t2;
    std::tuple<int, std::string, double> t3;

    t2 = std::make_tuple(11, 12, 13);
    t3 = std::make_tuple(15, "string", 3.14);

    std::get<2>(t3) = 6.28;

    std::cout << "t1: " << std::get<0>(t1) << " | " 
        << std::get<1>(t1)  << " | " << std::get<2>(t1)  << std::endl;
    std::cout << "t2: " << std::get<0>(t2) << " | " 
        << std::get<1>(t2)  << " | " << std::get<2>(t2)  << std::endl;
    std::cout << "t3: " << std::get<0>(t3) << " | " 
        << std::get<1>(t3)  << " | " << std::get<2>(t3)  << std::endl;

    int a = 5, x;
    std::string b = "Ahoj", y;
    double c = 3.14, z;

    t3 = std::tie(a,b,c);

    std::tie(x,y,z) = t3;
    
    std::cout << "tie" << x << " | " << y << " | " << z << std::endl;
    
    std::cout << "t3: " << std::get<0>(t3) << " | " 
        << std::get<1>(t3)  << " | " << std::get<2>(t3)  << std::endl;

    return 0;
}