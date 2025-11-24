#ifndef DSA_FINAL_PROJECT_INTERFACE_UTILS_H
#define DSA_FINAL_PROJECT_INTERFACE_UTILS_H
#include "blockchain.h"

void printMenu();
void readLine();

typedef enum {
    MENU_EXIT = 0,                         // 0. Exit program
    MENU_DISPLAY_BLOCKS = 1,              // 1. Display the list of blocks
    MENU_DISPLAY_BLOCK_TRANSACTIONS = 2,  // 2. Display all transactions in a block
    MENU_DISPLAY_STUD_TRANS_DAY = 3,      // 3. Display all transactions for a student on a given day
    MENU_DISPLAY_HISTORY = 4,             // 4. Display the history for a student
    MENU_CREDIT = 5,                      // 5. Credit an account
    MENU_PAY_MEAL = 6,                    // 6. Pay for a meal
    MENU_TRANSFER = 7,                    // 7. Transfer EATCoins
    MENU_EXPORT_TX = 8,                   // 8. Export all transactions to file
    MENU_IMPORT_TX = 9                    // 9. Import transactions from file
} MenuChoice;




#endif //DSA_FINAL_PROJECT_INTERFACE_UTILS_H