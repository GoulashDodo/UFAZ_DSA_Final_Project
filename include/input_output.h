#ifndef DSA_FINAL_PROJECT_INPUT_OUTPUT_H
#define DSA_FINAL_PROJECT_INPUT_OUTPUT_H
#include <stdbool.h>

#include "blockchain.h"


bool exportTransactionsToFile(Blockchain bc, const char *filename);
bool importTransactionsFromFile(Blockchain *bc, const char *filename);


#endif //DSA_FINAL_PROJECT_INPUT_OUTPUT_H