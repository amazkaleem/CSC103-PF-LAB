#include <stdio.h>
#include <stdbool.h>
#include <string.h>  

void generateString(char *thisArray, int thisYear) {
    int position = 0;  // Keep track of position in string
    
    // Thousands place (m = 1000)
    int thousands = thisYear / 1000;
    for (int i = 0; i < thousands; i++) {
        thisArray[position++] = 'm';
    }
    thisYear %= 1000;  // Get remaining value after thousands
    
    // Hundreds place (d = 500, c = 100)
    int hundreds = thisYear / 100;
    if (hundreds >= 5) {
        thisArray[position++] = 'd';  // Add 'd' for 500
        hundreds -= 5;
    }
    // Add 'c's for remaining hundreds
    for (int i = 0; i < hundreds; i++) {
        thisArray[position++] = 'c';
    }
    thisYear %= 100;  // Get remaining value after hundreds
    
    // Tens place (l = 50, x = 10)
    int tens = thisYear / 10;
    if (tens >= 5) {
        thisArray[position++] = 'l';  // Add 'l' for 50
        tens -= 5;
    }
    // Add 'x's for remaining tens
    for (int i = 0; i < tens; i++) {
        thisArray[position++] = 'x';
    }
    thisYear %= 10;  // Get remaining value after tens
    
    // Ones place (v = 5, i = 1)
    int ones = thisYear;
    if (ones >= 5) {
        thisArray[position++] = 'v';  // Add 'v' for 5
        ones -= 5;
    }
    // Add 'i's for remaining ones
    for (int i = 0; i < ones; i++) {
        thisArray[position++] = 'i';
    }
    
    // Null-terminate the string
    thisArray[position] = '\0';
}

int main() {
    int userYear;
    bool isValid = false;
    
    char finalString[20] = "";

    printf("Please enter the year you want the Roman Equivalent for: ");
    scanf("%d", &userYear);

    generateString(finalString, userYear);
    printf("Roman numeral: %s\n", finalString);
    return 0;
}
