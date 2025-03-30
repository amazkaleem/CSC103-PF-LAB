#include <stdio.h>
#include <stdlib.h>

int main()
{
    char ch = 'x';
    int count = 0;
    
    printf("Enter characters and stop with a space: \n");
    
    scanf("%c", &ch);

    while (ch != ' ')
    {
        count++; //These also include new line characters
        scanf("%c", &ch);
    }

    printf("nonblank characters: %d\n", count);

    //do-while loop
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

    printf("nonblank characters: %d\n", count);
    return 0;
}
