#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

void read(istream& in, vector<int>& v, const int& n)
{
    int i = 0;
    int temp;
    v.clear();

    while( i++ < n)
    {
        in >> temp;
        v.push_back(temp);
        in.get(); //white space
    }
}

int main()
{
    vector<int> vec;

    read(cin, vec, 3);

    cout << "R E S U L T" << endl;
    for(vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
        cout << *it << endl;

    return 0;
}
