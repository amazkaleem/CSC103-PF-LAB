#include <stdio.h> 
#include <stdlib.h> 

int main() { 
    int firstNum, secondNum, opResult; 
    char op; 

    // Prompt the user for input
    printf("Enter the first and second value separated by space: "); 
    scanf("%d %d", &firstNum, &secondNum); 
    
    printf("Choose an operation (+, -, *, /, %%): "); 
    scanf(" %c", &op);  // Notice the space before %c to consume any leftover newline character

    // Switch statement to perform the chosen operation
    switch(op) { 
        case '+': 
            opResult = firstNum + secondNum; 
            printf("%d + %d = %d\n", firstNum, secondNum, opResult); 
            break; 
        case '-': 
            opResult = firstNum - secondNum; 
            printf("%d - %d = %d\n", firstNum, secondNum, opResult); 
            break; 
        case '*': 
            opResult = firstNum * secondNum; 
            printf("%d * %d = %d\n", firstNum, secondNum, opResult); 
            break; 
        case '/': 
            if (secondNum != 0) {  // Check for division by zero
                opResult = firstNum / secondNum; 
                printf("%d / %d = %d\n", firstNum, secondNum, opResult); 
            } else {
                printf("Error: Division by zero is not allowed.\n");
            }
            break; 
        case '%': 
            if (secondNum != 0) {  // Check for modulus by zero
                opResult = firstNum % secondNum; 
                printf("%d %% %d = %d\n", firstNum, secondNum, opResult); 
            } else {
                printf("Error: Modulus by zero is not allowed.\n");
            }
            break; 
        default: 
            printf("Invalid operation selected.\n"); 
            break; 
    } 

    return 0; 
}
