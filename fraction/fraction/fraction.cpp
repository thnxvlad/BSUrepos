#include <iostream>
#include <string>

using namespace std;

int gcd(int a, int b)
{
    if (a < b) swap(a, b);
    while (a % b != 0)
    {
        a %= b;
        swap(a, b);
    }
    return b;
}

class fruction
{
public:
    int numerator, denumerator;
    fruction(int a, int b) { numerator = a, denumerator = b; }
    fruction() { numerator = 0, denumerator = 1; }

    fruction operator+(fruction a)
    {
        int _denum = (a.denumerator * denumerator) / gcd(a.denumerator, denumerator);
        a.denumerator *= _denum / a.denumerator;
        a.numerator += _denum / denumerator * numerator;
        a.denumerator = _denum;
        int g = gcd(a.numerator, a.denumerator);
        a.numerator /= g;
        a.denumerator /= g;
        return a;
    }

    fruction operator-(fruction a)
    {
        int _denum = (a.denumerator * denumerator) / gcd(a.denumerator, denumerator);
        a.denumerator *= _denum / a.denumerator;
        a.numerator -= _denum / denumerator * numerator;
        a.numerator *= -1;
        a.denumerator = _denum;
        int g = gcd(a.numerator, a.denumerator);
        a.numerator /= g;
        a.denumerator /= g;
        return a;
    }
};

int main()
{   
    fruction x(1, 3), y(1, 2);
    x = x - y;
    cout << x.numerator << '/' << x.denumerator << '\n';
}
