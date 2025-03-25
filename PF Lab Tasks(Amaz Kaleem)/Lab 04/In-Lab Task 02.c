#include <stdio.h> 
int main() { 
    int number, reversedNum = 0; 
    int oldNum, thisDigit; 
    printf("Please enter a five-digit number: "); 
    scanf("%d", &number); 
    oldNum = number; 
    while (number != 0) { 
        thisDigit = number % 10; 
        reversedNum = reversedNum * 10 + thisDigit; 
        number = number / 10; 
        
    } 
        printf("Reversed number = %d\n", reversedNum);
    if (oldNum == reversedNum) 
    { 
        printf("The original and reversed forms are equal.\n"); 
        
    } 
    else { 
        printf("The original and reversed forms are not equal.\n");
        
    }
    return 0;
    
}
