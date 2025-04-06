#include <stdio.h>
#include <stdlib.h>

int main() {
    int x, y, count;

    // While Loop
    printf("Please enter values of x and y (while loop): ");
    scanf("%d %d", &x, &y);

    count = 1;
    while (count <= y) {
        printf("%d x %d = %d\n", x, count, x * count);
        count++;
    }

    // Do-While Loop
    printf("\nPlease enter values of x and y (do-while loop): ");
    scanf("%d %d", &x, &y);

    count = 1;
    do {
        printf("%d x %d = %d\n", x, count, x * count);
        count++;
    } while (count <= y);

    // For Loop
    printf("\nPlease enter values of x and y (for loop): ");
    scanf("%d %d", &x, &y);

    for (count = 1; count <= y; count++) {
        printf("%d x %d = %d\n", x, count, x * count);
    }

    return 0;
}
