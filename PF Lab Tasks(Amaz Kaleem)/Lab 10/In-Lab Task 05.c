#include <stdio.h>

int main() {
    int arr[5];
    int i;
    int positive = 0, negative = 0, even = 0, odd = 0;

    
    printf("Enter 5 different numbers:\n");
    for (i = 0; i < 5; i++) {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    
    for (i = 0; i < 5; i++) {
        
        if (arr[i] > 0) {
            positive++;
        } else if (arr[i] < 0) {
            negative++;
        }

        
        if (arr[i] % 2 == 0) {
            even++;
        } else {
            odd++;
        }
    }

   
    printf("\nResults:\n");
    printf("Positive numbers: %d\n", positive);
    printf("Negative numbers: %d\n", negative);
    printf("Even numbers: %d\n", even);
    printf("Odd numbers: %d\n", odd);

    return 0;
}

