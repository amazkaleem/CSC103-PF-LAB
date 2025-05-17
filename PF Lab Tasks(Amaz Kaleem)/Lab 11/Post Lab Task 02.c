#include <stdio.h>
#include <string.h>

int isVowel(char ch) {
    
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
           ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
}

int main() {
    char sentence[81], result[81];
    int i, j = 0;

    printf("Enter a sentence (max 80 characters): ");
    fgets(sentence, sizeof(sentence), stdin);

    
    for (i = 0; sentence[i] != '\0'; i++) {
        if (!isVowel(sentence[i])) {
            result[j++] = sentence[i];
        }
    }

    result[j] = '\0'; 

    printf("Sentence without vowels: %s", result);

    return 0;
}

