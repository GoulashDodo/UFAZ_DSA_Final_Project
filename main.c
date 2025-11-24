#include <stdio.h>
#include <stdlib.h>

#include "include/input_output.h"
#include "include/interface_utils.h"
#include "include/transactions_utils.h"

int main(void) {

    Blockchain bc = NULL;

    bc = addBlock(bc);
    bc->date.year  = 2025;
    bc->date.month = 11;
    bc->date.day   = 24;

    MenuChoice userChoice;
    char userInput[256];

    while (true) {

        printMenu();

        if (fgets(userInput, sizeof(userInput), stdin) == NULL)
            break;

        userChoice = (MenuChoice)atoi(userInput);

        if (userChoice == MENU_EXIT) {
            printf("Exiting program.\n");
            break;
        }

        switch (userChoice) {
        case MENU_DISPLAY_BLOCKS: {
            // 1. Display the list of blocks in the BlockChain
            displayBlocks(bc);
            break;
        }

        case MENU_DISPLAY_BLOCK_TRANSACTIONS: {
            // 2. Display all transactions in a block
            printf("Enter block id: ");
            readLine(userInput, sizeof(userInput));
            int blockId = atoi(userInput);
            displayTransactionsInBlock(bc, blockId);
            break;
        }

        case MENU_DISPLAY_STUD_TRANS_DAY: {
            // 3. Display all transactions for a student on a given day
            int idStud;
            T_Date date;

            printf("Enter student id: ");
            readLine(userInput, sizeof(userInput));
            idStud = atoi(userInput);

            printf("Enter date (YYYY MM DD): ");
            if (fgets(userInput, sizeof(userInput), stdin) == NULL) break;

            if (sscanf(userInput, "%d %d %d", &date.year, &date.month, &date.day) != 3) {
                printf("Invalid date format.\n");
                break;
            }

            displayStudentTransactionsOnDay(idStud, date, bc);
            break;
        }

        case MENU_DISPLAY_HISTORY: {
            // 4. Display the history for a student
            int idStud;
            printf("Enter student id: ");
            readLine(userInput, sizeof(userInput));
            idStud = atoi(userInput);

            consult(idStud, bc);
            break;
        }

        case MENU_CREDIT: {
            // 5. Credit an account
            int idStud;
            float amount;
            char descr[128];

            printf("Enter student id: ");
            readLine(userInput, sizeof(userInput));
            idStud = atoi(userInput);

            printf("Enter amount to credit: ");
            readLine(userInput, sizeof(userInput));
            amount = (float)atof(userInput);

            printf("Enter description: ");
            readLine(descr, sizeof(descr));

            credit(idStud, amount, descr, bc);
            break;
        }

        case MENU_PAY_MEAL: {
            // 6. Pay for a meal
            int idStud;
            float amount;
            char descr[128];

            printf("Enter student id: ");
            readLine(userInput, sizeof(userInput));
            idStud = atoi(userInput);

            printf("Enter amount to pay: ");
            readLine(userInput, sizeof(userInput));
            amount = (float)atof(userInput);

            printf("Enter description: ");
            readLine(descr, sizeof(descr));

            if (pay(idStud, amount, descr, bc)) {
                printf("Payment successful.\n");
            }
            else {
                printf("Payment failed: insufficient balance.\n");
            }

            break;
        }

        case MENU_TRANSFER: {
            // 7. Transfer EATCoins between two students
            int idSource, idDestination;
            float amount;
            char descr[128];

            printf("Enter source student id: ");
            readLine(userInput, sizeof(userInput));
            idSource = atoi(userInput);

            printf("Enter destination student id: ");
            readLine(userInput, sizeof(userInput));
            idDestination = atoi(userInput);

            printf("Enter amount to transfer: ");
            readLine(userInput, sizeof(userInput));
            amount = (float)atof(userInput);

            printf("Enter description: ");
            readLine(descr, sizeof(descr));

            if (transfer(idSource, idDestination, amount, descr, bc)) {
                printf("Transfer successful.\n");
            } else {
                printf("Transfer failed (insufficient balance or error).\n");
            }
            break;
        }

        case MENU_EXPORT_TX: {
            char filename[256];

            printf("Enter filename to export to: ");
            readLine(filename, sizeof(filename));

            if (exportTransactionsToFile(bc, filename)) {
                printf("Export completed successfully.\n");
            } else {
                printf("Export failed.\n");
            }
            break;
        }

        case MENU_IMPORT_TX: {
            char filename[256];

            printf("Enter filename to import from: ");
            readLine(filename, sizeof(filename));

            if (importTransactionsFromFile(&bc, filename)) {
                printf("Import completed successfully.\n");
            } else {
                printf("Import failed.\n");
            }
            break;
        }


        default:
            printf("Invalid choice, try again.\n");
            break;
        }

    }


    freeBlockchain(bc);

    return 0;
}



