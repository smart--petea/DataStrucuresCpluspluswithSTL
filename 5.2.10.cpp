#include <vector>
#include <iostream>

using namespace std;

void replace(vector<int>& vec, int needle, int rep)
{
    for(vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
        if(*it == needle) *it = rep;
}

int main()
{
    vector<int> v = {1, 2, 4, 4, 5, 4, 4, 8, 9, 4};

    replace(v, 4, 21);

    for(vector<int>::iterator it = v.begin(); it != v.end(); ++it)
        cout << *it << endl;

    return 0;
}
