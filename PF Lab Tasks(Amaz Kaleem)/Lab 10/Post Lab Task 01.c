#include <stdio.h>

int main() {
    int ratings[40];
    int frequency[11] = {0};  
    int i, input;

    printf("Enter ratings from 40 students (scale of 1 to 10):\n");

    for (i = 0; i < 40; i++) {
        do {
            printf("Rating %d: ", i + 1);
            scanf("%d", &input);

            if (input < 1 || input > 10) {
                printf("Invalid rating! Please enter a value between 1 and 10.\n");
            }
        } while (input < 1 || input > 10);

        ratings[i] = input;
        frequency[input]++;
    }

   
    printf("\nSummary of Ratings:\n");
    for (i = 1; i <= 10; i++) {
        printf("Rating %2d: %d student(s)\n", i, frequency[i]);
    }

    return 0;
}

