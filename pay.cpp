#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "time.cpp"

using namespace std;

int main()
{
    cout << "Name of input file: ";
    string input_file_name;
    getline(cin, input_file_name);

    ifstream ifs_input(input_file_name);
    if(!ifs_input) 
    {
        cout << "Could not open file." << endl;
        return 1;
    }

    cout << "Name of output file: ";
    string output_file_name;
    getline(cin, output_file_name);

    ofstream ofs_output(output_file_name);
    if(!ofs_output)
    {
        cout << "Could not open output file." << endl;
        return 1;
    }

    int employee_number;
    int kPayRate = 1;
    while(ifs_input >> employee_number)
    {
        Time start_time;
        read(start_time, ifs_input);

        Time stop_time;
        read(stop_time, ifs_input);

        double pay = difference(stop_time, start_time) * kPayRate;

        ofs_output << employee_number << ' ';

        print(start_time, ofs_output);
        ofs_output << ' ';

        print(stop_time, ofs_output);
        ofs_output << " $" << fixed << setprecision(2) << pay << endl;
    }
    return 0;
}
