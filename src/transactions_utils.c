#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/transactions_utils.h"



float totalTransactionStudentBlock(int idStud, T_Block b) {
    float sum = 0.0f;

    T_Transaction *t = b.headTransaction;

    while (t != NULL) {

        if (t->studentId == idStud) {
            sum += t->coinAmount;
        }

        t = t->next;
    }

    return sum;
}

float soldeStudent(int idStud, Blockchain bc) {

    float total = 0.0f;
    T_Block *current = bc;

    while (current != NULL) {
        total += totalTransactionStudentBlock(idStud, *current);
        current = current->next;
    }

    return total;

}



bool credit(const int idStud, const float amount, const char *descr, Blockchain bc)
{
    if (bc == NULL) {
        printf("ERROR: Blockchain is empty, cannot add transaction.\n");
        return false;
    }

    if (amount <= 0.0) {
        printf("ERROR: Transaction amount must be greater than 0.\n");
        return false;
    }


    bc->headTransaction = addTransaction(
        idStud,
        amount,
        descr,
        bc->headTransaction
    );

    printf("Student %d credited with %.2f EATCoin.\n", idStud, amount);

    return true;
}


bool pay(const int idStud, const float amount, char *descr, Blockchain bc)
{
    if (bc == NULL) {
        printf("ERROR: Blockchain is empty, cannot add transaction.\n");
        return false;
    }

    if (amount <= 0.0) {
        printf("ERROR: Transaction amount must be greater than 0.\n");
        return false;
    }


    // 1. Find student's current total balance
    float balance = soldeStudent(idStud, bc);

    // 2. Check if balance is sufficient
    if (balance < amount) {
        // insufficient balance
        return false;
    }

    // 3. Add spending transaction (negative amount)
    bc->headTransaction = addTransaction(
        idStud,
        -amount,
        descr,
        bc->headTransaction
    );

    return true;   // successful payment
}



void consult(int idStud, Blockchain bc)
{
    if (bc == NULL) {
        printf("Blockchain is empty.\n");
        return;
    }

    printf("\n--------------------------\n");


    // 1. Display current balance
    float balance = soldeStudent(idStud, bc);
    printf("Student %d balance history \n", idStud);
    printf("Current balance: %.2f EATCoin\n\n", balance);

    printf("Last 5 transactions:\n");

    int displayedTransactionCount = 0;

    // 2. Traverse the blockchain block by block
    T_Block *currentBlock = bc;

    while (currentBlock != NULL && displayedTransactionCount < 5) {
        T_Transaction *t = currentBlock->headTransaction;

        // Traverse transactions in this block
        while (t != NULL && displayedTransactionCount < 5) {
            if (t->studentId == idStud) {

                printTransaction(t, currentBlock->id);

                displayedTransactionCount++;
            }
            t = t->next;
        }

        currentBlock = currentBlock->next;
    }

    if (displayedTransactionCount == 0) {
        printf("No transactions found for this student.\n");
    }

    printf("\n--------------------------\n");
}



bool transfer(int idSource, int idDestination, float amount, char *descr, Blockchain bc)
{
    if (bc == NULL) {
        printf("ERROR: Blockchain empty.\n");
        return false;
    }

    // 1. Check balance of the source student
    float balance = soldeStudent(idSource, bc);

    if (balance < amount) {
        // Not enough funds
        return false;
    }

    // 2. Record negative transaction for the sender
    bc->headTransaction = addTransaction(
        idSource,
        -amount,       // sender loses EATCoin
        descr,
        bc->headTransaction
    );

    // 3. Record positive transaction for the receiver
    bc->headTransaction = addTransaction(
        idDestination,
        amount,        // receiver gains EATCoin
        descr,
        bc->headTransaction
    );

    return true;   // successfully transferred
}
