#include <sstream>
using namespace std;

class Time
{
    friend void initialize(Time & t);
    friend void read(Time& t, istream& in);
    friend void print(const Time& t, ostream& out);
    friend double difference(const Time& t1, const Time& t2);

    private:
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
    in.get(); //colon
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
