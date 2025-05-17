#include <stdio.h>

int main() {
    int arr[10];
    int i, value, found = 0;

    
    printf("Enter 10 different integers:\n");
    for (i = 0; i < 10; i++) {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

   
    printf("\nEnter the value to search: ");
    scanf("%d", &value);

   
    for (i = 0; i < 10; i++) {
        if (arr[i] == value) {
            found = 1;
            break;
        }
    }

    
    if (found) {
        for (i = 0; i < 10; i++) {
            arr[i] += value;
        }

        
        printf("\nValue found. Modified array:\n");
        for (i = 0; i < 10; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    } else {
        printf("\nValue not found in the array.\n");
    }

    return 0;
}

