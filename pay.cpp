#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "time.cpp"

using namespace std;

double computePay(const Time& start_time, const Time& stop_time)
{
    int diff = difference(stop_time, start_time);

    return  diff * (diff < 8 ? 18 : 20);
}

int main()
{
    cout << "Name of start_file: ";
    string start_file_name;
    getline(cin, start_file_name);

    ifstream ifs_start(start_file_name.c_str());
    if(!ifs_start) 
    {
        cout << "Could not open start file." << endl;
        return 1;
    }

    cout << "Name of stop_file: ";
    string stop_file_name;
    getline(cin, stop_file_name);

    ifstream ifs_stop(stop_file_name.c_str());
    if(!ifs_stop) 
    {
        cout << "Could not open start file." << endl;
        return 1;
    }

    cout << "Name of output file: ";
    string output_file_name;
    getline(cin, output_file_name);

    ofstream ofs_output(output_file_name.c_str());
    if(!ofs_output)
    {
        cout << "Could not open output file." << endl;
        return 1;
    }

    int employee_number;
    while(ifs_start >> employee_number)
    {
        ifs_start.get();

        Time start_time;
        read(start_time, ifs_start);

        ifs_stop >> employee_number;
        ifs_stop.get();

        Time stop_time;
        read(stop_time, ifs_stop);


        ofs_output << employee_number << ' ';

        print(start_time, ofs_output);
        ofs_output << ' ';

        print(stop_time, ofs_output);
        ofs_output << " $" << fixed << setprecision(2) << computePay(start_time, stop_time) << endl;
    }
    return 0;
}
