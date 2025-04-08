#include <stdio.h>
#include <stdlib.h>


// Question: Make a program that calculates the sum, mean, minimum, and maximum of a series of numbers use while loop for this purpose.

int main() {
    int newArray[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int count, thisLength, max, min, sum = 0;
    double mean = 0.0;

    thisLength = sizeof(newArray) / sizeof(newArray[0]);

    // WHILE LOOP IMPLEMENTATION
    printf("\n--- WHILE LOOP IMPLEMENTATION ---\n");
    
    // Initialize variables for the while loop
    count = 0;
    sum = 0;
    min = max = newArray[0];

    while (count < thisLength)
    {
        sum = sum + newArray[count];
        if (newArray[count] < min) min = newArray[count];
        if (newArray[count] > max) max = newArray[count];
        
        count += 1;
    }

    mean = (double)sum / thisLength;
    
    printf("The sum of the array is: %d\n", sum);
    printf("The mean of the array is: %lf\n", mean);
    printf("The minimum value of the array is: %d\n", min);
    printf("The maximum value of the array is: %d\n", max);

    // DO-WHILE LOOP IMPLEMENTATION
    printf("\n--- DO-WHILE LOOP IMPLEMENTATION ---\n");
    
    // Reset variables for the do-while loop
    count = 0;
    sum = 0;
    min = max = newArray[0];

    do {
        sum = sum + newArray[count];
        if (newArray[count] < min) min = newArray[count];
        if (newArray[count] > max) max = newArray[count];
        
        count += 1;
    } while (count < thisLength);

    mean = (double)sum / thisLength;

    printf("The sum of the array is: %d\n", sum);
    printf("The mean of the array is: %lf\n", mean);
    printf("The minimum value of the array is: %d\n", min);
    printf("The maximum value of the array is: %d\n", max);
    
    // FOR LOOP IMPLEMENTATION
    printf("\n--- FOR LOOP IMPLEMENTATION ---\n");
    
    // Reset variables for the for loop
    sum = 0;
    min = max = newArray[0];
    
    for (count = 0; count < thisLength; count++)
    {
        sum = sum + newArray[count];
        if (newArray[count] < min) min = newArray[count];
        if (newArray[count] > max) max = newArray[count];
    }
    
    mean = (double)sum / thisLength;
    
    printf("The sum of the array is: %d\n", sum);
    printf("The mean of the array is: %lf\n", mean);
    printf("The minimum value of the array is: %d\n", min);
    printf("The maximum value of the array is: %d\n", max);
    
    return 0;
}