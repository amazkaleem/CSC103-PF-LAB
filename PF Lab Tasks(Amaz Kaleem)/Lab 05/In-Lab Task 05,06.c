#include <stdio.h> 
#include <stdlib.h> 
#include <math.h>  // Add this line to include math.h

int main() { 
    double side1, side2, side3, semiParameter, area; 
    printf("Enter the three sides of the triangle: "); 
    scanf("%lf %lf %lf", &side1, &side2, &side3); 
    if (side1 + side2 > side3 && side2 + side3 > side1 && side1 + side3 > side2) { 
        semiParameter = (side1 + side2 + side3) / 2; 
        area = sqrt(semiParameter * (semiParameter - side1) * (semiParameter - side2) * (semiParameter - side3)); 
        printf("The given sides do form a valid triangle.\n"); 
        printf("The area of the triangle is: %.2lf", area); 
    } else { 
        printf("The given sides do not form a valid triangle."); 
    } 
    return 0;
}
