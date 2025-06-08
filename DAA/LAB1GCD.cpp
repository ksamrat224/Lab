#include <iostream>
using namespace std;
int main()
{
    int a, b, x1 = 1, x2 = 0, y1 = 0, y2 = 1, x, y, q, r, gcd;
    cout << "Enter first Number: ";
    cin >> a;
    cout << "Enter second number: ";
    cin >> b;
    int a1 = a, b1 = b;
    while (b > 0)
    {
        q = a / b;
        r = a % b;
        x = x1 - (x2 * q);
        y = y1 - (y2 * q);
        x1 = x2;
        x2 = x;
        y1 = y2;
        y2 = y;
        a = b;
        b = r;
    }
    gcd = a;
    x = x1;
    y = y1;
    cout << "GCD(" << a1 << ", " << b1 << ") = " << a << " = " << x << "*" << a1 << " + " << y << "*" << b1;
    return 0;
}