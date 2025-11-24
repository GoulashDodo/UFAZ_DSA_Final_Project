#include "../include/interface_utils.h"
#include <stdio.h>
#include <string.h>


void printMenu(void) {
    printf("\nEATCoin Menu\n");
    printf("%d. Exit program\n", MENU_EXIT);
    printf("%d. Display the list of blocks in the BlockChain\n", MENU_DISPLAY_BLOCKS);
    printf("%d. Display all transactions in a block\n", MENU_DISPLAY_BLOCK_TRANSACTIONS);
    printf("%d. Display all transactions for a student on a given day\n", MENU_DISPLAY_STUD_TRANS_DAY);
    printf("%d. Display the history for a student\n", MENU_DISPLAY_HISTORY);
    printf("%d. Credit an account\n", MENU_CREDIT);
    printf("%d. Pay for a meal\n", MENU_PAY_MEAL);
    printf("%d. Transfer EATCoins between two students\n", MENU_TRANSFER);
    printf("%d. Export all transactions to text file\n", MENU_EXPORT_TX);
    printf("%d. Import transactions from text file\n", MENU_IMPORT_TX);
    printf("--------------------\n");
    printf("Enter your choice: ");
}




void readLine(char *buffer, int size) {
    if (fgets(buffer, size, stdin) != NULL) {
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n')
            buffer[len - 1] = '\0';
    }
}