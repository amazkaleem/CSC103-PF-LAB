#include <stdio.h>
#include <string.h>
#include <ctype.h>


int isVowel(char ch) {
    ch = tolower(ch);  // Making it case-insensitive
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

int main() {
    char text[200];
    int count = 0;
    int i;

    printf("Enter a line of text:\n");
    fgets(text, sizeof(text), stdin);

    for (i = 0; text[i + 1] != '\0'; i++) {
        if (isVowel(text[i]) && isVowel(text[i + 1])) {
            printf("Found: %c%c\n", text[i], text[i + 1]);
            count++;
        }
    }

    printf("\nTotal occurrences of two vowels in succession: %d\n", count);

    return 0;
}

