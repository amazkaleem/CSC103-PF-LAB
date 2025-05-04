#include <stdio.h>
#include <stdlib.h>


float sum() {
    int num1=0, num2=0, num3=0, num4=0, num5=0;
    int sum = 0;
    float average = 0.0;


    //Prompting for all user marks
    printf("Enter the first integer: \n");
    scanf("%d", &num1);
    printf("Enter the second integer: \n");
    scanf("%d", &num2);
    printf("Enter the third integer: \n");
    scanf("%d", &num3);
    printf("Enter the fourth integer: \n");
    scanf("%d", &num4);
    printf("Enter the fifth integer: \n");
    scanf("%d", &num5);

    sum = num1 + num2 + num3 + num4 + num5;

    //type casting to float to avoid data type conflict
    return average = (float)sum/5;


}


int main() {
    float thisAverage = 0.0;

    thisAverage = sum();

    printf("Average: %.2f\n", thisAverage);

    return 0;
}
