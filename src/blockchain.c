#include <stdio.h>
#include <stdlib.h>
#include "../include/blockchain.h"

Blockchain addBlock(Blockchain bc) {

    Blockchain newBlock = malloc(sizeof(T_Block));

    if (newBlock == NULL) {
        printf("Memory allocation failed\n");
        return bc;
    }


    if (bc == NULL) {
        newBlock->id = 0;
    } else {
        newBlock->id = bc->id + 1;
    }

    newBlock->date.year  = 2025;
    newBlock->date.month = 1;
    newBlock->date.day   = 1;


    newBlock->headTransaction = NULL;


    newBlock->next = bc;


    return newBlock;
}

void freeBlockchain(Blockchain bc)
{
    T_Block *curBlock = bc;

    while (curBlock != NULL) {
        // Сначала освобождаем все транзакции в этом блоке
        freeTransactions(curBlock->headTransaction);

        // Затем освобождаем сам блок
        T_Block *nextBlock = curBlock->next;
        free(curBlock);
        curBlock = nextBlock;
    }
}


void displayBlocks(Blockchain bc) {
    if (bc == NULL) {
        printf("Blockchain is empty.\n");
        return;
    }


    printf("\n--------------------------\n");

    printf("Block list: \n");
    T_Block *cur = bc;
    while (cur != NULL) {
        printf("Block #%d | Date: %04d-%02d-%02d\n",
               cur->id,
               cur->date.year, cur->date.month, cur->date.day);
        cur = cur->next;
    }


    printf("\n--------------------------\n");

}

void displayTransactionsInBlock(Blockchain bc, int blockId) {
    T_Block *cur = bc;
    while (cur != NULL && cur->id != blockId) {
        cur = cur->next;
    }

    if (cur == NULL) {
        printf("Block with id %d not found.\n", blockId);
        return;
    }

    printf("\n--------------------------\n");


    printf("Transactions in block #%d \n", cur->id);
    T_Transaction *t = cur->headTransaction;
    if (t == NULL) {
        printf("No transactions in this block.\n");
    }
    while (t != NULL) {
        printTransaction(t, cur->id);
        t = t->next;
    }
    printf("\n--------------------------\n");
}

void displayStudentTransactionsOnDay(int idStud, T_Date date, Blockchain bc) {

    printf("\n--------------------------\n");


    printf("Transactions of student %d on %04d-%02d-%02d \n",
           idStud, date.year, date.month, date.day);

    int found = 0;
    T_Block *cur = bc;

    while (cur != NULL) {
        if (cur->date.year == date.year &&
            cur->date.month == date.month &&
            cur->date.day == date.day) {

            T_Transaction *t = cur->headTransaction;
            while (t != NULL) {
                if (t->studentId == idStud) {
                    printTransaction(t, cur->id);
                    found = 1;
                }
                t = t->next;
            }
            }
        cur = cur->next;
    }

    if (!found) {
        printf("No transactions found for this student on this date.\n");
    }

    printf("\n--------------------------\n");
}