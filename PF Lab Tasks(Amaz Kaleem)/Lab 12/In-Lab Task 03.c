#include <stdio.h>
#include <string.h>

struct Footballer {
    char name[50];
    int age;
    int matches;
    float avg_goals;
};

int main() {
    struct Footballer players[20];
    int i, maxMatchesIndex = 0, youngestIndex = 0, lowestGoalsIndex = 0;

   
    for (i = 0; i < 2; i++) {
        printf("Enter name of player %d: ", i + 1);
        scanf(" %[^\n]", players[i].name);  
        printf("Enter age: ");
        scanf("%d", &players[i].age);
        printf("Enter number of matches played: ");
        scanf("%d", &players[i].matches);
        printf("Enter average goals per match: ");
        scanf("%f", &players[i].avg_goals);
    }

    
    for (i = 1; i < 2; i++) {
        if (players[i].matches > players[maxMatchesIndex].matches) {
            maxMatchesIndex = i;
        }
        if (players[i].age < players[youngestIndex].age) {
            youngestIndex = i;
        }
        if (players[i].avg_goals < players[lowestGoalsIndex].avg_goals) {
            lowestGoalsIndex = i;
        }
    }

    
    printf("\nPlayer who played the most matches: %s (%d matches)\n", players[maxMatchesIndex].name, players[maxMatchesIndex].matches);
    printf("Youngest player: %s (Age %d)\n", players[youngestIndex].name, players[youngestIndex].age);
    printf("Player with the lowest average goals per match: %s (%.2f goals per match)\n", players[lowestGoalsIndex].name, players[lowestGoalsIndex].avg_goals);

    return 0;
}

