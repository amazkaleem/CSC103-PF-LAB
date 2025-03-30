#include <stdio.h>
#include <stdlib.h>

int main() {

    int a,b,count,answer;
    count = 1; 
    printf("Please enter values of x and y separated by spaces: "); 
    scanf("%d %d",&a,&b);

    // while loop
    while (count < (b + 1)) {

        answer = a * count;
        printf("%d * %d = %d\n", a, count, answer);
        count ++;

     }


    //do-while loop
    count = 1;
    answer = 1;

    printf("Please enter values of x and y separated by spaces: "); 
    scanf("%d %d",&a,&b);

    do {
        answer = a * count;
        printf("%d * %d = %d\n", a, count, answer);
        count ++;

    } while (count < (b + 1));

    return 0;
}
