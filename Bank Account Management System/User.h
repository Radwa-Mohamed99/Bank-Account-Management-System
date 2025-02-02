#ifndef USER_H
#define USER_H

// Struct for Account Node (Linked List)
typedef struct Account {
    int id;
    char name[20];
    double balance;
    char type[10]; // Normal or VIP
    struct Account *next;
} Account;

// Global variable for head of linked list
extern Account *head;

// User Menu Functions
void userMenu();
void createAccount();
void deleteAccount();
void updateAccount();
void searchAccountByID();
void depositMoney();
void withdrawMoney();

#endif
