#include <stdio.h>
#include <stdbool.h>


bool isLeapYear(int year);

int main() {
    int year;

    printf("Enter a year: ");
    scanf("%d", &year);

    if (isLeapYear(year)) {
        printf("%d is a leap year.\n", year);
    } else {
        printf("%d is not a leap year.\n", year);
    }

    return 0;
}


bool isLeapYear(int year) {
    // Leap year conditions:
    // 1. Divisible by 4
    // 2. Not divisible by 100 unless divisible by 400
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return true;
    } else {
        return false;
    }
}
