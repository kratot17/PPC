#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main()
{
        string filename = "test.txt";

        // zapis do souboru
        ofstream fout(filename.c_str());  // default: ios::out | ios::trunc
        if (!fout) 
        {
                cerr << "error: otevreni souboru pro zapis selhalo!" << endl;
                abort();  // <cstdlib>
        }
        fout << "apple" << endl;
        fout << "orange" << endl;
        fout << "banana" << endl;
        fout.close();

        // cteni ze souboru
        ifstream fin(filename.c_str());  // default: ios::in
        if (!fin) 
        {
                cerr << "error: otevreni souboru pro cteni selhalo!" << endl;
                abort();
        }

        char ch;
        while (fin.get(ch))
        {
                cout << ch;
        }
        fin.close();

        return 0;
}