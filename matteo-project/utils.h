#include <string.h>

#ifndef LASD_2017_UTILS_H
#define LASD_2017_UTILS_H

typedef struct aliasRow{
    char* alias;
    int state;
 } aliasRow;
 //StateEMPTY 0
 //StateFILLED 1

typedef struct lkTable{
    int size;
    int inserted;
    aliasRow* table;
 } lkTable;

void clearBuffer();

lkTable* createAliasTable();
void addAlias(lkTable* tbl, int node, char* alias);
void printAliasesTable(lkTable* tbl);
void editAlias(lkTable* tbl, int node, char* alias);
void deleteAlias(lkTable* tbl, int node);
int getIntFromInput(int *data);
int getFloatFromInput(float *f);

#endif //LASD_2017_UTILS_H
