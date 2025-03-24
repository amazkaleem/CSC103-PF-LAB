#include <stdio.h>

int main() {

    //declaration
    float length, breadth, radius, perimeter, areaRectangle; 
    double circumference, areaCircle;

    printf("Enter the length and breadth of the rectangle: ");
    scanf("%f %f", &length, &breadth);

    printf("Enter the radius of the circle: ");
    scanf("%f", &radius);

    perimeter = 2 * (length + breadth);
    areaRectangle = length * breadth;
    circumference = 2 * 3.141592653589793 * radius;
    areaCircle = 3.141592653589793 * radius * radius;

    printf("The perimeter of the rectangle is: %.2f\n", perimeter);
    printf("The area of the rectangle is: %.2f\n", areaRectangle);
    printf("The circumference of the circle is: %.2lf\n", circumference);
    printf("The area of the circle is: %.2lf\n", areaCircle);
    return 0;

}