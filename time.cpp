#include <sstream>
using namespace std;

class Time
{
    friend void initialize(Time & t);
    friend void read(Time& t, istream& in);
    friend void print(const Time& t, ostream& out);
    friend double difference(const Time& t1, const Time& t2);

    private:
        int minutes;
};

void initialize(Time& t)
{
    t.minutes = 99;
}

void read(Time& t, istream& in)
{
    int hours;
    int minutes;

    in >> hours;
    in.get(); //colon
    in >> minutes;

    t.minutes = minutes + hours * 60;
}

void print(const Time& t, ostream& out)
{
    out << (t.minutes / 60) << ':';
    if(t.minutes < 10) out << 0;
    out << (t.minutes % 60);
}

double difference(const Time& t1, const Time& t2)
{
    return (t1.minutes - t2.minutes)/60.0;
}
