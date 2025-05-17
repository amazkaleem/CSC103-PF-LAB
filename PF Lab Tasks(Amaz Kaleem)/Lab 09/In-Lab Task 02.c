#include <stdio.h>


int main() {
    int f = 10;
    int g = 10;
    int *c = &f;
    int *d = &g;
    
    int sum = *c + *d;
    
    printf("The answer to the second problem is: %d\n", sum);


    return 0;

}