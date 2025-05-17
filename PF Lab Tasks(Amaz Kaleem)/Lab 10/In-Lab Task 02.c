#include <stdio.h>

// Function to input values
void inputArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

// Function to display values
void displayArray(int arr[], int size) {
    int i;
    printf("\nThe array is:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int arr[10];
    int size = 10;

    printf("Enter 10 integers:\n");
    inputArray(arr, size);
    displayArray(arr, size);

    return 0;
}


