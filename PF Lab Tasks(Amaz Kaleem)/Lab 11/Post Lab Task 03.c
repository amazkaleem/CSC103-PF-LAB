#include <stdio.h>

#define DIVISIONS 3
#define PRODUCTS 4

// Structure for each transaction
struct Transaction {
    int supplierID;
    int divisionID;
    int productID;
    int quantityReceived;
    float costPerItem;
};

// Global inventory table and cost table
int inventory[DIVISIONS][PRODUCTS] = {0};      // Stores quantity
float itemCost[DIVISIONS][PRODUCTS] = {0.0};   // Stores cost per item

// Function to update inventory
void updateInventory(struct Transaction t) {
    int d = t.divisionID - 1;
    int p = t.productID - 1;

    if (d >= 0 && d < DIVISIONS && p >= 0 && p < PRODUCTS) {
        inventory[d][p] += t.quantityReceived;
        itemCost[d][p] = t.costPerItem;
    } else {
        printf("Invalid division or product ID!\n");
    }
}

// Function to display inventory and total value
void displayInventory() {
    float totalValue = 0.0;
    int i; 
    int j;
    printf("\nInventory Table:\n");
    printf("Division  Product  Quantity  Cost per Item  Value\n");

    for (i = 0; i < DIVISIONS; i++) {
        for (j = 0; j < PRODUCTS; j++) {
            float value = inventory[i][j] * itemCost[i][j];
            printf("   %d         %d       %4d        %.2f        %.2f\n",
                   i + 1, j + 1, inventory[i][j], itemCost[i][j], value);
            totalValue += value;
        }
    }

    printf("\nTotal Inventory Value: %.2f\n", totalValue);
}

int main() {
    int n;
    int i;
    printf("Enter number of transactions: ");
    scanf("%d", &n);

    struct Transaction t;

    for (i = 0; i < n; i++) {
        printf("\nTransaction #%d\n", i + 1);
        printf("Enter Supplier ID (1-3): ");
        scanf("%d", &t.supplierID);

        printf("Enter Division ID (1-3): ");
        scanf("%d", &t.divisionID);

        printf("Enter Product ID (1-4): ");
        scanf("%d", &t.productID);

        printf("Enter Quantity Received: ");
        scanf("%d", &t.quantityReceived);

        printf("Enter Cost per Item: ");
        scanf("%f", &t.costPerItem);

        updateInventory(t);
    }

    displayInventory();

    return 0;
}

