#ifndef DSA_FINAL_PROJECT_TRANSACTIONS_H
#define DSA_FINAL_PROJECT_TRANSACTIONS_H

typedef struct Transaction {
    int studentId;           // student ID
    float coinAmount;        // EATCoin amount (+ for credit, - for debit)
    char description[100];   // description of the transaction
    struct Transaction *next; // linked list pointer
} T_Transaction;

T_Transaction* addTransaction(int, float, const char*, T_Transaction*);


void printTransaction(T_Transaction *t, int blockId);
void freeTransactions(T_Transaction *head);

#endif
