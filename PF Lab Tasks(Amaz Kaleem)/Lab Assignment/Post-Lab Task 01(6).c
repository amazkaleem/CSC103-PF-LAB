#include <stdio.h> 
#include <stdlib.h>

int main() 
{ 
    int sum = 0;
    int i = 73; 

    //while loop
    while (i < 416) {
        sum += i;
        i++;
    }

    printf("The sum of values from 73 to 415 is: %d\n", sum); 
    
    //do-while loop
    sum = 0;
    i = 73;

    do {
        sum += i;
        i++;
    } while (i < 416);

    printf("The sum of values from 73 to 415 is: %d\n", sum); 
    return 0; 
}