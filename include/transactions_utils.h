#ifndef TRANSACTION_UTILS_H
#define TRANSACTION_UTILS_H

#include <stdbool.h>

#include "blockchain.h"
#include "transactions.h"

float totalTransactionStudentBlock(int idStud, T_Block b);
float soldeStudent(int idStud, Blockchain bc);


//Changed void to bool type, so we can detect whether transaction occurred or not
//If true, then yes
//If false, then no
bool credit(int idStud, float amount, const char *descr, Blockchain bc);
bool pay(int idStud, float amount, char *descr, Blockchain bc);
bool transfer(int idSource, int idDestination, float amount, char *descr, Blockchain bc);

void consult(int idStud, Blockchain bc);

#endif
