#include <stdio.h>
#include <string.h>


char* strrev_custom(char* str) {
    int i, j;
    char temp;
    int len = strlen(str);

    for (i = 0, j = len - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }

    return str;
}

int main() {
    char src[50] = "Hello, World!";
    char dest[50];

    // 1. strcpy
    strcpy(dest, src);
    printf("1. After strcpy, dest: %s\n", dest);

    // 2. strcmp
    int cmpResult = strcmp(src, dest);
    printf("2. strcmp result: %d\n", cmpResult);

    // 3. strcat
    strcat(dest, " C Programming");
    printf("3. After strcat, dest: %s\n", dest);

    // 4. strchr
    char* foundChar = strchr(src, 'W');
    if (foundChar) {
        printf("4. strchr found: %c at position: %ld\n", *foundChar, foundChar - src);
    } else {
        printf("4. Character not found using strchr\n");
    }

    // 5. strrev
    char toReverse[50] = "ReverseMe";
    printf("5. Original string: %s\n", toReverse);
    printf("   Reversed string: %s\n", strrev_custom(toReverse));

    return 0;
}

