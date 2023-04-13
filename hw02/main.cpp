#include <iostream>
#include <vector>
#include <iomanip>
#include "doprava.hpp"
#include <string>

using namespace std;

void print_timetable(const Network &net, const string &stop) {
    for (int ln = 0; ln < net.nlines();
         ln++) {

        // data handling
        Line tmpL = net.getLine(ln);
        auto itStop = tmpL.stops.begin();
        for (/*nic nedelam na zacatku*/; itStop != tmpL.stops.end(); itStop++) {
            if (stop == *itStop) // porovname zda se vyhledavana zastavka rovna sktualni
                break;
        }
        if (itStop == tmpL.stops.end())
            continue; // zkusime najit zastavku v dalsi lince

        int offset = itStop - tmpL.stops.begin(); // zjistime, kolikata je ta zastavka

        string cilova_zastavka_tam = *tmpL.stops.rbegin();
        string cilova_zastavka_zpet = *tmpL.stops.begin();

        vector<Depart> odjezdy_vpred;
        vector<Depart> odjezdy_vzad;

        for (auto &itConn: tmpL.conns_fwd) {
            odjezdy_vpred.push_back(itConn.at(offset)); // presuneme odjezdy z konkretni zastavky do 1 vektoru
        }
        for (auto &itConn: tmpL.conns_bwd) {
            odjezdy_vzad.push_back(itConn.at(offset));
        }

        // table printing
        int hh, mm, ss, depInHour = 0, rowLen = 80;
        // header
        cout << "+" << std::string(rowLen - 2, '-') << "+" << endl;
        cout << "| " << left << setw(rowLen - 11) << stop << "Line: " << ln << " |" << endl;
        cout << "+" << std::string(38, '-') << "++" << std::string(38, '-') << "+" << endl;
        cout << "| To: " << left << setw(rowLen - 47) << cilova_zastavka_tam << "|| To: " << left << setw(rowLen - 47)
             << cilova_zastavka_zpet << "|" << endl;
        cout << "+" << std::string(4, '-') << "+" << std::string(33, '-') << "++" << std::string(4, '-') << "+"
             << std::string(33, '-') << "+" << endl;
        // body
        for (int hour = 0; hour < 24; hour++) {
            cout << "| " << std::setw(2) << std::setfill('0') << right << hour << " | ";
            for (auto &index: odjezdy_vpred) {
                index.ti.gett(hh, mm, ss); // naplnim si intigery - konkretne prvni odjezd tam
                if (hour == hh) {
                    cout << std::setw(2) << right << mm << " ";
                    depInHour++;
                }
            }
            cout << std::string(32 - (3 * depInHour), ' ') << "|";
            depInHour = 0;
            // second column
            cout << "| " << std::setw(2) << right << hour << " | ";
            for (auto &index: odjezdy_vzad) {
                index.ti.gett(hh, mm, ss); // naplnim si intigery - konkretne prvni odjezd tam
                if (hour == hh) {
                    cout << std::setw(2) << right << mm << " ";
                    depInHour++;
                }
            }
            cout << std::string(32 - (3 * depInHour), ' ') << "|" << std::setfill(' ') << endl;
            depInHour = 0;
        }
        cout << "+" << std::string(4, '-') << "+" << std::string(33, '-') << "++" << std::string(4, '-') << "+"
             << std::string(33, '-') << "+" << endl;
    }
}

void print_lines(const Network &net) {
    vector<long> departs;
    int rowLen = 80;
    int first_time[3] = {0, 0, 0};
    for (int ln = 0; ln < net.nlines();
         ln++) {
        // header
        cout << "+" << std::string(rowLen - 2, '-') << "+" << endl;
        cout << "| Line: " << left << setw(rowLen - 10) << ln << " |" << endl;
        cout << "+---+----+" << std::string(rowLen / 2 - 11, '-') << "++---+----+" << std::string(rowLen / 2 - 11, '-')
             << "+" << endl;
        cout << "| d | rT | ==>" << std::string(rowLen / 2 - 15, ' ') << "|| d | rT | <=="
             << std::string(rowLen / 2 - 15, ' ') << "|" << endl;
        cout << "+---+----+" << std::string(rowLen / 2 - 11, '-') << "++---+----+" << std::string(rowLen / 2 - 11, '-')
             << "+" << endl;
        // body
        Line tmpL = net.getLine(ln);
        for (int i = 0; i < tmpL.stops.size(); i++) {
            int d = 1, rT = 1, hh, mm, ss;
            auto stp = tmpL.conns_fwd.begin();
            stp->at(i).ti.gett(hh, mm, ss);
            if (i == 0) {
                first_time[0] = hh;
                first_time[1] = mm;
                first_time[2] = ss;
            }
            departs.push_back(stp->at(i).ti.gets());
            // udelat to samy i na druhou stranu
            // spocitat rozdily
            // zaporny casy vyresim 60 soustavou

            cout << "| " << d << " | " << right << std::setfill('0') << std::setw(2) << mm - first_time[1] << left << std::setfill(' ')
                 << " | " << std::setw(28)
                 << tmpL.stops.at(i) << "|| " << d << " | " << right << std::setfill('0') << std::setw(2) << rT << left
                 << std::setfill(' ') << " | "
                 << std::setw(28) << tmpL.stops.at(tmpL.stops.size() - (i + 1)) << "|" << endl;
        }

        cout << "+---+----+" << std::string(rowLen / 2 - 11, '-') << "++---+----+" << std::string(rowLen / 2 - 11, '-')
             << "+" << endl;
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
    list<string> stop_in;

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
        for (int i = 2; i < argc; i++) {
            string temp = argv[i];
            replace(temp.begin(), temp.end(), '_', ' ');
            stop_in.push_back(temp);
        }

        /* here should start the code for printing line routes without stats*/
        print_lines(net);

        /* here should end the code for printing line routes without stats*/
    } else if ((!flag_in.compare("--driver-stops"))) {

        /* here should start the code for stops statistics for drivers */



        /* here should end the code for stops statistics for drivers */
    } else {
        cout << "Flag not recognized, terminating." << endl;
    }

    return 0;
}