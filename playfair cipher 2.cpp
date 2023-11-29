#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MX 5

void playfair(char ch1, char ch2, char key[MX][MX]) {
    // Function body is not implemented in this example
    // You need to fill in the logic for the Playfair cipher
}

int main() {
    int i, j, k = 0, l, m = 0, n;
    char key[MX][MX], keyminus[25], keystr[10], str[25] = {0};
    char alpa[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L',
                     'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

    printf("\nEnter key:");
    fgets(keystr, sizeof(keystr), stdin);
    keystr[strcspn(keystr, "\n")] = '\0';  // Remove the newline character

    printf("\nEnter the plain text:");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';  // Remove the newline character

    n = strlen(keystr);

    for (i = 0; i < n; i++) {
        if (keystr[i] == 'j')
            keystr[i] = 'i';
        else if (keystr[i] == 'J')
            keystr[i] = 'I';
        keystr[i] = toupper(keystr[i]);
    }

    for (i = 0; i < strlen(str); i++) {
        if (str[i] == 'j')
            str[i] = 'i';
        else if (str[i] == 'J')
            str[i] = 'I';
        str[i] = toupper(str[i]);
    }

    j = 0;

    for (i = 0; i < 26; i++) {
        for (k = 0; k < n; k++) {
            if (keystr[k] == alpa[i])
                break;
            else if (alpa[i] == 'J')
                break;
        }
        if (k == n) {
            keyminus[j] = alpa[i];
            j++;
        }
    }

    k = 0;
    for (i = 0; i < MX; i++) {
        for (j = 0; j < MX; j++) {
            if (k < n) {
                key[i][j] = keystr[k];
                k++;
            } else {
                key[i][j] = keyminus[m];
                m++;
            }
            printf("%c ", key[i][j]);
        }
        printf("\n");
    }

    printf("\n\nEntered text: %s\nCipher Text: ", str);

    for (i = 0; i < strlen(str); i++) {
        if (str[i] == 'J')
            str[i] = 'I';

        if (str[i + 1] == '\0')
            playfair(str[i], 'X', key);
        else {
            // You may need to implement logic here for handling pairs of characters
        }
    }

    return 0;
}