#include <stdio.h>
void main()
{
    int m, a, c, x0, n;
    int x[20];
    float R[20];
    printf("Enter values of m, a, c and x0: ");
    scanf("%d%d%d%d", &m, &a, &c, &x0);
    printf("Enter number of random number to be generated: ");
    scanf("%d", &n);
    x[0] = x0;
    R[0] = (float)x0 / m;
    for (int i = 1; i < n; i++)
    {
        x[i] = ((a * x[i - 1]) + c) % m;
        R[i] = (float)x[i] / m;
    }
    printf("X[i]\tR[i]\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%f\n", x[i], R[i]);
    }
}