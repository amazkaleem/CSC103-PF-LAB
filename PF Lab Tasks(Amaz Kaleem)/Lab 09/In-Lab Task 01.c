#include <stdio.h>

float recursiveCall(int a, int b) {
    if (b == 0) {
        return 1;  
    }
    
    if (b > 0) {
        return a * recursiveCall(a, b - 1); 
    } else if (b < 0) {
        return (1.0 / a) * recursiveCall(a, b + 1);  
	}
    
}



int main() {
    int a, b;
    float result;
    
    printf("Enter the value of the base: \n");
    scanf("%d", &a);
    
    printf("Enter the value of the exponent: \n");
    scanf("%d", &b);
    
    result = recursiveCall(a, b);  
    
    printf("The answer is: %.2f\n", result);


    return 0;

}