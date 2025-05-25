#include <stdio.h>

struct Employee {
    int code;
    char name[50];
    int joining_day;
    int joining_month;
    int joining_year;
};

int main() {
    int n, i, j, current_day, current_month, current_year;
    
    printf("Enter number of employees: ");
    scanf("%d", &n);

    struct Employee employees[n];

    
    for (i = 0; i < n; i++) {
        printf("\nEnter details for employee %d\n", i + 1);
        printf("Employee code: ");
        scanf("%d", &employees[i].code);
        printf("Name: ");
        scanf(" %[^\n]", employees[i].name);  
        printf("Joining date (dd mm yyyy): ");
        scanf("%d %d %d", &employees[i].joining_day, &employees[i].joining_month, &employees[i].joining_year);
    }

    
    printf("\nEnter current date (dd mm yyyy): ");
    scanf("%d %d %d", &current_day, &current_month, &current_year);

    printf("\nEmployees with tenure of 3 or more years:\n");
    for (j = 0; j < n; j++) {
        int tenure = current_year - employees[j].joining_year;

        
        if (current_month < employees[j].joining_month || 
           (current_month == employees[j].joining_month && current_day < employees[j].joining_day)) {
            tenure--;  
        }

        if (tenure >= 3) {
            printf("%s\n", employees[j].name);
        }
    }

    return 0;
}

