#include <stdio.h>
#include <stdlib.h>

int main()
{
    float radius;
    double Area;
    printf("Please enter any Value of radius of your choice: ");
    scanf("%f", &radius);
    Area = 3.141592653589793 * (radius * radius); 
    printf("Area of Circle: %.2lf\n", Area);
    return 0;
}