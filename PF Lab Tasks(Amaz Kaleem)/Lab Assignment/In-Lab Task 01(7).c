#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, product;

    // While Loop
    printf("Please enter the number for which you want to find the factorial (while loop): ");
    scanf("%d", &n);
    product = 1;
    i = n;

    if (n == 0 || n == 1)
    {
        printf("The factorial is: 1\n");
    }
    else
    {
        while (i > 1)
        {
            product *= i;
            i--;
        }
        printf("Factorial (while loop) of %d is: %d\n", n, product);
    }

    // Do-While Loop
    printf("\nPlease enter the number for which you want to find the factorial (do-while loop): ");
    scanf("%d", &n);
    product = 1;
    i = n;

    if (n == 0 || n == 1)
    {
        printf("The factorial is: 1\n");
    }
    else
    {
        do
        {
            product *= i;
            i--;
        } while (i > 1);
        printf("Factorial (do-while loop) of %d is: %d\n", n, product);
    }

    // For Loop
    printf("\nPlease enter the number for which you want to find the factorial (for loop): ");
    scanf("%d", &n);
    product = 1;

    if (n == 0 || n == 1)
    {
        printf("The factorial is: 1\n");
    }
    else
    {
        for (i = n; i > 1; i--)
        {
            product *= i;
        }
        printf("Factorial (for loop) of %d is: %d\n", n, product);
    }

    return 0;
}
