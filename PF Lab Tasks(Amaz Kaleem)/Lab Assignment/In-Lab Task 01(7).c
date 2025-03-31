#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, product;
    printf("Please enter the number for which you want to find the factorial: ");
    scanf("%d", &n);
    product = n;

    if (n == 0 || n == 1) 

    {
        printf("The factorial of the number is: %d\n", product);
    }
    else {
        //Calculating Factorial using while loop
        while (n > 1)
        {
            n = n - 1;
            product = product * n;
            printf("Product: %d\n", product);
        }

        printf("The factorial of the number is: %d\n", product);

        printf("Please enter the second number for which you want to find the factorial: ");
        scanf("%d", &n);
        product = n;

        //Calculating Factorial using do-while loop
        do 
        {
            n = n - 1;
            product = product * n;
            printf("Product: %d\n", product);
        }
        while (n > 2);
        

        printf("The factorial of the number is: %d\n", product);

    }

    return 0;
}