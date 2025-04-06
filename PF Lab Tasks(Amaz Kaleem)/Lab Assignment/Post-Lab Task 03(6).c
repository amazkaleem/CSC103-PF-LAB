#include <stdio.h>
#include <stdlib.h>

int main()
{
    char ch = 'x';
    int count = 0;
    
    // Using while loop
    printf("Enter characters and stop with a space: \n");
    
    scanf("%c", &ch);
    while (ch != ' ')
    {
        count++; //These also include new line characters
        scanf("%c", &ch);
    }
    printf("nonblank characters (while loop): %d\n", count);
    
    // Clear the input buffer
    while (getchar() != '\n');
    
    // Using do-while loop
    count = 0;
    ch = 'x';
    printf("Enter characters and stop with a space: \n");
    do
    {
        scanf("%c", &ch);
        if (ch != ' ')
        {
            count++; //These also include new line characters
        }
    } while (ch != ' ');
    printf("nonblank characters (do-while loop): %d\n", count);
    
    // Clear the input buffer again
    while (getchar() != '\n');
    
    // Using for loop
    count = 0;
    ch = 'x';
    printf("Enter characters and stop with a space: \n");
    
    for (scanf("%c", &ch); ch != ' '; scanf("%c", &ch))
    {
        count++; //These also include new line characters
    }
    printf("nonblank characters (for loop): %d\n", count);
    
    return 0;
}