#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Admin.h"

// Global account list head
extern Account *head;

// Function to display all accounts (Sorted)
void displayAllAccounts() {
    if (!head) {
        printf("No accounts found.\n=================================================================================================\n");
        return;
    }

    // Sort accounts using Bubble Sort
    Account *ptr1, *ptr2;
    int tempID;
    char tempName[20], tempType[10];
    double tempBalance;

    for (ptr1 = head; ptr1 != NULL; ptr1 = ptr1->next) {
        for (ptr2 = ptr1->next; ptr2 != NULL; ptr2 = ptr2->next) {
            if (ptr1->id > ptr2->id) {  // Sort by ID
                tempID = ptr1->id;
                strcpy(tempName, ptr1->name);
                strcpy(tempType, ptr1->type);
                tempBalance = ptr1->balance;

                ptr1->id = ptr2->id;
                strcpy(ptr1->name, ptr2->name);
                strcpy(ptr1->type, ptr2->type);
                ptr1->balance = ptr2->balance;

                ptr2->id = tempID;
                strcpy(ptr2->name, tempName);
                strcpy(ptr2->type, tempType);
                ptr2->balance = tempBalance;
            }
        }
    }

    // Display sorted accounts
    Account *current = head;
    while (current) {
        printf("ID: %d | Name: %s | Balance: %.2f | Type: %s\n", 
               current->id, current->name, current->balance, current->type);
        current = current->next;
    }
    printf("===============================\n");
}

// Find account with highest balance
void findHighestBalance() {
    if (!head) {
        printf("No accounts found.\n===============================\n");
        return;
    }

    Account *current = head, *highest = head;
    while (current) {
        if (current->balance > highest->balance) {
            highest = current;
        }
        current = current->next;
    }

    printf("Highest Balance Account -> ID: %d | Name: %s | Balance: %.2f\n",
           highest->id, highest->name, highest->balance);
    printf("===============================\n");
}

// Admin Menu
void adminMenu() {
    int choice;
    char password[10];

    printf("Enter Admin Password: ");
    scanf("%s", password);

    if (strcmp(password, "admin1799") != 0) {
        printf("Incorrect Password! Returning to main menu.\n");
        return;
    }

    while (1) {
        printf("\nAdmin Menu:\n");
        printf("1. Display All Accounts (Sorted)\n");
        printf("2. Create Account\n");
        printf("3. Delete Account\n");
        printf("4. Update Account\n");
        printf("5. Search Account by ID\n");
        printf("6. Deposit Money\n");
        printf("7. Withdraw Money\n");
        printf("8. Find Highest Balance\n");
        printf("9. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: displayAllAccounts(); break;
            case 2: createAccount(); break;
            case 3: deleteAccount(); break;
            case 4: updateAccount(); break;
            case 5: searchAccountByID(); break;
            case 6: depositMoney(); break;
            case 7: withdrawMoney(); break;
            case 8: findHighestBalance(); break;
            case 9: return;
            default: printf("Invalid choice!\n===============================\n");
        }
    }
}
