#include <stdio.h> 
#include <stdlib.h> 

//Question: Write a program that input one integer n from the user. It prints all the even number from 1 to n.

int main() 
{ 
    int n, i;

    // WHILE loop implementation
    printf("Enter an integer (WHILE loop): "); 
    scanf("%d", &n); 

    i = 1;
    while (i <= n) {
        if (i % 2 == 0) {
            printf("%d is even\n", i);
        }
        i++;
    }

    // DO-WHILE loop implementation
    printf("\nEnter an integer (DO-WHILE loop): "); 
    scanf("%d", &n); 

    i = 1;
    if (n >= 1) {
        do {
            if (i % 2 == 0) {
                printf("%d is even\n", i);
            }
            i++;
        } while (i <= n);
    }

    // FOR loop implementation
    printf("\nEnter an integer (FOR loop): "); 
    scanf("%d", &n); 

    for (i = 1; i <= n; i++) {
        if (i % 2 == 0) {
            printf("%d is even\n", i);
        }
    }

    return 0;
}
