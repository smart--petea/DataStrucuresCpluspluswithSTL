#include <sstream>
#include <iostream>

using namespace std;

struct Fraction
{
    int a;
    int b;
};

void initialize(Fraction& f, int a = 0, int b = 1)
{
    f.a = a;
    f.b = b;
}

void read(Fraction& f, istream& in)
{
    int a, b;
    in >> a;
    in.get();
    in >> b;
    
    initialize(f, a, b);
}

void print(Fraction& f, ostream& out)
{
    int intPart = f.a / f.b;
    int denominator = f.a % f.b;

    out << intPart << " " << (denominator == 0 ? 1 : denominator) << "/" << f.b;
}

Fraction add(const Fraction& f, const Fraction& g)
{
    Fraction temp;
    initialize(temp, f.a * g.b + g.a * f.b, f.b * g.b);

    return temp;
}

Fraction multiply(const Fraction& f, const Fraction& g)
{
    Fraction temp;
    initialize (temp, f.a * g.a, f.b * g.b);
    return temp;
}

int main()
{
    Fraction f, g, h;
    initialize(g, 5);
    initialize(h, 5, 2);

    f = add(g, h);
    print(f, cout);
    cout << endl;

    f = multiply(g, h);
    print(f, cout);
    cout << endl;
}
