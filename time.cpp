#include <sstream>
#include <iostream>
using namespace std;

struct Time
{
    int hours;
    int minutes;
};

void initialize(Time& t)
{
    t.hours = t.minutes = 99;
}

void read(Time& t, istream& in)
{
    in >> t.hours;
    in.get();
    in >> t.minutes;
}

void print(const Time& t, ostream& out)
{
    out << t.hours << ':';
    if(t.minutes < 10) out << 0;
    out << t.minutes;
}

double difference(const Time& t1, const Time& t2)
{
    return (t1.hours + t1.minutes/60.0) - (t2.hours + t2.minutes/60.0);
}

int main()
{
    Time t1, t2;
    initialize(t1);
    initialize(t2);

    cout << "Initial values: ";
    print(t1, cout);

    cout << ' ';
    print(t2, cout);

    cout << endl;

    while(true)
    {
        cout << "Enter two times: ";
        read(t1, cin);
        read(t2, cin);

        cout << "The difference between ";
        print(t1, cout);
        cout << " and ";
        print(t2, cout);
        cout << " is " << difference(t2, t1) << endl;
    }

    return 0;
}
