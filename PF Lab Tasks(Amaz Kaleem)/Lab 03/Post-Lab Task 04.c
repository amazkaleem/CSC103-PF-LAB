#include <stdio.h>

int main() {
    int C, D, temp;
    printf("Enter two numbers C and D separated by space: ");
    scanf("%d %d", &C, &D);

    //swapping process
    temp = C;
    C = D;
    D = temp;

    printf("After swapping, C has become %d AND D has become %d\n", C, D);

    return 0;
}