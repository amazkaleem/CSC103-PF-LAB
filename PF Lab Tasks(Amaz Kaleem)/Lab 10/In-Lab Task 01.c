#include <stdio.h>

int main() {
    int arr[10];  
    int i;

    printf("Enter 10 integers:\n");
    for (i = 0; i < 10; i++) {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("\nThe array is:\n");
    for (i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

