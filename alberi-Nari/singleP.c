#include <stdlib.h>
#include <limits.h>
#include <stdio.h> //RICRODA
#include "singleP.h"


tree* newTree(int &nodes);

tree* newRandomTree(){
	int nodes=rand()%1000+99;
	tree* t= (tree*) malloc(sizeof(tree));
	t->info=rand();
	t->son=newTree(&nodes);
	t->bro=newTree(&nodes);
	return t;
}

tree* newTree(int* nodes){
	tree* t=NULL;

	if(*nodes>0){
		nodes--;
		t->info=rand();
		t->son=newTree(&nodes-1);
		t->bro=newTree(&nodes-1);
	}
	return t;
}

int max(tree* t){
	if(t!=NULL){
		int me=t->info;
		int son=max(t->son);
		int bro=max(t->bro);
		
		if(me>son){
			if(me>bro) return bro;
			return me;
		} else if(son>bro)
				return son;
		return bro;
	}
	return INT_MIN;
}
