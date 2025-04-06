#include <stdio.h> 
#include <stdlib.h>

int main() 
{ 
    int sum = 0;
    int i = 73;

    // WHILE loop
    while (i <= 415) {
        sum += i;
        i++;
    }

    printf("Using WHILE loop: The sum of values from 73 to 415 is: %d\n", sum); 

    // DO-WHILE loop
    sum = 0;
    i = 73;

    do {
        sum += i;
        i++;
    } while (i <= 415);

    printf("Using DO-WHILE loop: The sum of values from 73 to 415 is: %d\n", sum); 

    // FOR loop
    sum = 0;

    for (i = 73; i <= 415; i++) {
        sum += i;
    }

    printf("Using FOR loop: The sum of values from 73 to 415 is: %d\n", sum); 

    return 0; 
}
