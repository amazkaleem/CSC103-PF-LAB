#include <stdio.h> 
#include <stdlib.h> 

//Write a program that input two integers x and y from the user. It calculates and then displays the x raise to power y (xy).

int main() 
{ 
    int x, y, result, i;

    // WHILE LOOP implementation
    printf("=== Using WHILE loop ===\n");
    printf("Enter the values of x & y separated by space: "); 
    scanf("%d %d", &x, &y); 

    result = 1;
    i = 1;
    while (i <= y) {
        result *= x;
        i++;
    }
    printf("%d raised to the power %d = %d\n", x, y, result); 

    // DO-WHILE LOOP implementation
    printf("\n=== Using DO-WHILE loop ===\n");
    printf("Enter the values of x & y separated by space: "); 
    scanf("%d %d", &x, &y); 

    result = 1;
    i = 1;
    if (y >= 1) {
        do {
            result *= x;
            i++;
        } while (i <= y);
    } else {
        result = 1;  // x^0 = 1
    }
    printf("%d raised to the power %d = %d\n", x, y, result); 

    // FOR LOOP implementation
    printf("\n=== Using FOR loop ===\n");
    printf("Enter the values of x & y separated by space: "); 
    scanf("%d %d", &x, &y); 

    result = 1;
    for (i = 1; i <= y; i++) {
        result *= x;
    }
    printf("%d raised to the power %d = %d\n", x, y, result); 

    return 0;
}
