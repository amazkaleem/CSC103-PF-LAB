#include <stdio.h>
#include <stdlib.h>

int main() {
    int i = 0, j;
    while (i < 10) {
        j = 0;
        while (j < 2 * i + 1) {
            printf("%d", i);
            j++;
        }
        printf("\n");
        i++;
    }
    return 0;
}