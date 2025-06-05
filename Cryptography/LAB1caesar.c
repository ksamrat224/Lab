#include <stdio.h>
#include <string.h>
void main()
{
    int key, len, i;
    char plainText[100], outPut[100];
    printf("Enter plain text: ");
    gets(plainText);
    printf("Enter Key: ");
    scanf("%d", &key);
    len = strlen(plainText);
    printf("Encrypted text: ");
    for (i = 0; i < len; i++)
    {

        if (plainText[i] >= 65 && plainText[i] <= 90)
        {
            outPut[i] = ((plainText[i] - 65 + key) % 26) + 65;
        }
        else if (plainText[i] >= 97 && plainText[i] <= 122)
        {
            outPut[i] = ((plainText[i] - 97 + key) % 26) + 97;
        }
        else
        {
            outPut[i] = plainText[i];
        }
        printf("%c", outPut[i]);
    }
    printf("\nDecrypted text: ");

    for (i = 0; i < len; i++)
    {

        if (outPut[i] >= 65 && outPut[i] <= 90)
        {
            plainText[i] = ((outPut[i] - 65 - key + 26) % 26) + 65;
            // if (outPut[i] - 65 - key < 0)
            // {
            //     plainText[i] = ((outPut[i] - 65 - key) + 26) + 65;
            // }
            // else
            // {
            //     plainText[i] = ((outPut[i] - 65 - key)) + 65;
            // }
        }
        else if (outPut[i] >= 97 && outPut[i] <= 122)
        {
            plainText[i] = ((outPut[i] - 97 - key + 26) % 26) + 97;
            // if (outPut[i] - 97 - key < 0)
            // {
            //     plainText[i] = ((outPut[i] - 97 - key) + 26) + 97;
            // }
            // else
            // {
            //     plainText[i] = ((outPut[i] - 97 - key)) + 97;
            // }
        }
        else
        {
            outPut[i] = plainText[i];
        }
        printf("%c", plainText[i]);
    }
}