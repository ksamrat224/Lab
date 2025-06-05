#include <stdio.h>
#include <math.h>

#define TOTAL_CATEGORIES 5

// Expected probabilities for 4-digit groups
double expected_prob[TOTAL_CATEGORIES] = {
    0.5040, // All digits different
    0.4320, // One pair
    0.0270, // Two pairs
    0.0360, // Three of a kind
    0.0010  // Four of a kind
};

int main()
{
    int observed[TOTAL_CATEGORIES];
    int total_groups;
    double expected[TOTAL_CATEGORIES];
    double chi_square = 0.0;

    printf("Enter total number of groups: ");
    scanf("%d", &total_groups);

    printf("Enter observed counts for each category:\n");
    printf("1. All digits different: ");
    scanf("%d", &observed[0]);

    printf("2. One pair: ");
    scanf("%d", &observed[1]);

    printf("3. Two pairs: ");
    scanf("%d", &observed[2]);

    printf("4. Three of a kind: ");
    scanf("%d", &observed[3]);

    printf("5. Four of a kind: ");
    scanf("%d", &observed[4]);

    // Calculate expected values and chi-square
    for (int i = 0; i < TOTAL_CATEGORIES; i++)
    {
        expected[i] = expected_prob[i] * total_groups;
        chi_square += pow(observed[i] - expected[i], 2) / expected[i];
    }

    printf("\nExpected counts based on probabilities:\n");
    for (int i = 0; i < TOTAL_CATEGORIES; i++)
    {
        printf("Category %d: %.2f\n", i + 1, expected[i]);
    }

    printf("\nChi-Square value: %.4f\n", chi_square);

    printf("\nInterpretation:\n");
    printf("- Compare this value with Chi-Square table (df = 4, alpha = 0.05 critical value 9.49)\n");

    if (chi_square < 9.49)
        printf("Result: The sequence appears to be random.\n");
    else
        printf("Result: The sequence may NOT be random.\n");

    return 0;
}
