#include <stdio.h>
#include <stdlib.h>
int main () {
    int i = 5 , j;

    //while loop
    while (i > 0) {
        j = 0;
        while (j < i) {
            printf("*");
            j++;
        }
        printf("\n");
        i--;
    }

    //do-while loop
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

    return 0;
}
