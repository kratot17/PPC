#include <iostream>
#include <thread>

class MyFunctor
{
public:
    void operator()() {
        std::cout << "functor\n";
    }
};

int main()
{
    MyFunctor fnctor;
    std::thread t(fnctor);
    std::cout << "main thread\n";
    t.join();
    return 0;
}