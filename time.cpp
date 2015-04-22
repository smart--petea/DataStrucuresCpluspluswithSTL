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
    in >> t.hours;  //8
    in.get();       //:
    in >> t.minutes;//35
    in.get();       //' '

    char c;
    in.get(c);      //a

    if(c == 'p') t.hours += 12;

    in.get();       //.
    in.get();       //m
    in.get();       //.
}

void print(const Time& t, ostream& out)
{
    char c = 'a';
    int hours = t.hours;

    if(hours >= 12)
    {
        hours -= 12;
        c = 'p';
    }

    out << hours << ':';
    if(t.minutes < 10) out << 0;
    out << t.minutes;
    out << " " << c << ".m.";
}

double difference(const Time& t1, const Time& t2)
{
    return (t1.hours + t1.minutes/60.0) - (t2.hours + t2.minutes/60.0);
}

bool is_later_than(const Time& t1, const Time& t2)
{
    return (t1.hours > t2.hours) || (t1.hours == t2.hours && t1.minutes > t2.minutes);
}
