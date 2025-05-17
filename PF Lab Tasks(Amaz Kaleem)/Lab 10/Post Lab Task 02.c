#include <stdio.h>


void modify(int arr[], int size) {
	int i;
    for (i = 0; i < size; i++) {
        arr[i] = arr[i] * 3;
    }
}

int main() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; 
    int size = 10;

    
    modify(arr, size);

   
    printf("Modified array (each element multiplied by 3):\n");
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

