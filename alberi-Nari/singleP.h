#ifndef SINGLEP_H
#define SINGLEP_H

typedef struct tree{
	int info;
	struct tree* son;
	struct tree* bro;
} tree;

tree* newRandomTree();
int max(tree* t);
tree* delete(tree* t,int k);

#endif
