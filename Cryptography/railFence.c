#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int i, j, len, rails, count = 0;
    int code[100][1000] = {0};  // Matrix to store characters in Rail Fence pattern
    char str[1000];

    // Get the secret message
    printf("Enter a Secret Message: ");
    fgets(str, sizeof(str), stdin); // Use fgets to safely read the string

    // Remove the trailing newline if any
    str[strcspn(str, "\n")] = '\0';

    len = strlen(str);  // Length of the input message

    // Get the number of rails
    printf("Enter number of rails: ");
    scanf("%d", &rails);

    // Initialize the matrix with 0 (empty) values
    for (i = 0; i < rails; i++) {
        for (j = 0; j < len; j++) {
            code[i][j] = 0;
        }
    }

    // Fill the matrix with characters following the zigzag pattern
    j = 0;
    while (j < len) {
        if (count % 2 == 0) {
            // Moving downward (top to bottom)
            for (i = 0; i < rails && j < len; i++) {
                code[i][j] = (int)str[j];
                j++;
            }
        } else {
            // Moving upward (bottom to top)
            for (i = rails - 2; i > 0 && j < len; i--) {
                code[i][j] = (int)str[j];
                j++;
            }
        }
        count++;
    }

    // Print the encrypted message (by reading the matrix row by row)
    printf("Encrypted Message: ");
    for (i = 0; i < rails; i++) {
        for (j = 0; j < len; j++) {
            if (code[i][j] != 0) {
                printf("%c", code[i][j]); // Print the characters
            }
        }
    }
    printf("\n");

    return 0;
}