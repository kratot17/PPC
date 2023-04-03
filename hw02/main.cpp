#include <iostream>
#include <vector>
#include "doprava.hpp"

using namespace std;

void print_timetable(Network net, string stop) {
    for (int ln = 0; ln < net.nlines();
    ln++) {
        Line tmpL = net.getLine(ln);
        auto itStop = tmpL.stops.begin();
        for (/*nic nedelam na zacatku*/; itStop != tmpL.stops.end(); itStop++) {
            if (stop == *itStop) // porovname zda se vyhledavana zastavka rovna sktualni
                break; // za cyklem mit d itStop ukazatel na zastvaku
        }
        if (itStop == tmpL.stops.end())
            continue; // skusime najit zastavku v dalsi lince

        int offset = itStop - tmpL.stops.begin(); // sjistime, kolikata je ta zastavka

        string cilova_zastavka_tam = *tmpL.stops.rbegin();
        string cilova_zastavka_zpet = *tmpL.stops.begin();

        vector <Depart> odjezdy_vpred;
        vector <Depart> odjezdy_vzad;

        for (auto itConn = tmpL.conns_fwd.begin(); itConn != tmpL.conns_fwd.end(); itConn++)
            odjezdy_vpred.push_back(itConn->at(offset)); // presuneme odjezdy z konkretni zastavky do 1 vektoru
        for (auto itConn = tmpL.conns_fwd.begin(); itConn != tmpL.conns_bwd.end(); itConn++)
            odjezdy_vzad.push_back(itConn->at(offset)); // presuneme odjezdy z konkretni zastavky do 1 vektoru

        int hh, mm, ss;
        odjezdy_vpred.at(0).ti.gett(hh, mm, ss); // naplnim si intigery - konkretne prvni odjezd tam
        cout << "prvni odjezd tam je v " << hh << ":" << mm << ":" << ss << endl;

        odjezdy_vzad.at(0).ti.gett(hh, mm, ss); // naplnim si intigery - konkretne prvni odjezd zpet
        cout << "prvni odjezd zpet je v " << hh << ":" << mm << ":" << ss << endl;
    }
}

int main(int argc, char **argv) {

    // Load files:
    DriverList dl;
    dl.loadFromFile("driver_list.txt");

    Network net;
    net.loadFromFile("network.txt");

    // variables for argument decoding
    string flag_in;
    list <string> stop_in;

    if (argc > 1)
        flag_in = string(argv[1]);
    else {
        cerr << "Missing argument. Terminating." << endl;
        return 1;
    }

    if ((!flag_in.compare("--schedule"))) {
        // input check - do not edit
        if (argc > 2) {
            for (int i = 2; i < argc; i++) {
                string temp = argv[i];
                replace(temp.begin(), temp.end(), '_', ' ');
                stop_in.push_back(temp);
            }
        } else {
            cerr << "Missing stop name. Terminating." << endl;
            return 2;
        }
        // end of input check

        /* here should start the code for printing timetables*/
        /* stop_in contains names of stops, for which the timetable is to be printed. */

        // This is an example, how it can be done using lambda-function
        for_each(stop_in.begin(), stop_in.end(), [&](string stop_name) { print_timetable(net, stop_name); });
        // This is an example, how it can be done using for-loop 
        // for( auto iter = stop_in.begin(); iter != stop_in.end(); iter++) print_timetable(net,*iter);

        /* here should end the code for printing timetables*/
    } else if ((!flag_in.compare("--line-routing"))) {

        /* here should start the code for printing line routes without stats*/



        /* here should end the code for printing line routes without stats*/
    } else if ((!flag_in.compare("--driver-stops"))) {

        /* here should start the code for stops statistics for drivers */



        /* here should end the code for stops statistics for drivers */
    } else {
        cout << "Flag not recognized, terminating." << endl;
    }

    return 0;
}