#include <iostream>
using namespace std;

int inverse(int a, int b)
{
    int x1 = 1, x2 = 0, y1 = 0, y2 = 1, x, y, q, r, gcd;
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
    return x1;
}
int modPow(long base, long exp, long modulus)
{
    base %= modulus;
    int result = 1;
    while (exp > 0)
    {
        if (exp % 2 == 1)
            result = (result * base) % modulus;
        base = (base * base) % modulus;
        exp >>= 1;
    }
    return result;
}
int main()
{
    int p = 17, q = 11, m1, c, m2;
    int n = p * q;
    int On = (p - 1) * (q - 1);
    int e = 7;
    int d = inverse(e, On);
    cout << "Public key: " << e << " " << n << endl;
    cout << "Private key: " << d << " " << n << endl;
    cout << "Enter message: ";
    cin >> m1;
    c = modPow(m1, e, n);
    cout << "Cipher text: " << c << endl;
    m2 = modPow(c, d, n);
    cout << "Plain text: " << m2;
    return 1;
}