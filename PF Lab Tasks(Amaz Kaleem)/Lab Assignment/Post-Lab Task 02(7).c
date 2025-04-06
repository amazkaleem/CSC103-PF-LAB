#include <stdio.h>
#include <stdlib.h>

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