#include <stdio.h> 
#include <stdlib.h> 

int main() { 
    char petType, isNurtered; 
    int insuranceCost; 
    printf("Enter the pet type (d for Dog, c for Cat, b for Bird, r for Reptile): "); 
    scanf(" %c", &petType); 
    if (petType == 'd') 
    { 
        printf("Has the dog been nurtered? (Y/N): "); 
        scanf(" %c", &isNurtered); 
        if (isNurtered == 'Y' || isNurtered == 'y') 
        { 
            insuranceCost = 40; 
            
        } else if (isNurtered == 'N' || isNurtered == 'n') 
        { 
            insuranceCost = 50; 
        } else 
        { 
            printf("Invalid input. Please enter Y or N."); return 1; 
        } 
        printf("The insurance cost is: $%d\n", insuranceCost); 
        
    } else if (petType == 'c') 
    { 
        printf("Has the cat been nurtered? (Y/N): "); 
        scanf(" %c", &isNurtered); if (isNurtered == 'Y' || isNurtered == 'y') 
        { 
            insuranceCost = 450; 
        } else if (isNurtered == 'N' || isNurtered == 'n') 
        { 
            insuranceCost = 65; 
        } else 
        { 
            printf("Invalid input. Please enter Y or N.");
            return 1; 
        } 
        printf("The insurance cost is: $%d\n", insuranceCost); 
        
    } else if (petType == 'b' || petType == 'r') 
    { 
        printf("No insurance fee applies for birds or reptiles."); 
        
    } else 
    { 
        printf("Invalid pet type entered."); 
    } 
    return 0; 
}
