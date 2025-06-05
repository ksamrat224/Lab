#include <stdio.h>
void multiplyMatrix(float a[2][2], float b[2][2], float result[2][2])
{
    int m = 2, p = 2, o = 2;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < p; j++)
        {
            result[i][j] = 0;
            for (int k = 0; k < o; k++)
            {
                result[i][j] += (a[i][k] * b[k][j]);
            }
        }
    }
}

void printArray(float arr[2][2])
{
    for (int i = 0; i < 2; i++)
    {
        if (i == 1)
            printf("Pepsi\t");
        if (i == 0)
            printf("\tCoke\t\tPepsi\nCoke\t");
        for (int j = 0; j < 2; j++)
        {
            printf("%.3f\t", arr[i][j]);
        }
        printf("\n");
    }
}

void main()
{
    float p[2][2], first[2][2], second[2][2], third[2][2];
    int i, j;
    printf("Enter elements of matrix:\n");
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            scanf("%f", &p[i][j]);
        }
    }
    printf("\nFor 1st purchase: \n");
    printArray(p);
    multiplyMatrix(p, p, second);
    printf("\nFor 2nd purchase: \n");
    printArray(second);
    multiplyMatrix(second, p, third);
    printf("\nFor 3rd purchase: \n");
    printArray(third);
}