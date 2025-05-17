#include <stdio.h>


int runningSum(int n) {
    if (n == 0) {
        return 0;  
    } else {
        return n + runningSum(n - 1); 
    }
}


int main() {
    int newNum;
 	
    printf("Please enter a number: \n");
    scanf("%d", &newNum);
    
    int result2 = runningSum(newNum); 
    printf("The running sum of the first  natural numbers is: %d\n", result2);
    
    return 0;
}