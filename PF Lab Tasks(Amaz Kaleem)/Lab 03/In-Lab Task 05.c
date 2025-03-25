#include <stdio.h>
#include <stdlib.h>
int main()
{
    int num1, num2, sum, subtract, multiply;
    double division;
    printf("Enter 2 numbers separated by space in between: ");
    scanf("%d %d", &num1, &num2);
    sum = num1 + num2;
    subtract = num1 - num2;
    multiply = num1 * num2;
    division = (double) num1/num2;
    printf("Sum Result: %d \n",sum);
    printf("Subtraction Result: %d \n", subtract);
    printf("Multiplication Result: %d \n", multiply);
    printf("Division Result: %.2f \n", division);
    return 0;
}