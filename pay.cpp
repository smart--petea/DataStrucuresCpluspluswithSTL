#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "time.cpp"

using namespace std;

int main()
{
    string in_file_name;
    cout << "Input file: ";
    getline(cin, in_file_name);

    ifstream ifs_input(in_file_name.c_str());
    if(ifs_input) {
        cout << "Can't open input file";
        return 1;
    }

    string out_file_name;
    cout << "Out file: ";
    getline(cin, out_file_name);

    ofstream ofs_output(out_file_name.c_str());
    if(ofs_output) {
        cout << "Can't open output file";
        return 1;
    }

    int employee_number;
    int kPayRate = 1;
    while(ifs_input >> employee_number)
    {
        Time start_time;
        start_time.read(ifs_input);

        Time stop_time;
        stop_time.read(ifs_input);

        double pay = stop_time.minus(start_time) * kPayRate;

        ofs_output << employee_number << ' ';
        start_time.print(ofs_output);
        ofs_output << ' ';
        stop_time.print(ofs_output);
        ofs_output << " $" << fixed << setprecision(2) << pay << endl;
    }

    return 0;
}
