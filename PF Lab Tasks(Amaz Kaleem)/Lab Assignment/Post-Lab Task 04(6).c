#include <stdio.h>
#include <stdlib.h>


//Question: Write a program for a matchstick game being played between the computer and a user. Your program should ensure that the computer always wins. Rules for the game are as follows:
// − There are 21 matchsticks.
// − The computer asks the player to pick 1, 2, 3, or 4 matchsticks.
// − Whoever is forced to pick up the last matchstick loses the game
// − After the person picks, the computer does its picking.

int main() 
{ 
    int msticks, upick, cpick;

    // First game: do-while loop
    msticks = 21;
    printf("\n=== Game 1 (do-while loop) ===\n");
    do 
    { 
        printf("matchsticks remaining: %d\n", msticks); 
        printf("pick 1, 2, 3, or 4 matchsticks: "); 
        scanf("%d", &upick);
        
        // Validate input
        while (upick < 1 || upick > 4 || upick > msticks) {
            printf("Invalid input! Pick 1-4 matchsticks: ");
            scanf("%d", &upick);
        }
        
        msticks -= upick; 
        if (msticks == 1) 
        { 
            printf("only one matchstick left. you lose!\n"); 
            break; 
        } 
        else if (msticks == 0) {
            printf("You took the last matchstick. You lose!\n");
            break;
        }
        
        cpick = 5 - upick; 
        printf("computer picks %d matchsticks.\n", cpick); 
        msticks -= cpick; 
 
        if (msticks == 1) 
        { 
            printf("only one matchstick left. Computer wins!\n"); 
            break; 
        } 
    } while (msticks > 1);

    printf("\nBut the computer said, 'Let's play the Game again!'\n");

    // Second game: while loop
    msticks = 21; 
    printf("\n=== Game 2 (while loop) ===\n");
    while (msticks > 1) 
    { 
        printf("matchsticks remaining: %d\n", msticks); 
        printf("pick 1, 2, 3, or 4 matchsticks: "); 
        scanf("%d", &upick);
        
        // Validate input
        while (upick < 1 || upick > 4 || upick > msticks) {
            printf("Invalid input! Pick 1-4 matchsticks: ");
            scanf("%d", &upick);
        }
        
        msticks -= upick; 
        if (msticks == 1) 
        { 
            printf("only one matchstick left. you lose!\n"); 
            break; 
        }
        else if (msticks == 0) {
            printf("You took the last matchstick. You lose!\n");
            break;
        }
        
        cpick = 5 - upick; 
        printf("computer picks %d matchsticks.\n", cpick); 
        msticks -= cpick; 
 
        if (msticks == 1) 
        { 
            printf("only one matchstick left. Computer wins!\n"); 
            break; 
        } 
    }
    
    printf("\nThe computer challenges you to one final match!\n");
    
    // Third game: for loop
    msticks = 21;
    printf("\n=== Game 3 (for loop) ===\n");
    
    // Using for loop to run the game
    // Initialization: msticks = 21 (already done)
    // Condition: msticks > 1
    // No increment expression as msticks is modified within the loop body
    for (; msticks > 1;) 
    { 
        printf("matchsticks remaining: %d\n", msticks); 
        printf("pick 1, 2, 3, or 4 matchsticks: "); 
        scanf("%d", &upick);
        
        // Validate input
        while (upick < 1 || upick > 4 || upick > msticks) {
            printf("Invalid input! Pick 1-4 matchsticks: ");
            scanf("%d", &upick);
        }
        
        msticks -= upick; 
        if (msticks == 1) 
        { 
            printf("only one matchstick left. you lose!\n"); 
            break; 
        }
        else if (msticks == 0) {
            printf("You took the last matchstick. You lose!\n");
            break;
        }
        
        cpick = 5 - upick; 
        printf("computer picks %d matchsticks.\n", cpick); 
        msticks -= cpick; 
 
        if (msticks == 1) 
        { 
            printf("only one matchstick left. Computer wins!\n"); 
            break; 
        }
    }
    
    return 0; 
}