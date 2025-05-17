#include <stdio.h>

int main() {
    int original[10];
    int reversed[10];
    int i;

    
    printf("Enter 10 integers:\n");
    for (i = 0; i < 10; i++) {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &original[i]);
    }

    
    for (i = 0; i < 10; i++) {
        reversed[i] = original[9 - i];
    }

   
    printf("\nOriginal array:\n");
    for (i = 0; i < 10; i++) {
        printf("%d ", original[i]);
    }

    
    printf("\n\nReversed array:\n");
    for (i = 0; i < 10; i++) {
        printf("%d ", reversed[i]);
    }

    printf("\n");

    return 0;
}

