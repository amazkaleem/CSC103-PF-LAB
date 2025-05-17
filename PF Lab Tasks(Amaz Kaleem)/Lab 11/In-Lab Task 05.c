#include <stdio.h>

int main() {
    char input[200], output[200];
    int i = 0, j = 0;

    printf("Enter a string with multiple spaces:\n");
    fgets(input, sizeof(input), stdin);  // Reads entire line including spaces

    while (input[i] != '\0') {
        
        if (input[i] != ' ') {
            output[j++] = input[i];
        }
       
        else {
            if (j == 0 || output[j - 1] != ' ') {
                output[j++] = ' ';
            }
        }
        i++;
    }

    output[j] = '\0'; 

    printf("\nString after removing extra spaces:\n%s", output);

    return 0;
}

