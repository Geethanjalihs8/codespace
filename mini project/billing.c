#include <stdio.h>
#include <stdlib.h>

// Define a structure to represent menu items
struct MenuItem
{
    char name[50];
    float price;
};

// Function to display the menu
void displayMenu(const struct MenuItem menu[], int itemCount)
{
    printf("Menu:\n");
    for (int i = 0; i < itemCount; i++)
    {
        printf("%d. %s - $%.2f\n", i + 1, menu[i].name, menu[i].price);
    }
    printf("\n");
}

// Function to calculate the total bill
float calculateBill(const int order[], const struct MenuItem menu[], int itemCount)
{
    float total = 0;
    for (int i = 0; i < itemCount; i++)
    {
        total += menu[order[i] - 1].price;
    }
    return total;
}

int main()
{
    const struct MenuItem menu[] = {
        {"Pizza", 10.00}, {"Burger", 8.00}, {"Pasta", 12.50},
        // Add more menu items here
    };

    const int menuItemCount = sizeof(menu) / sizeof(menu[0]);

    int order[50]; // Array to store the user's order
    int orderSize = 0;

    printf("Welcome to the Restaurant Billing System!\n");

    while (1)
    {
        printf("Options:\n");
        printf("1. Display Menu\n");
        printf("2. Add Item to Order\n");
        printf("3. Calculate Bill\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                displayMenu(menu, menuItemCount);
                break;
            case 2:
                displayMenu(menu, menuItemCount);
                printf("Enter the item number to add to the order: ");
                int itemNumber;
                scanf("%d", &itemNumber);
                if (itemNumber >= 1 && itemNumber <= menuItemCount)
                {
                    order[orderSize++] = itemNumber;
                    printf("Item added to the order.\n");
                }
                else
                {
                    printf("Invalid item number.\n");
                }
                break;
            case 3:
                printf("Total bill: $%.2f\n", calculateBill(order, menu, orderSize));
                break;
            case 4:
                printf("Thank you for using the Restaurant Billing System!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
