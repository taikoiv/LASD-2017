#ifndef ARRAYDINAMICI_H
#define ARRAYDINAMICI_H

struct Tree{
	int info; 
	struct Tree **bros;
	struct Tree *sons;
};

typedef struct Tree tree;

tree *newRandomTree();
void print(tree *head);





#endif	
