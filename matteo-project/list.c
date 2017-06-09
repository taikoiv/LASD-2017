#include <stdlib.h>
#include <stdio.h>
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

void printList(list* l){
	if(l!=NULL){
		printf("%d",l->k);
		if(l->next!=NULL){
			printf(" -> ");
			printList(l->next);
		} else {
			printf("\n");
		}
	}
}

list* insertTail(list* l,int k){
	if(l!=NULL){
		if(l->k!=k)
			l->next=insertTail(l->next,k);
	} else {
		l=(list*) malloc(sizeof(list));
		l->k=k;
		l->next=NULL;
	}
	return l;
}
