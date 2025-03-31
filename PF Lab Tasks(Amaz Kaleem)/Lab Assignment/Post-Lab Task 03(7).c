#include <stdio.h>
#include <stdlib.h>

int main() {
    int i = 0, j;

    //while-loop
    while (i < 10) {
        j = 0;
        while (j < 2 * i + 1) {
            printf("%d", i);
            j++;
        }
        printf("\n");
        i++;
    }

    //do-while loop
    int a = 0, b;
    
    do {
        b = 0;
        do {
            printf("%d", a);
            b++;
        } while (b < 2 * a + 1);
        
        printf("\n");
        a++;
    } while (a < 10);
    
    return 0;
}
