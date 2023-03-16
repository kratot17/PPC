#include<iostream>
#include<stack>


int main()
{
    std::stack<double> a;

    std::cout << "a.size = " << a.size() << std::endl;
    a.push(1.1);
    a.push(1.6);
    a.push(2.3);
    std::cout << "a.size = " << a.size() << std::endl;
    std::cout << "a.top = " << a.top() << std::endl;

    while(!a.empty() )
    {
        std::cout <<  a.top()  << ", ";
        a.pop();
    }

    std::cout << std::endl;


    return 0;
}