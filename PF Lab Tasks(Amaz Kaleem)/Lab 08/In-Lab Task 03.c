#include <stdio.h>

float power(float base, int exponent) {
    float result = 1.0;
    int i;
    int abs_exponent;
    
    abs_exponent = (exponent < 0) ? -exponent : exponent;
    
    for (i = 0; i < abs_exponent; i++) {
        result *= base;
    }
    
    // Handling negative exponents by taking reciprocal
    if (exponent < 0) {
        result = 1.0 / result;
    }
    
    return result;
}

void powerFunction() {
    float num;
    int pow;
    
    printf("Please enter a number: ");
    scanf("%f", &num);
    
    printf("Please enter the power to which you want the number to be raised: ");
    scanf("%d", &pow);
    
    float answer = power(num, pow);
    
    printf("The answer is: %f\n", answer);
}

int main() {
    powerFunction();
    return 0;
}