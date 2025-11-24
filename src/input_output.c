//
// Created by mikay on 24.11.2025.
//

#include "../include/input_output.h"

#include <stdio.h>


bool exportTransactionsToFile(Blockchain bc, const char *filename)
{
    FILE *f = fopen(filename, "w");
    if (!f) {
        printf("ERROR: Cannot open file %s for writing.\n", filename);
        return false;
    }

    T_Block *block = bc;

    while (block != NULL) {
        T_Transaction *t = block->headTransaction;

        while (t != NULL) {
            fprintf(
                f,
                "%02d/%02d/%04d; %d; %.2f; %s\n",
                block->date.day,
                block->date.month,
                block->date.year,
                t->studentId,
                t->coinAmount,
                t->description
            );

            t = t->next;
        }

        block = block->next;
    }

    fclose(f);
    return true;
}


bool importTransactionsFromFile(Blockchain *bc, const char *filename)
{
    FILE *f = fopen(filename, "r");
    if (!f) {
        printf("ERROR: Cannot open file %s for reading.\n", filename);
        return false;
    }

    char line[512];

    while (fgets(line, sizeof(line), f) != NULL) {
        int day, month, year;
        int studentId;
        float amount;
        char description[256];

        if (sscanf(line, "%d/%d/%d; %d; %f; %[^\n]",
                   &day, &month, &year,
                   &studentId, &amount, description) != 6)
        {
            printf("Skipping invalid line: %s\n", line);
            continue;
        }

        T_Block *block = *bc;

        while (block != NULL) {
            if (block->date.day == day &&
                block->date.month == month &&
                block->date.year == year)
            {
                break; // нашли!
            }
            block = block->next;
        }

        if (block == NULL) {

            *bc = addBlock(*bc);
            block = *bc;

            block->date.day = day;
            block->date.month = month;
            block->date.year = year;
        }

        block->headTransaction =
            addTransaction(studentId, amount, description, block->headTransaction);
    }

    fclose(f);
    return true;
}
