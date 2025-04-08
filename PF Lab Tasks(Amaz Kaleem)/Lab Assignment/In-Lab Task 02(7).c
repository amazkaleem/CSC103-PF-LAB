#include <stdio.h>
#include <stdlib.h>
#include <math.h>


//Question: Newton-Raphson iteration
// Define the function f(x) = cos(x) - x
// The equation f(x) = 0 cannot be solved by mathematical analysis. In order to solve an equation like this we have to use a numerical method, typically on a computer. An often used method is called Newton-Raphson iteration.
// The principle is this:
// guess an x-value called x1 which you expect to be near the solution.
// calculate y1 = f(x1)
// calculate the derivative y1' = f'(x1) = -sin(x1) - 1.
// approximate the function f(x) with the straight line which is the tangent of the curve y= f(x) in the point (x1,y1). The tangent crosses the x-axis at the point
// 2 = x1 - y1 / y1'
// now x2 is (hopefully) nearer the solution than x1.
// Calculate x3 = x2 - y2 / y2' and so on until the solution is as accurate as you desire.
// stop with an error message if the x-values do not converge towards a solution.
// Let your program write out x1, y1, x2, y2, x3, y3, and so on. Try with different values for the initial guess, x1, and see if it converges towards the solution.

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