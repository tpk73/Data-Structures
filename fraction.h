// Include iostream to get access to istream, ostream
#include <iostream>
using namespace std;

struct Fraction {
    int num;
    int den;
};

// A function to calculate the greatest common divisor will be useful
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// All fraction values are reduced
// For example, we have 3/4 and never 9/12
// It would be good to create a function to do that
void reduce(Fraction& f)
{
    int reduce;
    reduce = gcd(f.num, f.den);

    int x;
    if (reduce < 0) {
        x = reduce;
        reduce = reduce * -1;
    }
    x++;

    f.num = f.num / reduce;
    f.den = f.den / reduce;
 
}

istream& operator>>(istream& in, Fraction& f)
{
    // Implement fraction input here
    char i;

    in >> f.num >> i >> f.den;
    return in;
  
}

ostream& operator<<(ostream& out, Fraction f)
{
    // Implement fraction output here
    out << f.num << "/" << f.den;
    return out;

}

Fraction operator+(Fraction a, Fraction b)
{
    // Implement fraction addition here
    int lcd;
    lcd = (a.den * b.den) / gcd(a.den, b.den);

    int a2, b2;
    a2 = lcd / a.den;
    b2 = lcd / b.den;

    a.den = lcd;
    a.num = a.num * a2;
    b.den = lcd;
    b.num = b.num * b2;

    Fraction f;
    f.num = a.num + b.num;
    f.den = lcd;

    reduce(f);
    return f;
  
}

Fraction operator-(Fraction a, Fraction b)
{
    // Implement fraction subtraction (a-b) here
    int lcd;
    lcd = (a.den * b.den) / gcd(a.den, b.den);

    int a2, b2;
    a2 = lcd / a.den;
    b2 = lcd / b.den;

    a.den = lcd;
    a.num = a.num * a2;
    b.den = lcd;
    b.num = b.num * b2;

    Fraction f;
    f.num = a.num - b.num;
    f.den = lcd;

    reduce(f);
    return f;

}

Fraction operator*(Fraction a, Fraction b)
{
    // Implement fraction multiplication here
    Fraction f;
    f.num = a.num * b.num;
    f.den = a.den * b.den;

    reduce(f);
    return f;

}

Fraction operator/(Fraction a, Fraction b)
{
    // Implement fraction division (a/b) here
    Fraction f;
    f.num = b.den;
    f.den = b.num;

    f.num = f.num * a.num;
    f.den = f.den * a.den;
    
    reduce(f);
    return f;

}