#include <stdio.h>
#include <stdlib.h>

int main() {
    int adjacent = 1, base, hypotenuse;
    
    printf("Side1\tSide2\tHypotenuse\n");
    
    //while loop
    while (adjacent <= 100) {
        base = adjacent;
        while (base <= 100) {
            hypotenuse = base;
            while (hypotenuse <= 100) {
                if (adjacent * adjacent + base * base == hypotenuse * hypotenuse) {
                    printf("%d\t%d\t%d\n", adjacent, base, hypotenuse);
                }
                hypotenuse++;
            }
            base++;
        }
        adjacent++;
    }

    //do-while loop
    adjacent = 1; 
    base = 0; 
    hypotenuse = 0;
    
    printf("Side1\tSide2\tHypotenuse\n");
    
    do {
        base = adjacent;
        do {
            hypotenuse = base;
            do {
                if (adjacent * adjacent + base * base == hypotenuse * hypotenuse) {
                    printf("%d\t%d\t%d\n", adjacent, base, hypotenuse);
                }
                hypotenuse++;
            } while (hypotenuse <= 100);
            base++;
        } while (base <= 100);
        adjacent++;
    } while (adjacent <= 100);
    
    return 0;

}