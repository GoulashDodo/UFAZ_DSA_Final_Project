#ifndef DSA_FINAL_PROJECT_BLOCKCHAIN_H
#define DSA_FINAL_PROJECT_BLOCKCHAIN_H

#include "transactions.h"

typedef struct Date {
    int year;
    int month;
    int day;
} T_Date;

typedef struct Block {
    int id;
    T_Date date;
    T_Transaction *headTransaction;
    struct Block *next;
} T_Block;

typedef T_Block* Blockchain;


Blockchain addBlock(Blockchain);

void freeBlockchain(Blockchain bc);

//Functions for printing blocks
void displayBlocks(Blockchain bc);
void displayTransactionsInBlock(Blockchain bc, int blockId);
void displayStudentTransactionsOnDay(int idStud, T_Date date, Blockchain bc);


#endif // DSA_FINAL_PROJECT_BLOCKCHAIN_H
