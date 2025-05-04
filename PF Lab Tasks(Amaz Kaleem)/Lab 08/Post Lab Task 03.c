#include <stdio.h>

void circularShiftRight(int *x, int *y, int *z) {
    int temp = *z;  // Store z's value temporarily
    *z = *y;        // Move y to z
    *y = *x;        // Move x to y
    *x = temp;      // Move original z to x
}

int main() {
    int a = 5, b = 8, c = 10;

    printf("Before circular shift:\n");
    printf("a = %d, b = %d, c = %d\n", a, b, c);
    
    circularShiftRight(&a, &b, &c);

    printf("After circular shift:\n");
    printf("a = %d, b = %d, c = %d\n", a, b, c);

    return 0;
}
