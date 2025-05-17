#include <stdio.h>


int stringCompare(const char str1[], const char str2[]) {
    int i = 0;

    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return 0;  // Not equal
        }
        i++;
    }

    // If both strings end at the same time, they are equal
    if (str1[i] == '\0' && str2[i] == '\0') {
        return 1;  // Equal
    } else {
        return 0;  // Not equal 
    }
}

int main() {
    char str1[100], str2[100];

    
    printf("Enter first string: ");
    scanf("%s", str1);

    printf("Enter second string: ");
    scanf("%s", str2);


    if (stringCompare(str1, str2)) {
        printf("Strings are equal.\n");
    } else {
        printf("Strings are NOT equal.\n");
    }

    return 0;
}

