#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    double x, func, derivative;
    int count, max_iterations;
    
    max_iterations = 3;
    
    // while implementation
    printf("=== WHILE LOOP IMPLEMENTATION ===\n");
    printf("Please guess a number that you think is closer to the solution. It should be in degrees: \n");
    scanf("%lf", &x);

    // Convert degrees to radians (C expects radians)
    x = x * (3.14159265 / 180.0);
    
    count = 0;
    printf("Starting x: %lf radians\n", x);
    
    while (count < max_iterations) {
        func = cos(x) - x;
        derivative = -sin(x) - 1;
        
        x = x - (func/derivative);
        count++;
        
        printf("Iteration %d: x = %lf radians, f(x) = %lf\n", count, x, cos(x) - x);
    }
    
    // do-while implementation
    printf("\n=== DO-WHILE LOOP IMPLEMENTATION ===\n");
    printf("Please guess a number a second time that you think is closer to the solution. It should be in degrees: \n");
    scanf("%lf", &x);

    // Convert degrees to radians (C expects radians)
    x = x * (3.14159265 / 180.0);
    
    count = 0;
    printf("Starting x: %lf radians\n", x);
    
    do {
        func = cos(x) - x;
        derivative = -sin(x) - 1;
        
        x = x - (func/derivative);
        count++;
        
        printf("Iteration %d: x = %lf radians, f(x) = %lf\n", count, x, cos(x) - x);
    } while (count < max_iterations);
    
    // for loop implementation
    printf("\n=== FOR LOOP IMPLEMENTATION ===\n");
    printf("Please guess a number a third time that you think is closer to the solution. It should be in degrees: \n");
    scanf("%lf", &x);

    // Convert degrees to radians (C expects radians)
    x = x * (3.14159265 / 180.0);
    
    printf("Starting x: %lf radians\n", x);
    
    for (count = 0; count < max_iterations; count++) {
        func = cos(x) - x;
        derivative = -sin(x) - 1;
        
        x = x - (func/derivative);
        
        printf("Iteration %d: x = %lf radians, f(x) = %lf\n", count + 1, x, cos(x) - x);
    }
    
    printf("\nFinal solution (approximate): x = %lf radians (%lf degrees)\n", 
           x, x * (180.0 / 3.14159265));
    printf("f(x) at this point: %lf (should be close to zero)\n", cos(x) - x);
    
    return 0;
}