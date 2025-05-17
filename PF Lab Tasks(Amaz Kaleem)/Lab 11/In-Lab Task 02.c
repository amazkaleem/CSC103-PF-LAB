#include <stdio.h>
#include <string.h>

int main() {
    char words[5][20] = { "apple", "banana", "cherry", "date", "fig" };
    char search[20];
    int found = 0;
    int i;

    
    printf("Enter a word to search: ");
    scanf("%s", search);

    
    for (i = 0; i < 5; i++) {
        if (strcmp(words[i], search) == 0) {
            found = 1;
            printf("'%s' found at position %d.\n", search, i);
            break;
        }
    }

    if (!found) {
        printf("'%s' not found in the array.\n", search);
    }

    return 0;
}

