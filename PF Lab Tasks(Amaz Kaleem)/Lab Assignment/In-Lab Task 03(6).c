#include <stdio.h>

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
