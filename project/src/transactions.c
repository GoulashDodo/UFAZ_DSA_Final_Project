#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/transactions.h"

T_Transaction *addTransaction(const int studentId, const float coinAmount, const char* transactionDescription, T_Transaction* listTransaction) {

    T_Transaction *newTransaction = malloc(sizeof(T_Transaction));\

    if (newTransaction == NULL) {
        fprintf(stderr, "ERROR: Memory allocation failed.\n");
        return listTransaction;
    }

    newTransaction->studentId = studentId;
    newTransaction->coinAmount = coinAmount;

    strncpy(newTransaction->description, transactionDescription, sizeof(newTransaction->description) - 1);
    newTransaction->description[sizeof(newTransaction->description) - 1] = '\0';

    // Insert at the top of the list
    newTransaction->next = listTransaction;

    return newTransaction;

}

void printTransaction(T_Transaction *t, int blockId)
{
    if (t == NULL) {
        printf("NULL transaction.\n");
        return;
    }

    printf("[Block %d] Student %d | Amount: %.2f | Description: %s\n",
           blockId,
           t->studentId,
           t->coinAmount,
           t->description);
}


void freeTransactions(T_Transaction *head)
{
    T_Transaction *cur = head;
    while (cur != NULL) {
        T_Transaction *next = cur->next;  // сохраняем указатель на следующий
        free(cur);                        // освобождаем текущий
        cur = next;                       // двигаемся дальше
    }
}
