//
// Created by Checco on 6/9/2017.
//
#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

void clearBuffer();
lkTable* createAliasTable();
void addAlias(lkTable* tbl, int node, char* alias);
void editAlias(lkTable* tbl, int node, char* alias);
void deleteAlias(lkTable* tbl, int node);

void clearBuffer(){ //clear the stdin when user write an invalid input data
    char c;
    while ((c = getchar()) != '\n' && c != EOF) { };
}

lkTable* createAliasTable(){
    lkTable* tbl =  (lkTable *)malloc(sizeof(lkTable*));
    return tbl;
}

void addAlias(lkTable* tbl, int node, char* alias){
    if(node<tbl->size){
        tbl->table[node].state=1;
        tbl->table[node].alias=alias;
    }else{
        aliasRow* newAlias = (aliasRow *)malloc(sizeof(aliasRow*));
        newAlias->alias = alias;
        newAlias->state = 1;
        aliasRow* tmp = (aliasRow *)malloc(tbl->size*sizeof(aliasRow*));
        memcpy(tmp,tbl->table,);
        printf("new\n");
    }
}