#include <stdio.h>
#include "Admin.h"
#include "User.h"

int main() {
    int choice;
    while (1) {
        printf("\n1. Admin Login\n2. User Menu\n3. Exit\nEnter choice: ");
        scanf("%d", &choice);
        if (choice == 1) adminMenu();
        else if (choice == 2) userMenu();
        else if (choice == 3) break;
        else printf("Invalid choice!\n===============================\n");
    }
    return 0;
}
