# Bank Account Management System

## Overview

The **Bank Account Management System** is a C program designed to efficiently manage bank accounts. It allows users to perform various banking operations, including creating accounts, searching, updating details, processing transactions, and deleting accounts. Additionally, an **admin interface** has been implemented, which requires authentication to access administrative functions.

## Files 📁

1. **`main.c`**:
   - Contains the `main()` function, which serves as the entry point of the program.
   - Manages the main menu and handles user/admin interactions.
   - Invokes functions for account creation, searching, updates, and transactions.

2. **`user.c`**:
   - Implements the user interface logic.
   - Manages user-specific actions such as account creation, searching, updating details, and performing transactions (deposit/withdrawal).

3. **`admin.c`**:
   - Implements the admin interface logic.
   - Handles the admin login and provides functionalities for managing all user accounts.
   - Includes options to display all accounts sorted and find the account with the highest balance.

4. **`user.h`**:
   - Header file for user-related functions.
   - Contains function prototypes for user operations, such as creating accounts, searching, and managing transactions.

5. **`admin.h`**:
   - Header file for admin-related functions.
   - Contains function prototypes for the admin login, account management, and displaying information about accounts.

## Features 🌟

- **User Operations:**
  - Create a new account
  - Search for an account by ID
  - Update account details
  - Deposit money
  - Withdraw money (ensuring no overdraft occurs)
  - Delete an account
  - Exit the program

- **Admin Panel:**
  - Secure login using an admin password
  - Access to all user operations
  - Enhanced control over account management
  - Display all accounts sorting
  - Find the account with the highest balance

## Technical Details 

- **Programming Language:** C
- **Data Structure Used:** Linked List
- **Key Concepts Implemented:**
  - Structures (`struct`)
  - Dynamic Memory Allocation (`malloc`, `free`)
  - Pointers
  - File Handling (if applicable for persistent storage)
  - Conditional Statements and Loops

## Data Structure

All account data is stored in a linked list. Each node contains:

- **Account ID** (int)
- **Account Holder Name** (char[20])
- **Balance** (double)
- **Account Type** (Normal / VIP)
- **Pointer to Next Node**

## Functions and Their Responsibilities

### User Functions

1. **`void createAccount()`** – Adds a new account to the system.
2. **`void searchAccountByID(int id)`** – Searches for an account using its unique ID.
3. **`void updateAccount(int id)`** – Updates account details.
4. **`void depositMoney(int id, float amount)`** – Deposits a specified amount into an account.
5. **`void withdrawMoney(int id, float amount)`** – Withdraws money while ensuring sufficient balance.
6. **`void deleteAccount(int id)`** – Deletes an account from the linked list.

### Admin Functions

1. **`void adminLogin()`** – Prompts for a password to grant admin access.
2. **`void adminMenu()`** – Grants access to all functionalities once authenticated.
3. **`void findHighestBalance()`** – Finds and displays the account with the highest balance.
4. **`void displayAllAccounts()`** – Displays all stored accounts.

## How to Run the Program

1. **Compile the C program** using a compiler like `gcc`:
   ```bash
   gcc Admin.c User.c main.c -o Bank_System.exe
   ```
2. **Run the executable**:
   ```bash
   Bank_System
   ```
3. **Follow on-screen instructions** to navigate through the menu.

## Bank Account Management System window

![Bank Account Management System window](https://github.com/Radwa-Mohamed99/Bank-Account-Management-System/blob/main/System%20window.png?raw=true)

## Admin window

![Admin window](https://github.com/Radwa-Mohamed99/Bank-Account-Management-System/blob/main/Admin%20window.png?raw=true)

## User Window

![User Window](https://github.com/Radwa-Mohamed99/Bank-Account-Management-System/blob/main/User%20window.png?raw=true)

## Bank Account Management System 🎥



https://github.com/user-attachments/assets/e7832318-838a-4ccc-ae2e-4b3b1a25923d


