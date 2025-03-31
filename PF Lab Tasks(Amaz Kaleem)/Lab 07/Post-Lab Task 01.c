#include <stdio.h>
#include <stdlib.h>


int main() {
    int newArray[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int count, thisLength, max, min, sum = 0;

    double mean = 0.0;

    thisLength = sizeof(newArray) / sizeof(newArray[0]);

    min = max = newArray[0];


    //while loop
    while (count < thisLength)
    {
        sum = sum + newArray[count];
        if (newArray[count] < min) min = newArray[count];
        if (newArray[count] > max) max = newArray[count];
        
        count += 1;
    }

    mean = (double)sum / thisLength; //When you cast one operand to double, the division becomes floating-point division and gives you the correct result. Here’s what happens:

    // 1. (double) sum converts sum into a double.
    
    // 2. Since one operand is now double, C automatically promotes the other operand (length) to double too.
    
    // 3. The result is a double with the correct decimal value.
    
    printf("The sum of the array is: %d\n", sum);
    printf("The mean of the array is: %lf\n", mean);
    printf("The minimum value of the array is: %d\n", min);
    printf("The maximum value of the array is: %d\n", max);

    count = min =  max =  sum = 0;
    mean = 0.0;

    min = max = newArray[0];

    //do-while loop
    do {
        sum = sum + newArray[count];
        if (newArray[count] < min) min = newArray[count];
        if (newArray[count] > max) max = newArray[count];
        

        count += 1;
    } while (count < thisLength);


    mean = (double)sum / thisLength;

    printf("The sum of the array now is: %d\n", sum);
    printf("The mean of the array now is: %lf\n", mean);
    printf("The minimum value of the array now is: %d\n", min);
    printf("The maximum value of the array now is: %d\n", max);
    
    return 0;
}