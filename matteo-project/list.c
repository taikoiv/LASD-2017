#include <stdlib.h>
#include "list.h"

int LIST_ERROR=0;

list* insertTop(list* l,int k){
	list* e=malloc(sizeof(list));
	if(e!=NULL){
		e->k=k;
		e->next=l;
	} else {
		LIST_ERROR=-1;
		e=l;
	}
	return e;
}

void freeList(list* l){
	if(l!=NULL){
		freeList(l->next);
		free(l);
	}
}
