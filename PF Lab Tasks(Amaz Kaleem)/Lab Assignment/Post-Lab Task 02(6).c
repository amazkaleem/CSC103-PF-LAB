#include <stdio.h> 
#include <stdlib.h> 
int main() 
{ 
    int n; 
    printf("Enter an integer: "); 
    scanf("%d", &n); 


    int i = 1;

    //while loop
    while (i <= n) {
        if ( i % 2 == 0) {
            printf("%d is even\n", i);
        }
        i++;
    }

    //do-while loop
    i = 1;
    n = 0;
    printf("Enter an integer again: ");
    scanf("%d", &n);

    do {
        if ( i % 2 == 0) {
            printf("%d is even\n", i);
        }
        i++;
    } while (i <= n);
    
    return 0;
}
