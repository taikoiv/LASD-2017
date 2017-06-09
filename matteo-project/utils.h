//
// Created by Checco on 6/9/2017.
//

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
        aliasRow* table;
    } lkTable;

    void clearBuffer();

    lkTable* createAliasTable();
    void addAlias(lkTable* tbl, int node, char* alias);
    void editAlias(lkTable* tbl, int node, char* alias);
    void deleteAlias(lkTable* tbl, int node);

#endif //LASD_2017_UTILS_H
