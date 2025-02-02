#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "User.h"

Account *head = NULL; // Linked list to store accounts

// Create a new account
void createAccount() {
    Account *newAccount = (Account *)malloc(sizeof(Account));
    if (!newAccount) {
        printf("Memory allocation failed!\n===============================\n");
        return;
    }

    printf("Enter ID: ");
    scanf("%d", &newAccount->id);
    printf("Enter Name: ");
    scanf("%s", newAccount->name);
    printf("Enter Initial Balance: ");
    scanf("%lf", &newAccount->balance);
    printf("Enter Type (Normal/VIP): ");
    scanf("%s", newAccount->type);

    newAccount->next = head;
    head = newAccount;

    printf("Account created successfully!\n===============================\n");
}

// Search for an account by ID
void searchAccountByID() {
    int id;
    printf("Enter Account ID: ");
    scanf("%d", &id);

    Account *current = head;
    while (current) {
        if (current->id == id) {
            printf("Account Found -> ID: %d | Name: %s | Balance: %.2f | Type: %s\n",
                   current->id, current->name, current->balance, current->type);
            printf("===============================\n");
            return;
        }
        current = current->next;
    }
    printf("Account not found!\n===============================\n");
}

// Deposit money
void depositMoney() {
    int id;
    double amount;
    printf("Enter Account ID: ");
    scanf("%d", &id);
    printf("Enter Amount to Deposit: ");
    scanf("%lf", &amount);

    Account *current = head;
    while (current) {
        if (current->id == id) {
            current->balance += amount;
            printf("Deposit Successful! New Balance: %.2f\n===============================\n", current->balance);
            return;
        }
        current = current->next;
    }
    printf("Account not found!\n===============================\n");
}

// Delete an account
void deleteAccount() {
    int id;
    printf("Enter Account ID to delete: ");
    scanf("%d", &id);

    Account *current = head, *prev = NULL;
    while (current) {
        if (current->id == id) {
            if (prev) prev->next = current->next;
            else head = current->next;

            free(current);
            printf("Account deleted successfully!\n===============================\n");
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("Account not found!\n===============================\n");
}

// Update account details
void updateAccount() {
    int id;
    printf("Enter Account ID to update: ");
    scanf("%d", &id);

    Account *current = head;
    while (current) {
        if (current->id == id) {
            printf("Enter new name: ");
            scanf("%s", current->name);
            printf("Enter new type (Normal/VIP): ");
            scanf("%s", current->type);
            printf("Account updated successfully!\n===============================\n");
            return;
        }
        current = current->next;
    }
    printf("Account not found!\n===============================\n");
}

// Withdraw money
void withdrawMoney(int id, double amount) {
    Account *current = head;
    while (current) {
        if (current->id == id) {
            if (amount <= 0) {
                printf("Invalid amount. Please enter a positive value!\n===============================\n");
                return;
            }

            if (current->balance >= amount) {
                current->balance -= amount;
                printf("Withdrawal Successful! New Balance: %.2f\n===============================\n", current->balance);
            } else {
                printf("Insufficient balance! Available: %.2f\n===============================\n", current->balance);
            }
            return;
        }
        current = current->next;
    }
    printf("Account not found!\n===============================\n");
}

// User menu
void userMenu() {
    int choice;
    while (1) {
        printf("\nUser Menu:\n");
        printf("1. Create Account\n");
        printf("2. Delete Account\n");
        printf("3. Update Account\n");
        printf("4. Search Account by ID\n");
        printf("5. Deposit Money\n");
        printf("6. Withdraw Money\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        int id;
        double amount;

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                deleteAccount();
                break;
            case 3:
                updateAccount();
                break;
            case 4:
                searchAccountByID();
                break;
            case 5:
                depositMoney();
                break;
            case 6:
                printf("Enter Account ID: ");
                scanf("%d", &id);
                printf("Enter Amount to Withdraw: ");
                scanf("%lf", &amount);
                withdrawMoney(id, amount);
                break;
            case 7:
                return;
            default:
                printf("Invalid choice!\n===============================\n");
        }
    }
}
