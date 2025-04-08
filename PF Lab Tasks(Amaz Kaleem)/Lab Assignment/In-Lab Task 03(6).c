#include <stdio.h>


//Write a program that determines the number entered by the user is even or odd. After displaying the message (“Even” or “Odd”), it ask the user Do you want to enter another number (y/n). If the user enter y, it do the same process again otherwise exit.

int main() {
    int num;
    char choice;
    int i;

    // While loop version
    printf("=== Using WHILE loop ===\n");
    choice = 'y';

    while (choice == 'y' || choice == 'Y') {
        printf("Enter an integer: ");
        scanf("%d", &num);

        if (num % 2 == 0)
            printf("Even\n");
        else
            printf("Odd\n");

        printf("Do you want to enter another number? (y/n): ");
        scanf(" %c", &choice); // Note the space before %c to consume newline
    }

    // Do-while version
    printf("\n=== Using DO-WHILE loop ===\n");
    do {
        printf("Enter an integer: ");
        scanf("%d", &num);

        if (num % 2 == 0)
            printf("Even\n");
        else
            printf("Odd\n");

        printf("Do you want to enter another number? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    // For loop version — we'll simulate this with a break condition
    printf("\n=== Using FOR loop ===\n");
    for (;;) {
        printf("Enter an integer: ");
        scanf("%d", &num);

        if (num % 2 == 0)
            printf("Even\n");
        else
            printf("Odd\n");

        printf("Do you want to enter another number? (y/n): ");
        scanf(" %c", &choice);

        if (choice != 'y' && choice != 'Y') {
            break;
        }
    }

    return 0;
}
