#include <stdio.h> 
#include <stdlib.h> 

int main() { 
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
    
    // Check the percentage and print the division accordingly
    if (percentage >= 60) { 
        printf("First Division with percentage of: %.2f\n", percentage); 
    } else if (percentage >= 50) { 
        printf("Second Division with percentage of: %.2f\n", percentage); 
    } else if (percentage >= 40) { 
        printf("Third Division with percentage of: %.2f\n", percentage); 
    } else { 
        printf("Fail with percentage of: %.2f\n", percentage); 
    } 
    
    return 0; 
}
