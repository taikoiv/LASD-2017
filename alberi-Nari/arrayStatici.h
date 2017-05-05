#ifndef ARRAYSTATICI_H
#define ARRAYSTATICI_H

#define dim 10

struct Tree{
	int info; 
	struct Tree *bros[dim];
	struct Tree *sons;
};

typedef struct Tree tree;

tree *newRandomTree();
void print(tree *head);





#endif	
