#include <stdio.h>
#include <stdlib.h>


//Question: Write a program using while loop which Prints the following pattern up to 10 lines
// 0
// 111
// 22222
// 3333333

int main() {
    int i, j;

    printf("=== USING WHILE LOOP ===\n");
    i = 0;
    while (i < 10) {
        j = 0;
        while (j < 2 * i + 1) {
            printf("%d", i);
            j++;
        }
        printf("\n");
        i++;
    }

    printf("\n=== USING DO-WHILE LOOP ===\n");
    i = 0;
    do {
        j = 0;
        do {
            printf("%d", i);
            j++;
        } while (j < 2 * i + 1);
        
        printf("\n");
        i++;
    } while (i < 10);
    
    printf("\n=== USING FOR LOOP ===\n");
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 2 * i + 1; j++) {
            printf("%d", i);
        }
        printf("\n");
    }
    
    return 0;
}