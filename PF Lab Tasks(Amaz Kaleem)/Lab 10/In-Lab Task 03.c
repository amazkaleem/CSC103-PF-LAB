#include <stdio.h>


void inputArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}


void displayArray(int arr[], int size) {
    int i;
    printf("\nThe array is:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


void calculateSumAndAverage(int arr[], int size) {
    int i, sum = 0;
    float average;

    for (i = 0; i < size; i++) {
        sum += arr[i];
    }

    average = (float)sum / size;

    printf("\nSum of array elements: %d\n", sum);
    printf("Average of array elements: %.2f\n", average);
}


int main() {
    int arr[10];
    int size = 10;

    printf("Enter 10 integers:\n");
    inputArray(arr, size);

    displayArray(arr, size);

    calculateSumAndAverage(arr, size);

    return 0;
}

