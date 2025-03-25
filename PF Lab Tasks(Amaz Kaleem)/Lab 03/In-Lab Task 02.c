#include <stdio.h>
#include <stdlib.h>

int main()
{
    int sub1, sub2, sub3, total_marks;
    printf("Welcome to the A-Level School System. You can opt for a minimum of three core subjects here..\n");
    printf("Enter marks of subjects separated by space in between: ");
    scanf("%d %d %d", &sub1, &sub2, &sub3);
    total_marks = sub1 + sub2 + sub3;
    printf("Your Total Marks are.. %d\n",total_marks);
    return 0;
}