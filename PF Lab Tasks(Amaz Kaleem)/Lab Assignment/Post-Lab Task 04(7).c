#include <stdio.h>
#include <stdlib.h>

int main () {
    int i = 5, j;

    // WHILE loop
    printf("Pattern using WHILE loop:\n");
    i = 5;
    while (i > 0) {
        j = 0;
        while (j < i) {
            printf("*");
            j++;
        }
        printf("\n");
        i--;
    }

    // DO-WHILE loop
    printf("\nPattern using DO-WHILE loop:\n");
    i = 5;
    do {
        j = 0;
        while (j < i) {
            printf("*");
            j++;
        }
        printf("\n");
        i--;
    } while (i > 0);

    // FOR loop
    printf("\nPattern using FOR loop:\n");
    for (i = 5; i > 0; i--) {
        for (j = 0; j < i; j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
