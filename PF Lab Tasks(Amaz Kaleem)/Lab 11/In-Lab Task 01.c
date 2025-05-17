#include <stdio.h>

int main() {
    char str[100];
    int i = 0;

   
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);  

    
    while (str[i] != '\0') {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32;  
        }
        i++;
    }

    
    printf("Uppercase string: %s", str);

    return 0;
}

