#include <stdio.h>
#include <stdlib.h>

int main()
{
    int sub1, sub2, sub3, total_marks;
    double percentage;
    printf("Welcome to the A-Level School System again! You can opt for a minimum of three core subjects here..\n");
    printf("Enter marks of subjects separated by space in between: ");
    scanf("%d %d %d", &sub1, &sub2, &sub3);
    total_marks = sub1 + sub2 + sub3;
    printf("Your Total Marks are.. %d\n", total_marks);
    percentage = (double) total_marks / 300.0 * 100.0;
    printf("This makes up %.2lf percentage\n", percentage);

    return 0;
}