#include <stdio.h> 
#include <stdlib.h> 

int main() 
{ 
    int msticks = 21, upick, cpick; 

    //do-while 
    do 
    { 
        printf("matchsticks remaining: %d\n", msticks); 
        printf("pick 1, 2, 3, or 4 matchsticks: "); 
        scanf("%d", &upick); 
        msticks -= upick; 
        if (msticks == 1) 
        { 
            printf("only one matchstick left. you lose!\n"); 
            break; 
        } 
        cpick = 5 - upick; 
        msticks -= cpick; 
        printf("computer picks %d matchsticks.\n", cpick); 
 
        if (msticks == 1) 
        { 
            printf("only one matchstick left. Computer wins!\n"); 
            break; 
        } 
    } while (msticks > 1);

    printf("But the computer said, 'Let's play the Game again!'\n");

    msticks = 21; 
    upick = 0; 
    cpick = 0;

    //while loop
    while (msticks > 1) 
    { 
        printf("matchsticks remaining: %d\n", msticks); 
        printf("pick 1, 2, 3, or 4 matchsticks: "); 
        scanf("%d", &upick); 
        msticks -= upick; 
        if (msticks == 1) 
        { 
            printf("only one matchstick left. you lose!\n"); 
            break; 
        } 
        cpick = 5 - upick; 
        msticks -= cpick; 
        printf("computer picks %d matchsticks.\n", cpick); 
 
        if (msticks == 1) 
        { 
            printf("only one matchstick left. Computer wins!\n"); 
            break; 
        } 
    } 
    return 0; 
}
