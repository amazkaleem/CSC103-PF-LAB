#include <stdio.h> 
#include <stdlib.h> 

int main() { 
    int division;
    float maths, physics, chem, bio, cs, total, percentage; 
    
    // Prompt the user to enter marks for the 5 subjects
    printf("Please enter marks for all 5 subjects separated by space: ");
    scanf("%f %f %f %f %f", &maths, &physics, &chem, &bio, &cs); 
    
    // Calculate the total marks
    total = maths + physics + chem + bio + cs; 
    
    // Display the total marks
    printf("Total: %.2f\n", total); 
    
    // Calculate the percentage
    percentage = (total / 500) * 100; 
    
    if (percentage >= 60) { 
        division = 1; 
    } else if (percentage >= 50) 
    { 
        division = 2; 
    } else if (percentage >= 40) 
    { 
        division = 3; 
    } else 
    { 
        division = 0; 
    } 
    
    switch (division) 
    { 
        case 1: 
            printf("First Division with percentage of: %.2f",percentage); 
            break; 
        case 2: 
            printf("Second Division with percentage of: %.2f",percentage);
            break; 
        case 3: 
            printf("Third Division with percentage of: %.2f",percentage); 
            break; 
        default: 
            printf("Fail with percentage of: %.2f",percentage); 
            break; 
        
    } 
    return 0;
}
