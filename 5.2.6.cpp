#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

void print(const vector<int>& v, ostream& out)
{
    for(vector<int>::const_iterator i = v.begin(); i != v.end(); i++) 
        out << *i << endl;
}

int main()
{
    vector<int> x = {1, 2, 3, 4};
    print(x, cout);
    return 0;
}
