#include <sstream>
#include <iostream>
#include <assert.h>

using namespace std;

struct Time
{
    int hours;
    int minutes;
};

void normalize(Time& t)
{
    //hours in [0, 23]
    //minutes in [0, 59]
    t.hours += t.minutes < 0 ? (t.minutes - 60)/ 60 : t.minutes / 60;
    t.hours = (t.hours < 0) ? t.hours % 24 + 24 : t.hours % 24;
    t.minutes = (t.minutes < 0) ? t.minutes % 60 + 60 : t.minutes % 60; 
}

void add_minutes(Time& t, int num_minutes)
{
    t.minutes += num_minutes;
    normalize(t);
}

void initialize(Time& t, int hours = 23, int minutes = 59) //initialize(t, 100, 100)
{
    t.hours = hours;
    t.minutes = minutes;
    normalize(t);
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

bool is_later_than(const Time& t1, const Time& t2)
{
    return (t1.hours > t2.hours) || (t1.hours == t2.hours && t1.minutes > t2.minutes);
}


int main()
{
    /*
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
    */

    /*
    //1.4.5
    //Add to the Time data type an operation is_later_than(t1, t2)
    Time t1, t2;

    initialize(t1, 5);
    initialize(t2, 4);
    assert(is_later_than(t1, t2));

    initialize(t1, 5, 33);
    initialize(t2, 5, 33);
    assert(!is_later_than(t1, t2));

    initialize(t1, 5, 34);
    initialize(t2, 5, 33);
    assert(is_later_than(t1, t2));

    initialize(t1, 4, 34);
    initialize(t2, 5, 33);
    assert(!is_later_than(t1, t2));
    */

    //1.4.6
    Time t1;
    initialize(t1, 0, 0);
    add_minutes(t1, -12);
    print(t1, cout);
    cout << endl;

    /*
    //initialize testing
    Time t1;
    initialize(t1, 1000, 2000);
    print(t1, cout);
    cout << endl;

    initialize(t1, 0, -20); //23:40
    print(t1, cout);
    cout << endl;

    initialize(t1, -2, -20); //21:40
    print(t1, cout);
    cout << endl;

    initialize(t1, 0, -72); //22:48
    print(t1, cout);
    cout << endl;

    initialize(t1, 1, -12); //00:48
    print(t1, cout);
    cout << endl;
    */

    return 0;
}
