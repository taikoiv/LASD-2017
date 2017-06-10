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

int getIntFromInput(int *data){
	int ok, // ritorno della funzione 
		i; // indice per scorrere la stringa letta
	char buffer[51];
	
	scanf("%50s",buffer);
	clearBuffer();
	
	i = 0;
	
	while( buffer[i]>47 && buffer[i]<57 ) i++;
	
	ok = (buffer[i]=='\0' && i>0 );
	
	if(ok) *data = atoi(buffer);
	
	return ok;
}

int getFloatFromInput(float *f){
	char buffer[51];
	int cont, //indice per lo scorrimento dell'input utente
		off, //lunghezza minima della stringa (in base alla presenza del punto e/o del segno negativo)
		ret;
	
	scanf("%50s",buffer);
	clearBuffer();
	
	cont = off = (buffer[0]=='-') ? 1 : 0;
	while(buffer[cont]>47 && buffer[cont]<57) cont++;
	if(buffer[cont]=='.'){
		cont++;
		off++;
		while(buffer[cont]>47 && buffer[cont]<57) cont++;		
	}
	
	ret = (buffer[cont]=='\0' && cont>off);
	
	if(ret)
		*f = atof(buffer);
		
	return ret;
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
        //memcpy(tmp,tbl->table,);
        printf("new\n");
    }
}
