#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()  {
    int y, count;
    double x, func, derivative;

    count = 3;

    //while implementation
    printf("Please guess a number that you think is closer to the solution. It should be in degrees: \n");
    scanf("%lf", &x);

    // Convert degrees to radians (C expects radians)
    x = x * (3.14159265 / 180.0);

    while (count > 0) 
    {

        count = count - 1;
        func = cos(x) - x;
        derivative = -sin(x) - 1;

        x = x - (func/derivative);

        printf("\n Your current value of x is: %lf in radians\n", x);
        fflush(stdout);
    }



    //do-while implementation

    printf("Please guess a number a second time that you think is closer to the solution. It should be in degrees: \n");
    scanf("%lf", &x);

    // Convert degrees to radians (C expects radians)
    x = x * (3.14159265 / 180.0);

    count = 3;

    do 
    {

        func = cos(x) - x;
        derivative = -sin(x) - 1;

        x = x - (func/derivative);

        printf("\n Your current value of x is: %lf in radians\n", x);
        fflush(stdout);
        count = count - 1;
    }
    while (count > 0);

    return 0;
}
