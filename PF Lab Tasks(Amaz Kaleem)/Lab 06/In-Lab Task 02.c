#include <stdio.h> 
#include <stdlib.h> 
int main() 
{ 
    int a,b,count,answer; 
    printf("Please enter values of x and y separated by spaces: "); 
    scanf("%d %d",&a,&b); 
    for (count= 1;count < (b + 1);count++) { 
        answer = a * count; 
        printf("%d * %d = %d\n",a,count,answer); 
        
    } 
    return 0;
}
