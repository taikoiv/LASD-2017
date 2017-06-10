#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    lkTable* tbl =  (lkTable *)malloc(sizeof(lkTable));
	tbl->size=0;
    return tbl;
}

void addAlias(lkTable* tbl, int node, char* alias){
    if(node<tbl->size){
        tbl->table[node].state=1;
        tbl->table[node].alias=alias;
    }else{
		aliasRow newAlias;
		newAlias.alias = alias;
		newAlias.state = 1;
		if(tbl->size != 0) {
			aliasRow* tmp = (aliasRow *)realloc(tbl->table,(node+1)*sizeof(aliasRow));
			tmp[node] = newAlias;
			tbl->table = tmp;
			tbl->size = node+1;
		}else{
			tbl->table = (aliasRow *)malloc((node+1)*sizeof(aliasRow));
			tbl->table[node] = newAlias;
			tbl->size = node+1;
		}
	}
}
void editAlias(lkTable* tbl, int node, char* alias){
	if(tbl->table[node].state==1){
		tbl->table[node].alias=alias;
	}
}
void printAliasesTable(lkTable* tbl){
	int i;
	printf("\n\t|Aliases Table|\n");
	printf("\t|-Id|--Alias--|\n");
	printf("\t|---|---------|\n");
	for(i=0;i<tbl->size;i++){
		if(tbl->table[i].state==1){
			printf("\t|");
			if(i<10) printf("--");
			else if(i<100) printf("-");
			printf("%d",i);
			printf("|");
			printf("%s",tbl->table[i].alias);
			printf("|\n");
		}
	}
}

void deleteAlias(lkTable* tbl, int node){
	if(tbl->table[node].state==1){
		tbl->table[node].state=0;
	}
}
