#include <stdio.h>
#include <stdlib.h>

int main () {
    int i = 5 , j;

    while (i > 0) {
        j = 0;
        while (j < i) {
            printf("*");
            j++;
        }
        printf("\n");
        i--;
    }
    return 0;
}