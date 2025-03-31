#include <stdio.h> 
#include <stdlib.h> 
int main() 
{ 
    int x,y,result = 1; 
    printf("Enter the values of x & y separated by space in between: "); 
    scanf("%d %d", &x, &y); 


    // while loop
    int i = 1;
    while (i < (y + 1)) {
        result *= x;
        i++;
    }

    printf("%d raised to the power %d = %d\n",x,y,result); 


    //do-while loop
    i = 1;
    result = 1;

    do {
        result *= x;
        i++;
    } while (i < (y + 1));

    printf("%d raised to the power %d = %d\n",x,y,result);

    return 0;
        
}