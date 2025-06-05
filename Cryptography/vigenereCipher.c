#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to generate the Vigenère cipher text
void vigenereEncrypt(char text[], char key[], char encrypted[]) {
    int textLen = strlen(text), keyLen = strlen(key);
    for (int i = 0, j = 0; i < textLen; i++) {
        char ch = toupper(text[i]);
        if (isalpha(ch)) {
            char keyCh = toupper(key[j % keyLen]);
            encrypted[i] = ((ch - 'A') + (keyCh - 'A')) % 26 + 'A';
            j++;
        } else {
            encrypted[i] = ch;
        }
    }
    encrypted[textLen] = '\0';
}

int main() {
    char text[100], key[100], encrypted[100];
    printf("Enter plaintext: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = 0;
    
    printf("Enter keyword: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = 0;
    
    vigenereEncrypt(text, key, encrypted);
    printf("\nEncrypted Text: %s\n", encrypted);
    
    return 0;
}