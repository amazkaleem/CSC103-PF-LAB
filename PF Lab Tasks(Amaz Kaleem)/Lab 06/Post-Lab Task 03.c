#include <stdio.h> 
#include <stdlib.h> 

int main() 
{ 
    char ch = 'x'; 
    int count = 0; 
    printf("Enter characters and stop with a space: \n"); 
    for (; ;) 
    { 
        scanf("%c", &ch); 
        if (ch == ' ') 
        { 
            break; 
        } 
        count++; //These also include new line characters 
    } 
    printf("nonblank characters: %d\n", count);

    return 0;
}
