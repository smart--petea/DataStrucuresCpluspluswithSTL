#include <iostream>
#include <vector>

using namespace std;

vector<int> concatenate(const vector<int>& a, const vector<int>& b) 
{
    vector<int> temp;

    for(vector<int>::const_iterator it = a.begin(); it != a.end(); ++it)
        temp.push_back(*it);

    for(vector<int>::const_iterator it = b.begin(); it != b.end(); ++it)
        temp.push_back(*it);

    return temp;
}

int main()
{
    vector<int> v1 = {1, 2};
    vector<int> v2 = {3, 4, 5};

    vector<int> v_concat = concatenate(v1, v2);

    for(vector<int>::iterator it = v_concat.begin(); it != v_concat.end(); ++it)
        cout << *it << endl;

    return 0;
}
