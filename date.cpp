#include <sstream>
#include <iostream>
using namespace std;

struct Date 
{
    int month;
    int day;
    int year;

    static const char* months[];
};

const char* Date::months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

void initialize(Date& date, int month = 0, int day = 0, int year = 2000)
{
    if(month < 0 || month >= 12) throw "month out of range";
    if(day < 0 || day >= 30) throw "day out of range";
    if(year < 0) throw "year is negative";

    date.month = month;
    date.day = day;
    date.year = year;
}

void read(Date& date, istream& in)
{
    in >> date.month;
    in.get();
    in >> date.day;
    in.get();
    in >> date.year;
}

void print(Date& date, ostream& out)
{
    out << date.month + 1 << "/" << date.day + 1 << "/" << date.year;
}

void print_in_words(Date& date, ostream& out)
{
    out << Date::months[date.month] << " " << date.day + 1 << ", " << date.year;
}
