#include <sstream>
using namespace std;

class Time
{
    public:
        void initialize() 
        {
            hours = minutes = 99;
        }

        void read(istream& in)
        {
            in >> hours;
            in.get(); //colon
            in >> minutes;
        }

        void print(ostream& out)
        {
            out << hours << ':';
            if(minutes < 10) out << 0;
            out << minutes;
        }

        double minus(const Time& t2)
        {
            return (hours + minutes/60.0) - (t2.hours + t2.minutes/60.0);
        }

        bool is_later_than(const Time& t) const
        {
            if(t.hours < hours || (t.hours == hours && t.minutes < minutes)) return true;

            return false;
        }

    private:
        int hours;
        int minutes;
};
