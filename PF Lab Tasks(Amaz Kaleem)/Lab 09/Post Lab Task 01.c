#include <stdio.h>


int gcd(int x, int y) {
    if (y == 0)
        return x;
    else
        return gcd(y, x % y);
}

int main() {
    int x = 48, y = 18;
    printf("GCD of %d and %d is %d\n", x, y, gcd(x, y));
    return 0;
}
