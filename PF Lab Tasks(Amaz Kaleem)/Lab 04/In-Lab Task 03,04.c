#include <stdio.h> 
#include<stdlib.h> 
int main() 
{ 
    int thisYear; 
    printf("Please enter an year you want to check for leap year: "); 
    scanf("%d", &thisYear); 
    if ((thisYear % 4 == 0 && thisYear % 100 != 0) || (thisYear % 400 == 0)) 
    { 
        printf("%d is a leap year", thisYear); 
        
    } else 
    { 
        printf("%d is not a leap year", thisYear); 
        
    } 
    return 0; 
    
}
