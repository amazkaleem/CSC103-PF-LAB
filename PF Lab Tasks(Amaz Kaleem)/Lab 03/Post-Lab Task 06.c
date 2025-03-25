#include <stdio.h>

int main() {

    float bSalary, dAllowance, hRent, gSalary;

    printf("Enter the basic salary of Mr. X: $");
    scanf("%f", &bSalary);

    dAllowance = 0.40 * bSalary;
    hRent = 0.20 * bSalary;
    gSalary = bSalary + dAllowance + hRent;

    printf("Dearness Allowance Amount: $%.2f\n", dAllowance);
    printf("House Rent Allowance Amount: $%.2f\n", hRent);
    printf("Total Gross Salary: $%.2f\n", gSalary);
    
    return 0;
}