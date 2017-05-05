#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "arrayStatici.h"

int isEmpty(tree *head){
	return head==NULL;
}

tree *createTree(int nodes){
	tree *head = NULL;
	
	printf("Nodes %d\n", nodes);
	if(nodes>0){
		int i=0, nson = 0;
		head = (tree *)malloc(sizeof(tree));
		head->bros = (tree**)malloc(sizeof(tree*));
		for(; i<rand()%dim; i++){
			head->bros[i]=(tree*)malloc(sizeof(tree));
			head->bros[i]->info = rand();
			nson = rand()%(nodes-nson);
			printf("nson %d\n", nson);
		}
	}
	return head;
}

tree *newRandomTree(){
	tree *head = NULL;
	int nodes = rand()%20;
	if(nodes>0){
		head = (tree *)malloc(sizeof(tree));
		head->info = rand();
		printf("%d\n", head->info);
		head->bros = NULL;
		head->sons = createTree(nodes-1);
	}
	return head;
}

void print(tree *head){
	int n = 0, i=0;
	if(!isEmpty(head)){
		n = sizeof(*head->bros)/sizeof(tree);
		for(; i<n; i++)
			printf("%d   ", head->bros[i]->info);
		printf("\n");
		print(head->sons);	
	}
}
