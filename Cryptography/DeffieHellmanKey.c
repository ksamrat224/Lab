#include<stdio.h>
long long modPow(long long base, long long exp, long long modulus) {
    base %= modulus;
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) result = (result * base) % modulus;
        base = (base * base) % modulus;
        exp >>= 1;
    }
    return result;
}

int main() {
    long long q, alpha, Xa, Xb, Ya, Yb, k1, k2;
    
    printf("Enter value of q and alpha: ");
    scanf("%lld %lld", &q, &alpha);
    
    printf("Enter values of Xa and Xb: ");
    scanf("%lld %lld", &Xa, &Xb);
    
    Ya = modPow(alpha, Xa, q);
    Yb = modPow(alpha, Xb, q);
    
    k1 = modPow(Yb, Xa, q);
    k2 = modPow(Ya, Xb, q);
    
    printf("Ya = %lld\t\tYb = %lld\nK1 = %lld\tK2 = %lld\n", Ya, Yb, k1, k2);
    
    return 0;
}