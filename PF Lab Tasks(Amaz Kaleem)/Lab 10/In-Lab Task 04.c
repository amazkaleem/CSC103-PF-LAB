#include <stdio.h>

int main() {
    int arr[10];
    int i, smallest, largest;

    
    printf("Enter 10 integers:\n");
    for (i = 0; i < 10; i++) {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    
    smallest = largest = arr[0];

    
    for (i = 1; i < 10; i++) {
        if (arr[i] < smallest) {
            smallest = arr[i];
        }
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }

    
    printf("\nSmallest number: %d\n", smallest);
    printf("Largest number: %d\n", largest);

    return 0;
}

