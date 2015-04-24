#include <vector>
#include <iostream>

using namespace std;

int count(const vector<int>& v, int needle)
{
    int n = 0;

    for(vector<int>::const_iterator it = v.begin(); it != v.end(); ++it)
        if(*it == needle) ++n;

    return n;
}

int main()
{
    vector<int> v = {1, 2, 1, 3, 1, 4, 1};
    cout << count(v, 1) << endl;
    return 0;
}
