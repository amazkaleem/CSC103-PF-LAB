#include <stdio.h>
#include <stdlib.h>

int main()
{

    int x,y,result = 1;
    printf("Enter the values of x & y separated by space in between: ");
    scanf("%d %d", &x, &y);

    for(int i = 1; i < y+1; i++)
    {
        result *= x;
    }

    printf("%d raised to the power %d = %d\n",x,y,result);
    return 0;
}