#include <iostream>
#include <thread>

void thread_function()
{
    std::cout << "thread function\n";
}

int main()
{
    std::thread t(&thread_function);    // startuje vlakno t
    std::cout << "main thread\n";
    t.join();                           // hlavni vlakno ceka, az se t dokonci
    /*
      vlakno t je mozne pustit jako samostatny proces (demon)
      t.detach();
      nelze kombinovat s join()
      vlakno nic nevypise, protoze hlavni program mezitim skonci
    */
   
    return 0;
}