#include <stdio.h>
#include <stdlib.h>

int main() 
{ 
    float alpha, beta, gamma,sigma; 
    double total;
    printf("Please enter the values of the three angles separated by spaces in between: "); 
    scanf("%f %f %f", &alpha, &beta, &gamma); 
    total = alpha + beta + gamma; 
    if (total == 180.0) { 
        printf("Your triangle is Valid"); 
        
    } else 
    { printf("Your triangle is Invalid"); 
        
    } return 0; 
    
}
