#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h> 
int main() { 
    int num; 
    char ch; 
    bool reRun = false, isValid = false; 
    do 
    { 
        printf("Enter the value you want to test: \n");
        scanf("%d",&num); 
        if (num % 2 == 0) 
        { 
            printf("%d is Even\n",num); 
            
        } else 
        { 
            printf("%d is Odd\n",num); 
            
        } 
        printf("write Y/y or N/n to rerun or terminate program\n"); 
        scanf(" %c", &ch); 
        do { 
            if (ch == 'Y' || ch == 'y') 
            { 
                reRun = false; 
                isValid = true; 
            
            } else if (ch == 'N' || ch == 'n') 
            { 
                reRun = true; 
                isValid = true;
                
            } else 
            { 
                printf("Invalid input! please enter character again\n"); 
                printf("write Y/y or N/n to rerun or terminate program\n");
                scanf(" %c", &ch); 
                
            } 
            
        } while (isValid == false); 
        
    } while (reRun == false);
    
    return 0;
    
}
