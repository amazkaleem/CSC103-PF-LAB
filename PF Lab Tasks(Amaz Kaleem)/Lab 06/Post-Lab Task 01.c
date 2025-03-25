#include <stdio.h> 
#include <stdlib.h>

int main() 
{ 
    int sum = 0; 
    for (int i = 73; i < 416; i++) 
    { 
        sum += i; 
    } 
    printf("The sum of values from 73 to 415 is: %d\n", sum); 
    return 0; 
}
