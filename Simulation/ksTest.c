#include <stdio.h>

int main()
{
    // Static array of values in [0, 1]
    float x[] = {0.15, 0.73, 0.33, 0.57, 0.92, 0.21, 0.41, 0.88, 0.60, 0.11};
    int n = sizeof(x) / sizeof(x[0]);

    // Manual Bubble Sort
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (x[j] > x[j + 1])
            {
                swap(x[j], x[j + 1]);
            }
        }
    }
    // Calculate D+ and D-
    float d_plus = 0.0, d_minus = 0.0;
    for (int i = 0; i < n; i++)
    {
        float Dp = ((float)(i + 1) / n) - x[i];
        float Dm = x[i] - ((float)i / n);
        if (Dp > d_plus)
            d_plus = Dp;
        if (Dm > d_minus)
            d_minus = Dm;
    }

    // Final D
    float D = max(d_plus, d_minus);

    // Output results
    printf("D+ = %.4f\n", d_plus);
    printf("D- = %.4f\n", d_minus);
    printf("D  = %.4f\n", D);

    return 0;
}
