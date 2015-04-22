#include <iostream>
#include <sstream>

using namespace std;

struct ThreeDVector
{
    double x;
    double y;
    double z;
};

void initialize(ThreeDVector& thr, double x = 0, double y = 0, double z = 0)
{
    thr.x = x;
    thr.y = y;
    thr.z = z;
}

void read(ThreeDVector& thr, istream& in)
{
    double x, y, z;

    in.get();

    in >> x;
    in.get();
    in.get();

    in >> y;
    in.get();
    in.get();

    in >> z;
    in.get();

    initialize(thr, x, y, z);
}

void print(const ThreeDVector& v, ostream& os)
{
    os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
}

ThreeDVector add(const ThreeDVector& thr1, const ThreeDVector& thr2)
{
    ThreeDVector thr_temp;
    initialize(thr_temp, thr1.x + thr2.x, thr1.y + thr2.y, thr1.z + thr2.z);

    return thr_temp;
}

int main()
{
    /*
    ThreeDVector thr, sss;
    initialize(thr, 1, 2, 3);
    initialize(sss, 3, 2, 1);
    print(thr, cout);

    cout << endl;

    print(add(thr, sss), cout);
    */

    ThreeDVector thr;

    read(thr, cin); 
    print(thr, cout);

    return 0;
}

