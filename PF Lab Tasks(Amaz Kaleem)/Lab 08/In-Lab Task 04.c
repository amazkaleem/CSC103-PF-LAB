#include <stdio.h>

void marksCalculator(float *average, float *percentage) {
    int sub1, sub2, sub3, total;
    
    printf("Enter your marks in Electronics: ");
    scanf("%d", &sub1);
    
    printf("Enter your marks in Linear Algebra: ");
    scanf("%d", &sub2);
    
    printf("Enter your marks in Programming Fundamentals: ");
    scanf("%d", &sub3);
    
    total = sub1 + sub2 + sub3;
    *average = (float)total / 3;   
    
    *percentage = ((float)total / (3 * 100)) * 100;
}

int main() {
    float avg, pct;
    
    printf("Welcome to your Report Card. I hope you are excited!\n\n");
    
    marksCalculator(&avg, &pct);
    
    printf("\nResults:\n");
    printf("Average marks: %.2f\n", avg);
    printf("Percentage: %.2f%%\n", pct);
    
    return 0;
}