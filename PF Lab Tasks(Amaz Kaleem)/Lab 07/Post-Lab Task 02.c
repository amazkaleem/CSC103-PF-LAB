#include <stdio.h>
#include <stdlib.h>

int main() {
    int adjacent, base, hypotenuse;
    printf("Side1\tSide2\tHypotenuse\n");
        for (adjacent = 1; adjacent <= 100; adjacent++) {
            for (base = adjacent; base <= 100; base++) {
                for (hypotenuse = base; hypotenuse <= 100; hypotenuse++) {
                    if (adjacent * adjacent + base * base == hypotenuse * hypotenuse) {
                        printf("%d\t%d\t%d\n", adjacent, base, hypotenuse);
                    }
                }
            }
        }
    return 0;
}