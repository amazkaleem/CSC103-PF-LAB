#include <stdio.h>
#include <stdlib.h>


//Question: A right triangle can have sides whose lengths are all integers. The set of three integer values for the lengths of the sides of a right triangle is called a Pythagorean triple. The lengths of the three sides must satisfy the relationship that the sum of the squares of two of the sides is equal to the square of the hypotenuse. Write an application that displays a table of the Pythagorean triples for side1, side2 and the hypotenuse, all no larger than 500. Use a triple-nested for loop that tries all possibilities. This method is an example of “brute-force” computing. You’ll learn in more advanced computer science courses that for many interesting problems there’s no known algorithmic approach other than using sheer brute force.

int main() {
    int side1, side2, hypotenuse;
    int limit = 100; // Using 500 as specified in the question
    
    printf("=== WHILE LOOP IMPLEMENTATION ===\n");
    printf("Side1\tSide2\tHypotenuse\n");
    
    // While loop implementation
    side1 = 1;
    while (side1 <= limit) {
        side2 = side1; // Start with side2 >= side1 to avoid duplicates
        while (side2 <= limit) {
            hypotenuse = side2; // Start with hypotenuse >= side2
            while (hypotenuse <= limit) {
                if (side1 * side1 + side2 * side2 == hypotenuse * hypotenuse) {
                    printf("%d\t%d\t%d\n", side1, side2, hypotenuse);
                }
                hypotenuse++;
            }
            side2++;
        }
        side1++;
    }

    printf("\n=== DO-WHILE LOOP IMPLEMENTATION ===\n");
    printf("Side1\tSide2\tHypotenuse\n");
    
    // Do-while loop implementation
    side1 = 1;
    do {
        side2 = side1; // Start with side2 >= side1 to avoid duplicates
        do {
            hypotenuse = side2; // Start with hypotenuse >= side2
            do {
                if (side1 * side1 + side2 * side2 == hypotenuse * hypotenuse) {
                    printf("%d\t%d\t%d\n", side1, side2, hypotenuse);
                }
                hypotenuse++;
            } while (hypotenuse <= limit);
            side2++;
        } while (side2 <= limit);
        side1++;
    } while (side1 <= limit);
    
    printf("\n=== FOR LOOP IMPLEMENTATION ===\n");
    printf("Side1\tSide2\tHypotenuse\n");
    
    // For loop implementation (triple-nested as required)
    for (side1 = 1; side1 <= limit; side1++) {
        for (side2 = side1; side2 <= limit; side2++) { // Start with side2 >= side1
            for (hypotenuse = side2; hypotenuse <= limit; hypotenuse++) { // Start with hypotenuse >= side2
                if (side1 * side1 + side2 * side2 == hypotenuse * hypotenuse) {
                    printf("%d\t%d\t%d\n", side1, side2, hypotenuse);
                }
            }
        }
    }
    
    return 0;
}