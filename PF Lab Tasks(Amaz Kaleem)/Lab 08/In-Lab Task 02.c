#include <stdlib.h>
#include <stdio.h>

// Function renamed to match what's called in main
void findPrimeFactors(int* thisArray, int thisNum) {

    // Initializing array with zeros
    for (int i = 0; i < thisNum; i++) {
        thisArray[i] = 0;
    }
    
    int n = thisNum;
    int idx = 0;
    
    // Checking if 2 is a factor
    while (n % 2 == 0) {
        thisArray[idx++] = 2;
        n /= 2;
    }
    
    // Checking for all odd factors
    // Mathematical Principle: If a number n has no factors less than or equal to √n, then n must be prime.
    // Why It Works: If n = a × b where both a and b are greater than √n, then a × b would be greater than n, which is impossible.
    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            thisArray[idx++] = i;
            n /= i;
        }
    }
    
    // If n is a prime number greater than 2
    if (n > 2) {
        thisArray[idx] = n;
    }
}

int main() {
    int num1 = 0;
    
    printf("Please enter a number for which you want to find the prime factors:\n");
    scanf("%d", &num1);
    
    int primeFactors[num1];
    
    
    findPrimeFactors(primeFactors, num1);
    
    printf("Prime factors of %d are: ", num1);
    for (int i = 0; i < num1; i++) {
        if (primeFactors[i] != 0) {
            printf("%d ", primeFactors[i]);
        }
    }
    printf("\n");
    
    return 0;
}