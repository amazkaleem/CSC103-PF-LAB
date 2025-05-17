#include <stdio.h>


int countEven(int *arr, int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            count++;
        }
    }
    return count;
}

int main() {
    int numbers[] = {2, 7, 4, 9, 12, 5, 8, 11};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    int result = countEven(numbers, size);
    printf("Number of even integers: %d\n", result);
    return 0;
}
