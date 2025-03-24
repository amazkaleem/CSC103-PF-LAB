#include <stdio.h>
int main() {
    float infahrenheit; 
    double incelsius;
    printf("Please enter temperature in Fahrenheit: ");
    scanf("%f", &infahrenheit);
    incelsius = (infahrenheit - 32) * 5 / 9;
    printf("Temperature in Celsius: %.2lf C\n", incelsius);
    return 0;
}