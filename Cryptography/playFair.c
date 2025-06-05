#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 5
char k[SIZE][SIZE];

void genKey(char key[]) {
    int used[26] = {0}, i, j = 0;
    for (i = 0; key[i]; i++) {
        char c = toupper(key[i]); if (c == 'J') c = 'I';
        if (isalpha(c) && !used[c - 'A']) used[c - 'A'] = 1, k[j / SIZE][j++ % SIZE] = c;
    }
    for (i = 0; i < 26; i++) {
        if (i + 'A' == 'J' || used[i]) continue;
        k[j / SIZE][j++ % SIZE] = i + 'A';
    }
}

void find(char c, int *r, int *c_) {
    if (c == 'J') c = 'I';
    for (int i = 0; i < SIZE * SIZE; i++)
        if (k[i / SIZE][i % SIZE] == c) *r = i / SIZE, *c_ = i % SIZE;
}

void prep(char *in, char *out) {
    int j = 0;
    for (int i = 0; in[i]; i++) {
        char c = toupper(in[i]);
        if (isalpha(c)) {
            if (c == 'J') c = 'I';
            if (j && out[j - 1] == c) out[j++] = 'X';
            out[j++] = c;
        }
    }
    if (j % 2) out[j++] = 'X';
    out[j] = 0;
}

void enc(char *in, char *out) {
    for (int i = 0; in[i]; i += 2) {
        int r1, c1, r2, c2;
        find(in[i], &r1, &c1); find(in[i + 1], &r2, &c2);
        out[i] = (r1 == r2) ? k[r1][(c1 + 1) % SIZE] : (c1 == c2) ? k[(r1 + 1) % SIZE][c1] : k[r1][c2];
        out[i + 1] = (r1 == r2) ? k[r2][(c2 + 1) % SIZE] : (c1 == c2) ? k[(r2 + 1) % SIZE][c2] : k[r2][c1];
    }
    out[strlen(in)] = 0;
}

int main() {
    char key[100], plain[100], prepText[100], cipher[100];
    printf("Enter keyword: "); fgets(key, sizeof key, stdin); key[strcspn(key, "\n")] = 0;
    printf("Enter plaintext: "); fgets(plain, sizeof plain, stdin); plain[strcspn(plain, "\n")] = 0;
    
    genKey(key);
    prep(plain, prepText);
    enc(prepText, cipher);

    printf("\nEncrypted Text: %s\n", cipher);
}
