#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

void read(ifstream& in, vector<int>& v)
{
    v.clear();

    int temp;
    while(in >> temp)
    {
        in.get(); //white space
        v.push_back(temp);
    }
}

int main()
{
    string ifile_name;
    cout << "file name: ";
    getline(cin, ifile_name);

    ifstream ifile(ifile_name.c_str());
    if(!ifile)
    {
        cout << "could not open '" << ifile_name << "'" << endl;
        return 1;
    }
    vector<int> vec;

    read(ifile, vec);

    cout << "R E S U L T" << endl;
    for(vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
        cout << *it << endl;

    return 0;
}
